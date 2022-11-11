# Born2beroot Guía de evaluación

Esta es una guía para realizar paso a paso todos los comandos, pruebas y consideraciones necesarias para comprobar cada parte de la hoja de evaluación del proyecto.

# Índice

1. [Preliminaries](#preliminaries)
2. [General instructions](#general-instructions)
3. [Mandatory part](#mandatory-part)

	3.1. [Overview](#overview)

	3.2. [Setup](#setup)

	3.3. [User](#user)

	3.4. [Hostname and partitions](#hostname-and-partitions)

	3.5. [Sudo](#sudo)

	3.6. [UFW](#ufw)

	3.7. [SSH](#ssh)

	3.8. [Script](#script)

4. [Bonus](#bonus)

## Preliminaries

Simplemente hacer la evaluación de manera presencial y descargar el repositorio git de intra del evaluado para comprobar que contiende los archivos que especifica el subject. 

Una vez descargado el repo, comprueba que no contiene archivos ocultos `ls -la` y que solo tiene el archivo `signature.txt` con la firma de la máquina virtual.

## General instructions

Comparar la firma de signature.txt del repositorio con la del archivo `born2beroot.vdi` ubicado en el equipo local.

`shasum born2beroot.vdi` 

## Mandatory part

### Overview

➤ Máquina virtual; qué es, cómo funciona y por qué usarla.

Una máquina virtual es más un software capaz de cargar en su interior otro sistema operativo emulando que es un PC de verdad, es decir es un software que "crea" una máquina (PC, consola, móvil o lo que sea) que en vez de ser física es virtual o emulada.

Hay dos tipos de máquinas virtuales diferenciadas por su funcionalidad: las de sistema y las de proceso; la gran mayoría de las veces que oigas hablar de una máquina virtual casi seguro que se estarán refiriendo a las de sistema. Esta emula a un ordenador completo, es un software que puede hacerse pasar por otro dispositivo -como un PC- de tal modo que puedes ejecutar otro sistema operativo en su interior. Tiene su propio disco duro, memoria, tarjeta gráfica y demás componentes de hardware, aunque todos ellos son virtuales. 

Los componentes de la máquina virtual (memoria RAM, disco duro, procesador, etc) toman su capacidad del PC donde está instalada la máquina virtual, también llamado el host o el anfitrión. Otros dispositivos podrían realmente ser inexistentes físicamente, como por ejemplo un CD-ROM que en verdad es el contenido de una imagen ISO en vez de un lector de CD de verdad.

Los usos de las máquinas virtuales son muchos: probar otros sistemas operativos sin instalarlo realmente en el equipo real, para ejecutar programas antiguos que ya no corren en nuestro sistema actual, usar aplicaciones que solo están dispnibles para otros sistemas (MacOS/Win), probar como se comporta una aplicación o software en diferentes sistemas, como medida de seguridad extra (al estar aislada del sistema real del equipo, cualquier "imprevisto" no afectará al equipo real).

➤ CentOS y Debian, diferencias y por qué has elegido uno (Debian).

En mi caso he elegido Debian porque todas las guías y recursos que he encontrado para el proyecto usaban Debian (suena mal usar este argumento en la defensa, pero es la verdad y lo sabes). Además, en general Debian tiene mucha comunidad en internet para resolver dudas y encontrar guias/recursos, tiene una instalación más sencilla y es más sencillo encontrar, instalar y actualizar paquetes que usando CentOS.

Diferencias entre los dos: 

- CentOS está desarrollado por una empresa y Debían por usuarios. Esto significa que Debian cuenta con actualizaciones y mejores más frecuentes, pero al mismo, las actualizaciones de CentOS suelen ser más estables, más "fiables".

- Debian tiene compatibilidad con más arquitecturas que CentOS.

- La actualizaciones de sistema son más sencillas en Debian, en el caso de CentOS, normalmente, es mejor hacer una instalación completa de la versión nueva en lugar de actualizar, lo que puede ser muy tedioso.

- La interfaz gráfica de CentOS es más compleja que la de Debian, que es más orientada a la comodidad del usuario.

- CentOS usa YUM como gestor/instalador de paquetes, mientras que Debian usa apt-get.

- CentOS tiene menos paquete disponibles en general, comparado con Debian (que al estar mantenido por usuarios, cuenta con una cantidad enorme de paquetes que no dejan de actualizarse constantemente). 

➤ Apt vs Aptitude y APPArmor.

Ambos son gestores de paquetes para el sistemas GNU/Linux, permiten instalar, desinstalar, actualizar y en general administrar paquetes .deb en el sistema operativo. Son herramientas globables de alto nivel que usan como backend el gestor estándar dpkg y le agregan funcionalidades de gestión de repositorios externos para dependencias y actualizaciones. 

La principal diferencia entre los dos es que aptitude añade una especie de interfaz (en consola) más intuitiva y user-friendly que puede facilitar mucho el trabajo a los usuarios, mientras que en apt tenemo que realizar todas las acciones mediante lineas y combinaciones de comandos en consola. Además, aptitude tiene algunas funciones extra por defecto, comparado con apt, como instalar por defecto dependencias que están marcadas como "recommended". 

Por último, importante destacar que hay mucha más información y recursos sobre apt que sobre aptitude, ya que la comunidad sigue usando mucho más el primero.

- APPArmor es un módulo de seguridad del kernel Linux que permite al administrador del sistema restringir las capacidades de un programa. Viene instalada por defecto en muchos sistemas de Linux, como es el caso de Debian, aunque se ejecuta de forma silenciosa en segundo plano. Básicamente lo que hace es bloquear procesos vulnerables, ofrece seguridad de "control de acceso obligatorio" (MAC) y nos permite restringir las acciones que puede realizar cada proceso. AppArmor es particularmente útil para restringir el software que puede ser explotado, como un navegador web o software de servidor. Podemos comprobar el estado del servicio apparmor en cualquier momento usando el comando sudo `apparmor_status`.

➤ Comprueba que se está ejecutando el script cada 10 minutos.

Si ya ha aparecido una vez y el evaluador lo ha podido verificar, yo recomiendo desactivarlo ahora, aunque luego tengas que volver a activarlo, cambiar su frencuencia, etc. Así por lo menos no salta en mitad de ninguna de las pruebas que vamos a seguir realizando.

### Setup

➤ Comprueba que la máquina virtual NO cuenta con interfaz gráfica.

➤ La contraseña para acceder al usuario de la máquina cumple con las reglas del subject.

Como tendrás apuntados los usuarios y pass usados para el proyecto, puedes enseñarselas al evaluador. No tiene mucha importancia, luego vamos a ver la política de contraseñas y a hacer más pruebas sobre esto.

➤ Verifica que el servicio UFW está operativo.

`sudo ufw status` o `sudo systemctl status ufw`

➤ Verifica que el servicio SSH está operativo.

`sudo ssh status` o `sudo systemctl status ssh`

➤ Comprueba el sistema operativo del sistema.

`hostnamectl | grep Opertaing`

### User

➤ Comprueba que el usuario se encuentra en el grupo sudo y user42.

Estando logeado con el usuario que queremos comprobar, comando `groups` o para revisar los grupos de cualquier usuario `groups <user_name>`.

`getent group` para ver todos los grupos y sus usuarios, `getent group <group_name>` para ver un grupo en específico.

➤ Crea un nuevo usuario y asignale una contraseña, puedes probar a que esta contraseña sea débil intencionadamente para volver a comprobar que se cumple la política de contraseñas.

`sudo adduser <new_user>`, añadir contraseña y dejar en blanco todos los campos siguientes.	

➤ Edita los archivos de politica de contraseñas para comprobar que se han establecido las reglas impuestas por el subject.

`sudo nano /etc/login.defs`

```
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

`sudo nano /etc/pam.d/common-password`

```
password        requisite                       pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
```

➤ Crea un grupo nuevo 'evaluating' e incluye al usuario nuevo en él y comprueba que se haya incluido correctamente.

Nuevo grupo: `sudo groupadd evaluating`.

Añadir el usuario nuevo al grupo recien creado: `sudo adduser <new_user> evaluating`.

Comprobar que el usuario se ha añadido al grupo correctamente: `groups <new_user>`.

➤ Explica/argumenta las ventajas y desventajas de usar esta política de contraseñas.

La principal ventaja de una política de contraseñas fuerte es la protección que ofrece ante intentos de intrusión, al tener un mínimo de 10 caracteres y la obligación de incluir mayúsculas y símbolos hace que un ataque por fuerza bruta tardase muchos más que si quitasemos todos esos filtros y se tratase de una contraseña corta y únicamente númerica o alfabética, además el hecho de tener que cambiar de contraseña cada cierto tiempo asegura que incluso si una contraseña es robada, volverá a ser segura en un número de días. 

La desventaja es que generar claves complejas puede ocasionar que el propio usuario las olvide, o que acuda a aplicaciones y otros medios para autogenerarlas o guardarlas, lo que también podría ocasionar falta de seguridad si la fuente usada no es completamente fiable.

### Hostname and partitions

➤ Comprueba que el nombre del host cumple con el patrón del subject (<login42>42).

`hostnamectl`

➤ Cambia el hostname y reinicia la máquina para comprobar que sigue cambiado.

`sudo hostnamectl set-hostname <new_hostname>`

`sudo reboot`

➤ Mira la lista de particiones y comprueba que se corresponden con las del subject (ten en cuenta que dependiendo de si se ha realizado o no el bonus, habrá que mirar diferentes ejemplos del subject).

`lsblk`

➤ Explicación de LVM.

LVM es el gestor de volúmenes lógicos (Logical Volumes Manager). Un volumen lógico es lo que tradicionalmente llamamos una partición del disco duro.

LVM "trabaja" entre nuestros discos físicos y los sistemas de ficheros de las particiones (volúmenes lógicos) que hacemos en esos discós físicos. 

Lo que hace es asignar a cada volumen lógico un tamaño en uno o varios volúmenes físicos (discos) y esto lo hace de manera flexible, es decir, un mismo volumen lógico puede tener su espacio asignado repartido en varios discos o en espacios de memoria que no sean contiguos dentro del mismo disco.

La principal ventaja de esto, en comparación a las particiones de disco tradicionales, es que antes estabas limitado por el tamaño de cada disco, si en un mismo disco tenías cuatro particiones, no podrías ampliar una sin eliminar las siguientes, ya que la memoría estaba asignada de manera contigua, incluso para ampliar la última partición, tendrías como límite el tamaño total del disco.

Con LVM, si por ejemplo amplias la memoría del equipo añadiendo uno o más discos físicos, la capacidad nueva se repartiría por igual para cada volumen lógico anterior. O si quisieras eliminar, limitar o ampliar algun volumen lógico, podrías hacerlo sin necesidad de modifcar el resto ni perder datos o información importante del sistema.

### Sudo

➤ Comprobar que sudo está instalado (este paso tiene poco sentido, a estas alturas ya hemos usado bastantes comandos sudo).

`sudo apt -qq list sudo`

➤ Incluir al usuario nuevo dentro del grupo sudo (también lo hemos hecho antes...).

`sudo adduser <new_user> sudo`

➤ Explicación del uso de sudo, de las reglas que hemos establecido para este y editar los archivos de sudo para enseñar cómo hemos modificado estas reglas.

Sudo se usa para realizar acciones con permiso de administrador, como podríamos hacer desde el usuario root. Podemos modificar las reglas de sudo para hacerlo más fléxible o más estricto, para limitar su uso a X usuarios, etc.

Para mostrar el estado de nuestras reglas, abrimos con nano el archivo de configuaración de sudo `sudo nano etc/sudoers.d/sudo_config` y para mostrar las reglas para la contraseña de sudo, hacemos lo mismo con el archivo password `sudo nano etc/pam.d/common-password` (este ya lo hemos revisado antes).

En el archivo `...sudoers.d/sudo_config`, veremos lo siguiente:

```
Defaults        passwd_tries=3
Defaults        badpass_message="Wrong password"
Defaults        logfile="/var/log/sudo/sudo_config"
Defaults        log_input, log_output
Defaults        iolog_dir="/var/log/duo"
Defaults        requiretty
Defaults        secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

➤ Log de sudo. Mostrar que la carpeta /var/log/sudo existe y que contiene al menos un archivo (el log) y que este se actualiza cuando usamos comandos sudo.

El log tiene que existir y guardar cada comando de sudo nuevo que ejecutemos, para comprobar ambas cosas, mostramos primero la carpeta `/var/log/sudo`, en esta tiene que estar el archivo que registra el log. Si te fijas en el archivo que vimos antes, `sudo_config`, viene especificada la ruta y el nombre del archivo log de sudo, en mi caso se llama sudo_config también, lo normal es que tenga el nombre sudo_log, pero no es importante si se llama log, config o paco, mientras cumpla su función.

Para verificar que se actualiza, ejecuta cualquier comando sudo y luego realiza un `sudo tail /var/log/sudo/<logfile>`.

### UFW

➤ Verificar que UFW está instalado y funcionando (ya lo hicimos al principio).

Como ya hemos comprobado al principio que el servicio estaba funcionando, este paso tiene poco sentido, pero podemos mirar la versión instalada, por cambiar...

`sudo apt -qq -list ufw`

➤ Explicación básica de UFW.

Es un cortafuegos que por defecto deniega cualquier conexión a todos los puertos del equipo, a excepción de los que el usuario añada como reglas.

➤ Comprueba la lista de reglas de UFW, debe existir una regla para el puerto 4242.

`sudo ufw status`

➤ Añade una regla para el puerto 8080, luego elimina esta regla.

`sudo ufw allow 8080`

`sudo ufw delete allow 8080`

### SSH

➤ Verificar que SSH está instalado y funcionando (otra vez...).

`sudo apt -qq -list ssh`

➤ Explicación básica de SSH.

SSH es un protocolo de red que permite a los usuarios una forma segura de acceder de forma remota a un equipo, incluso si se desconfía de la seguridad de la red usada para hacerlo, ya que la comunicación se hace de manera cifrada.

➤ Comprueba que el servicio SSH solo usa el puerto 4242.

`sudo nano /etc/ssh/sshd_config` o `sudo grep Port /etc/ssh/sshd_config`

➤ Comprueba que no es posible conectarse via SSH con usuario root, luego conecta con el nuevo usuario.

`ssh root@localhost -p 4242`

`ssh <new_user>@localhost -p 4242`

### Script

➤ Enseña tu script monitoring.sh y explica de manera general que hace.

`sudo nano /usr/local/bin/monitoring.sh`

No sé muy bien hasta qué punto hay que pararse a explicar el script (cada línea, comando?). Yo explicaría la estructura en general, el wall y poco más (tengo que revisarlo, según vayan las evaluaciones).

➤ Explicación breve de qué es cron.

Cron es un servicio de administrador de tareas de Linux que permite ejecutar archivos, en nuestro caso un script, en un momento determinado que estableceremos nosotros mismos modificando el archivo `contrab`.

➤ Cambia la frecuencia con la que se muestra el script en pantalla, desactivalo completamente y luego reinicia la máquina y comprueba que sigue estando sin modificar.

`sudo crontab -u root -e`

Al final del archivo debe aparecer: 

```
*/10 * * * * sh /var/local/sleep.sh && /var/local/monitoring.sh
```

Aquí deberíamos saber explicar que `*/10` es cada diez minutos, (podemos cambiarlo para hacer la prueba de que funciona con cualquier ejemplo), que el resto de `*` serían `hora-dia-mes-diadelasemana`, que `sh` es la forma con la que especificamos que el archivo a ejecutar es un script, luego las rutas a los script a ejecutar y añadimos entre ella el comando booleano `&&` para que hasta que no se cumpla sleep, no ejectuamos monitoring.

Para detener el servicio cron: `sudo systemctl stop cron` y para reactivarlo `sudo systemctl stop cron`. Si lo desactivas de esta forma, aunque reinicies el sistema con el servicio parado, al iniciar de nuevo estará activo.

Para comprobar, después de desactivarlo, que el script no se ha modificado ni eliminado: `sudo nano /usr/local/bin/monitoring.sh`.

## BONUS

➤ Muestra las particiones, comprueba que coincidan con el ejemplo de particiones BONUS del subject.

Comando `lsblk`, comparar lo que se muestra en pantalla con el ejemplo del subject.

➤ Comprueba que existe una página Wordpress del localhost.

En el navegador, introduce `localhost` o la IP del equipo. Debe aparecer una página wordpress.

➤ Comprueba que todos los servicios necesarios para wordpress están instalados correctamente.

Podemos comprobar que todo el stack que es necesario instalar antes de wordpress está actualmente instalado en el sistema con los siguientes comandos:

`dpkg -l | grep lighttpd` (ver disponibilidad lighttpd)

`sudo ufw status` (ver puerto 80)

`dpkg -l | grep mariadb-server` (ver disponibilidad mariadb-server)

`dpkg -l | grep php` (ver disponibilidad php)

`dpkg -l | grep wget` (ver disponibilidad wget)

➤ Explica qué servicio extra has decidido instalar y demuestra que funciona.

- FTP

Conectar a nuestra máquina virtual usando `$ ftp <ip_number>` desde otro terminal o equipo conecntado a la misma red (podemos usar termnux en el movil, por ejemplo). Desde el mismo MAC en 42 a mi me ha dado siempre problemas, también se puede instalar y usar filezilla, pero yo personalmente no lo he llegado a usar.

Para probar que de verdad puedes modificar archivos, crea una carpeta en el directorio de ftp y luego desde la maquina virtual comprueba con ls -l que efectivamente se ha creado, luego puedes borrarlo desde la conexion remota de nuevo.