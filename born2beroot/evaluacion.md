# Born2beroot Guía de evaluación

Esta es una guía para realizar paso a paso todos los comandos, pruebas y consideraciones necesarias para comprobar cada parte de la hoja de evaluación del proyecto.

## Preliminaries

Simplemente hacer la evaluación de manera presencial y descargar el repositorio git de intra del evaluado para comprobar que contiende los archivos que especifica el subject. 

Una vez descargado el repo, comprueba que no contiene archivos ocultos `ls -la` y que solo tiene el archivo `signature.txt` con la firma de la máquina virtual.

## General instructions

Comparar la firma de signature.txt del repositorio con la del archivo `born2beroot.vdi` ubicado en el equipo local.

`shasum born2beroot.vdi` 

## Mandatory part

### Overview

➤ Máquina virtual; qué es, cómo funciona y por qué usarla.

➤ CentOs y Debian, diferencias y por qué has elegido uno (Debian).

➤ Apt vs Aptitude y APPArmor.

➤ Comprueba que se está ejecutando el script cada 10 minutos.

### Setup

➤ Comprueba que la máquina virtual NO cuenta con interfaz gráfica.

➤ La contraseña para acceder al usuario de la máquina cumple con las reglas del subject.

➤ Verifica que el servicio UFW está operativo.

➤ Verifica que el servicio SSH está operativo.

➤ Comprueba el sistema operativo del sistema.

### User

➤ Comprueba que el usuario se encuentra en el grupo sudo y user42.

➤ Crea un nuevo usuario y asignale una contraseña, puedes probar a que esta contraseña sea débil intencionadamente para volver a comprobar que se cumple la política de contraseñas.

➤ Edita los archivos de politica de contraseñas para comprobar que se han establecido las reglas impuestas por el subject.

➤ Crea un grupo nuevo 'evaluating' e incluye al usuario nuevo en él y comprueba que se haya incluido correctamente.

➤ Explica/argumenta las ventajas y desventajas de usar esta política de contraseñas.

### Hostname and partitions

➤ Comprueba que el nombre del host cumple con el patrón del subject (<hostname>42).

➤ Cambia el hostname y reinicia la máquina para comprobar que sigue cambiado.

➤ Mira la lista de particiones y comprueba que se corresponden con las del subject (ten en cuenta que dependiendo de si se ha realizado o no el bonus, habrá que mirar diferentes ejemplos del subject).

➤ Explicación de LVM.

### Sudo

➤ Comprobar que sudo está instalado (este paso tiene poco sentido, a estas alturas ya hemos usado bastantes comandos sudo).

➤ Comprobar que el usuario nuevo está incluido dentro del grupo sudo (también lo hemos hecho antes...).

➤ Explicación del uso de sudo, de las reglas que hemos establecido para este y editar los archivos de sudo para enseñar cómo hemos modificado estas reglas.

➤ Log de sudo. Mostrar que la carpeta /var/log/sudo existe y que contiene al menos un archivo (el log) y que este se actualiza cuando usamos comandos sudo.
 
### UFW

➤ Verificar que UFW está instalado y funcionando (ya lo hicimos al principio).

➤ Explicación básica de UFW.

➤ Comprueba la lista de reglas de UFW, debe existir una regla para el puerto 4242.

➤ Añade una regla para el puerto 8080, luego elimina esta regla.


### SSH

➤ Verificar que SSH está instalado y funcionando (otra vez...).

➤ Explicación básica de SSH.

➤ Comprueba que el servicio SSH solo usa el puerto 4242.

➤ Comprueba que no es posible conectarse via SSH con usuario root, luego conecta con el nuevo usuario.

### Script

➤ Enseña tu script monitoring.sh y explica de manera general que hace.

➤ Explicación breve de qué es cron.

➤ Cambia la frecuencia con la que se muestra el script en pantalla, desactivalo completamente y luego reinicia la máquina y comprueba que sigue estando sin modificar.

## BONUS

➤ Muestra las particiones, comprueba que coincidan con el ejemplo de particiones BONUS del subject.

➤ Comprueba que existe una página Wordpress del localhost.

➤ Comprueba que todos los servicios necesarios para wordpress están instalados correctamente.

➤ Explica qué servicio extra has decidido instalar y demuestra que funciona.
