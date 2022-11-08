# Born2beroot-Guía 💻

# Índice

0. [sgoingfre](#0--sgoinfre)
1. [Descargar imagen de la maquina virtual 💿](#1--descargar-imagen-de-la-maquina-virtual-)
2. [Instalación de la maquina 🛠](#2--instalacion-de-la-maquina-)
3. [Instalación Debian 🌀](#3--instalación-debian-)
	
	3.1 [Particionado manual del disco](#31--particionado-manual-del-disco)

4. [Configuración de la máquina virtual ⚙️](#4-configuración-de-la-máquina-virtual-%EF%B8%8F)

	4.1 [Instalación de sudo y configuración de usuarios y grupos 👤](#41---instalación-de-sudo-y-configuración-de-usuarios-y-grupos-)
	
	4.2 [Instalación y configuración de SSH 📶](#42---instalación-y-configuración-ssh-)
	
	4.3 [Instalación y configuración de UFW 🔥🧱](#4-3-instalació-y-configuración-de-ufw-)
	
	4.4 [Configurar contraseña fuerte para sudo 🔒](#4-4-configurar-contraseña-fuerte-para-sudo-)
	
	4.5 [Configuración de política de contraseñas fuerte 🔑](#4-5-configuración-de-política-de-contraseñas-fuerte-)
	
	4.6 [Conectarse via SSH 🗣](#4-6-conectarse-via-ssh-)
	
5. [Script 🚨](#5--script-)

	5.1 [Resultado total del script 🆗](#5-13-resultado-total-del-script)
	
6. [Crontab ⏰](#6--crontab-)
7. [Signature.txt 📝](#7--signaturetxt-)

## 0. sgoinfre 
Importante tener creada la carpeta en sgoingfre/perso/<tu_login>, y modificar sus permisos (chmod 700)

Aquí vamos a trabajar todo el proyecto, guardaremos la ISO del sistema operativo y el archivo que genera VirtualBox

## 1. Descarga de Debian💿
[Click aqui](https://www.debian.org/distrib/index.es.html) para descargar la ISO de Debian desde su web oficial. Seleccionar aquitectra amd64.

## 2- Instalacion de la maquina 🛠

Para realizar la instalación se requiere de un software de virtualización. En este tutorial haremos uso de [VirtualBox](https://www.virtualbox.org/). Si ya tienes VirtualBox instalado y dispones de la ISO Debian ya podemos empezar con el tutorial.

1 ◦ Debemos abrir VirtualBox y pinchar sobre ```Nueva```

<img width="836" alt="Captura de pantalla 2022-07-13 a las 18 02 05" src="https://user-images.githubusercontent.com/66915274/178779265-38eade6e-2789-4597-89e9-5beca2d3921a.png">

2 ◦ Escogemos el nombre de nuestra máquina (born2beroot) y la carpeta donde estará ubicada. Importante introducir la maquina dentro de la carpeta sgoinfre ya que si no la ubicamos ahí nos quedaremos sin espacio y fallará la instalación (dependiendo del campus la ruta de sgoinfre puede cambiar). 

<img width="928" alt="Screen Shot 2022-10-23 at 2 57 11 PM" src="https://user-images.githubusercontent.com/66915274/197393458-dda8da5f-2362-4d36-b740-0951ebf03d3c.png">

3 ◦ Dejamos la cantidad de memoria RAM que reservaremos para la máquina cómo está por defecto (1024). 

<img width="685" alt="Captura de pantalla 2022-07-13 a las 13 06 05" src="https://user-images.githubusercontent.com/66915274/178781098-8aa07fbc-e1d2-4bee-8021-ddf052880364.png">

4 ◦ Seleccionamos la segunda opción para asi crear un disco duro virtual ahora.

<img width="826" alt="Captura de pantalla 2022-07-13 a las 18 13 24" src="https://user-images.githubusercontent.com/66915274/178781390-289236e0-1732-4dd8-8d3d-34eb0a229a18.png">

5 ◦ Escogemos la primera opción ```VDI``` ya que nos hemos descargado una imagen de disco.

<img width="829" alt="Captura de pantalla 2022-07-13 a las 18 16 35" src="https://user-images.githubusercontent.com/66915274/178781999-a42c3c6c-bc1e-4ad5-8bc5-b4b3f811c3f2.png">

6 ◦ Seleccionamos la primera opción ```Reservado dinámicamente``` para que asi se vaya reservando memoria en la máquina real segun vayamos utilizandola en la virtual hasta llegado al límite máximo disponible en la virtual.

<img width="833" alt="Captura de pantalla 2022-07-13 a las 18 19 33" src="https://user-images.githubusercontent.com/66915274/178782529-fb309739-3169-4e20-b3e1-23d17a122a18.png">

7 ◦ Seleccionamos el tamaño de disco, no es importante, el ejemplo de 30Gb del bonus en el subject es solo eso, un ejemplo. Luego deberemos darle a ```Crear```.

<img width="835" alt="Captura de pantalla 2022-07-13 a las 18 25 20" src="https://user-images.githubusercontent.com/66915274/178783666-4fa624a3-9c38-4c45-b6a8-d476c2864200.png">

8 ◦ Ahora vamos a selecionar la imagen ISO para instalar el SO. Debemos darle a ```configuración```

<img width="831" alt="Captura de pantalla 2022-07-13 a las 18 30 46" src="https://user-images.githubusercontent.com/66915274/178784822-38228e96-ca37-4cc0-b3ca-551829e4c8c8.png">

9 ◦ Acto seguido pincharemos encima de ```Almacenamiento``` , volveremos a pinchar sobre el emoticono 💿 que se encuentra a la derecha y de nuevo pincharemos sobre ```Seleccionar un archivo de disco```.

<img width="962" alt="Captura de pantalla 2022-07-13 a las 18 33 28" src="https://user-images.githubusercontent.com/66915274/178785148-2904cf4f-93c0-4866-a5d6-778390bddeb7.png">

10 ◦ Seleccionaremos la ISO que habíamos descargado, ```Abrir``` y después ```Aceptar```. 

<img width="790" alt="Captura de pantalla 2022-07-13 a las 18 38 39" src="https://user-images.githubusercontent.com/66915274/178786115-24f93fde-bc01-4e60-bf8d-20d7a5ae83be.png">

11 ◦ Una vez completados todos los pasos anteriores ya podemos ```Iniciar``` nuestra máquina virtual.

❗❗ Posibles problemas al ejecutar la máquina virtual ❗❗

 ◦ Teclas se pulsan repetidas veces: es por redimensionar (scale factor) la pantalla de la máquina virtual por encima del 150%, hay que bajarlo a ese valor como máximo. 

 ◦ Lag/delay de la máquina virtual: en teoría, asignar más memoria RAM a la máquina virtual, desde la configuración en VirtualBox, debería solucionar este problema, aunque a mi nunca ha llegado a funcionar completamente fluida.

 ◦ "Parpadeao" de la pantalla en la terminal de la máquina virtual: esto es normal, le pasa a casi todos los compañeros, no he encontrado solución, mejor conectar por ssh lo antes posible y dejar de lado la terminal de la máquina virtual.

## 3- Instalación Debian 🌀

1 ◦ Escogeremos la version sin interfaz gráfica ```Install``` ya que el subject indica que no se utilice interfaz gráfica

<img width="632" alt="Captura de pantalla 2022-07-13 a las 18 58 48" src="https://user-images.githubusercontent.com/66915274/178789643-e987c6d0-5b6f-4b98-ad4a-5c092a352183.png">

2 ◦ Escogeremos el idioma que usaremos para la instalación y el predeterminado que se le quedará al sistema ```English```.  

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 00 41" src="https://user-images.githubusercontent.com/66915274/178789949-4fe83ac8-23b8-4f82-a034-a6d5e81d4f17.png">

3 ◦ Introducimos nuestro País, territorio o zona. En mi caso pondre ```Other```.

<img width="791" alt="Captura de pantalla 2022-07-13 a las 19 07 50" src="https://user-images.githubusercontent.com/66915274/178791067-44230a4c-e647-46cb-9d6f-bc441bf0227b.png">

4 ◦ Como he seleccionado other debo indicar mi continente o region. En mi caso pongo ```Europe``` 🇪🇺. 

<img width="797" alt="Captura de pantalla 2022-07-13 a las 19 09 58" src="https://user-images.githubusercontent.com/66915274/178791387-78171f90-2834-42ab-aedb-9cf900d0ecd5.png">

5 ◦ Seleccionamos el país. En mi caso ```Spain``` 🇪🇸.

<img width="793" alt="Captura de pantalla 2022-07-13 a las 19 12 01" src="https://user-images.githubusercontent.com/66915274/178791824-7a34813c-eae9-4b5c-9873-cea158229e07.png">

6 ◦ Seleccionamos ```United States```.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 13 43" src="https://user-images.githubusercontent.com/66915274/178792054-4e72dfdd-8175-48f9-a06d-f2696fa752e3.png">

7 ◦ Configurarción teclado: si te aparece la opción (a mi en la última versión que use no me aperecia) selecciona ```Spanish```, para no volverte loco después con el teclado...
Si no te queda otra, selecciona ```American English```.

<img width="793" alt="Captura de pantalla 2022-07-13 a las 19 02 21" src="https://user-images.githubusercontent.com/66915274/178790230-d2571d4f-a546-4b43-bd44-c6a591d92d72.png">

8 ◦ En este paso debemos elegir el ```Host Name``` de la máquina, el cual debe ser tu login seguido de 42. 

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 17 23" src="https://user-images.githubusercontent.com/66915274/178792607-1cc585eb-ae32-4b2c-97fd-4fcf5bad4262.png">

9 ◦ ```Domain name```: lo dejamos en blanco, no se especifica nada en el subject.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 20 29" src="https://user-images.githubusercontent.com/66915274/178793113-b0934aac-fac4-4844-8412-aca124038fd0.png">

10 ◦ Debemos introducir una contraseña para la cuenta de administración del sistema. Importante apuntarla o hacer una foto ya que le daremos uso. Si quieres ver la contraseña para asegurarte de que la has escrito correctamente debes tabular hasta llegar a la opción ```Show Password in Clear``` debes darle a la barra espaciadora y se mostrara la clave. Nos pedirá volver a introducirla para confirmar.

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 21 29" src="https://user-images.githubusercontent.com/66915274/178793296-c2c3b6c5-9744-4ba8-ac32-8e3c21c44f9b.png">

12 ◦ Nombre de nuestro nuevo usuario, debe ser nuestro nuestro login de 42. Nos pedirá introducirlo dos veces.

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 26 20" src="https://user-images.githubusercontent.com/66915274/178794178-901f7951-a978-458d-a925-4586026784f7.png">

13 ◦ Ahora debemos introducir la contraseña de nuestro nuevo usuario. Como la anterior , repetiremos el proceso para comprobar que no la hayas escrito mal y tambien es importante que la guardes porque le daremos uso más adelante. Yo personalmente he usado siempre la misma contraseña para todas las situaciones en las que nos piden establecer una.

<img width="790" alt="Captura de pantalla 2022-07-13 a las 19 30 08" src="https://user-images.githubusercontent.com/66915274/178794862-94de8c7a-282e-4a83-9903-d3b8439122ea.png">

14 ◦ Seleccionamos la hora de nuestra ubicación.

<img width="796" alt="Captura de pantalla 2022-07-13 a las 19 31 41" src="https://user-images.githubusercontent.com/66915274/178795105-956854e1-deff-4851-8eba-26cdefb1e06f.png">

15 ◦ Vamos a hacer las particiones de forma manual, para hacer el bonus. Esocgeremos la opción ```Manual```.

### 3.1- Particionado manual del disco

1 ◦ En el momento de escoger el particionado de disco seleccionaremos manual. De esta manera podremos editar las particiones una a una.

<img width="789" alt="Screen Shot 2022-10-23 at 4 30 48 PM" src="https://user-images.githubusercontent.com/66915274/197397840-b6ae9d65-a6aa-4a5d-a03f-856d9ce81644.png">

2 ◦ En este apartado nos muestra una descripción general de nuestras particiones y puntos de montaje. Actualmente no tenemos particiones hechas. Para crear una nueva tabla de particiones debemos escoger el dispositivo donde queremos crearlas. En nuestro caso escogeremos el único disponible.

<img width="793" alt="Screen Shot 2022-10-23 at 4 35 39 PM" src="https://user-images.githubusercontent.com/66915274/197398114-44abc561-d34d-47c9-b512-581b4ec6fddb.png">

3 ◦ Aceptamos el mensaje de confirmación. Básicamente nos avisa que si ya hay particiones en el dispositivo seran eliminadas y que si estamos seguros de crear una nueva tabla de particiones vacía..

<img width="770" alt="Screen Shot 2022-10-23 at 4 36 08 PM" src="https://user-images.githubusercontent.com/66915274/197398137-b9fe1f96-5907-462e-8a50-44b71ae2aefe.png">

4 ◦ Una vez hemos completado el paso anterior podemos ver como nos aparece nuestra tabla de particiones vacía. Ahora debemos configurarla , para ello debemos seleccionarla.

<img width="786" alt="Screen Shot 2022-10-23 at 4 36 35 PM" src="https://user-images.githubusercontent.com/66915274/197398172-b05fa7aa-e5b4-40cb-afd4-03a1404d7885.png">

5 ◦ Crearemos una nueva partición.

<img width="512" alt="Screen Shot 2022-10-23 at 4 36 54 PM" src="https://user-images.githubusercontent.com/66915274/197398199-70570553-de1b-49a9-8c44-da9a1e4b5c1e.png">

Empezaremos creando esta:

![image](https://user-images.githubusercontent.com/66915274/197427077-48636236-4012-4edf-b0e4-319db502e685.png)

6 ◦ Como bien indica el subject el tamaño de la partición debe ser de 500 megabytes.

<img width="777" alt="Screen Shot 2022-10-23 at 4 37 27 PM" src="https://user-images.githubusercontent.com/66915274/197398241-604b2bb2-7303-412a-b382-40bfbf443ed0.png">

7 ◦ Escogemos el tipo de la partición. Escogemos primaria ya que será la partición donde se encontrará instalado el Sistema Operativo.

<img width="457" alt="Screen Shot 2022-10-23 at 4 37 38 PM" src="https://user-images.githubusercontent.com/66915274/197398253-2c0f8205-3d3f-4ab7-94a3-70c37ee014d9.png">

8 ◦ Seleccionaremos beginning ya que queremos que la nueva partición se cree al principio del espacio disponible.

<img width="787" alt="Screen Shot 2022-10-23 at 4 37 52 PM" src="https://user-images.githubusercontent.com/66915274/197398265-c63d7b32-55b7-45ad-86b3-166e44cfd598.png">

9 ◦ En la siguiente captura nos muestra los detalles de la partición. Modificaremos el punto de montaje al que escifica el subject.

<img width="781" alt="Screen Shot 2022-10-23 at 4 38 27 PM" src="https://user-images.githubusercontent.com/66915274/197398293-2487ded0-2584-48c4-a5ea-1f2464ec39f9.png">

10 ◦ Escogemos boot como el punto de montaje de nuestra partición.

<img width="577" alt="Screen Shot 2022-10-23 at 4 38 49 PM" src="https://user-images.githubusercontent.com/66915274/197398322-51b9854b-ab32-4d81-8126-3ef3913858a6.png">

11 ◦ Terminamos de configurar la partición actual.

<img width="787" alt="Screen Shot 2022-10-23 at 4 39 07 PM" src="https://user-images.githubusercontent.com/66915274/197398336-72b17153-73dc-48a5-b7d3-839877e8983b.png">

12 ◦ Una vez hemos completado el paso anterior ya nos debe aparecer la partición. Ahora debemos crear una partición lógica con todo el espacio disponible del disco, que no tenga punto de montaje y que este encriptada. Para ello seleccionamos el espacio libre donde queremos crearla.

<img width="781" alt="Screen Shot 2022-10-23 at 4 39 37 PM" src="https://user-images.githubusercontent.com/66915274/197398367-ee8a1f5d-3941-4a86-a775-90f29b1c955e.png">

![image](https://user-images.githubusercontent.com/66915274/197431553-718358bb-6570-41dd-b114-09acc347999d.png)

13 ◦ Creamos nueva partición.

<img width="462" alt="Screen Shot 2022-10-23 at 4 39 58 PM" src="https://user-images.githubusercontent.com/66915274/197398396-843c7fb3-b945-4305-a960-02aa9d4ca940.png">

14 ◦ Seleccionamos el tamaño máximo.

<img width="779" alt="Screen Shot 2022-10-23 at 4 40 26 PM" src="https://user-images.githubusercontent.com/66915274/197398425-63205376-839f-4986-a8d0-981cdaa380e4.png">

15 ◦ Seleccionamos el tipo de particion, en este caso lógica.

<img width="466" alt="Screen Shot 2022-10-23 at 4 40 53 PM" src="https://user-images.githubusercontent.com/66915274/197398448-49c99180-9a3d-4dd4-a9ce-d680bfdefa1c.png">

16 ◦ Modificaremos el punto de montaje.

<img width="788" alt="Screen Shot 2022-10-23 at 4 41 44 PM" src="https://user-images.githubusercontent.com/66915274/197398500-188cc4fb-4eb5-4a56-893b-58838877c056.png">

17 ◦ Escogeremos la opción de no montarlo.

<img width="590" alt="Screen Shot 2022-10-23 at 4 42 11 PM" src="https://user-images.githubusercontent.com/66915274/197398518-f6fb7588-8c53-40a9-9ceb-238d6a62d942.png">

18 ◦ Terminamos de configurar la partición actual.

<img width="788" alt="Screen Shot 2022-10-23 at 4 42 41 PM" src="https://user-images.githubusercontent.com/66915274/197398541-922f2c4d-ed5a-4d92-8083-ccf57aec3dee.png">

19 ◦ Configuraremos volúmenes encriptados. Para asi poder encriptar nuestra partición.

<img width="786" alt="Screen Shot 2022-10-23 at 4 43 08 PM" src="https://user-images.githubusercontent.com/66915274/197398562-2369fa90-7db9-4ba3-abed-7ac15ede8b81.png">

20 ◦ Aceptamos el mensaje de confirmación.

<img width="777" alt="Screen Shot 2022-10-23 at 4 43 27 PM" src="https://user-images.githubusercontent.com/66915274/197398573-9720e351-04f4-49f0-a3dc-fe0ce1ada296.png">

21 ◦ Creamos los volúmenes encriptados.

<img width="596" alt="Screen Shot 2022-10-23 at 4 43 46 PM" src="https://user-images.githubusercontent.com/66915274/197398595-b36ab8da-86c6-483a-99fd-079293a92570.png">

22 ◦ Seleccionamos en que partición queremos realizar la encriptación.

<img width="568" alt="Screen Shot 2022-10-23 at 4 44 06 PM" src="https://user-images.githubusercontent.com/66915274/197398615-7c9f8e45-7885-4f39-84eb-e3a056eeb2c7.png">

23 ◦ Terminamos de configurar la partición actual.

<img width="787" alt="Screen Shot 2022-10-23 at 4 44 35 PM" src="https://user-images.githubusercontent.com/66915274/197398649-06749ec8-903d-4b1a-af2a-c2dad77bcaec.png">

24 ◦ Finalizamos ya que no queremos crear mas volúmenes encriptados.

<img width="589" alt="Screen Shot 2022-10-23 at 4 44 49 PM" src="https://user-images.githubusercontent.com/66915274/197398663-0bd74c65-b3fd-430c-b3e6-4f1e0c76ae8d.png">

25 ◦ Aceptamos el mensaje de confirmación. Nos comenta que que se encriptara todo lo que hay dentro de la partición y que no debe tardar mucho en terminar.

<img width="783" alt="Screen Shot 2022-10-23 at 4 45 06 PM" src="https://user-images.githubusercontent.com/66915274/197398670-91db3e3e-b271-4e1b-ad8a-28ceb06e0897.png">

26 ◦ (Opcional) Le damos a cancel para saltar el paso; no hay nada que encriptar ya que la partición esta vacía.

<img width="789" alt="Screen Shot 2022-10-23 at 4 45 27 PM" src="https://user-images.githubusercontent.com/66915274/197398685-6603ef31-d499-46da-949f-ade8e2a05bf9.png">

27 ◦ De nuevo deberemos poner una contraseña, esta vez será la frase de encriptación. Como te he comentado previamente deberás repetir el proceso y la debes anotar ya que será importante en un futuro.

<img width="779" alt="Screen Shot 2022-10-23 at 4 48 38 PM" src="https://user-images.githubusercontent.com/66915274/197398855-0c93f419-897e-4eee-9499-18321d8e8dfd.png">

28 ◦ Repetimos la frase de encriptación.

<img width="722" alt="Screen Shot 2022-10-23 at 4 49 01 PM" src="https://user-images.githubusercontent.com/66915274/197398875-3fa85638-7105-42bf-bbc2-e189fbbc1918.png">

29 ◦ Configuraremos el gestor de volumenes logicos. 

<img width="785" alt="Screen Shot 2022-10-23 at 4 50 17 PM" src="https://user-images.githubusercontent.com/66915274/197398933-85e0025e-0a4d-41f0-8fd0-5f0c8ee32e9b.png">

30 ◦ Aceptaremos en mensaje de confirmación ya que estamos de acuerdo con que se guarden los cambion en el disco.

<img width="786" alt="Screen Shot 2022-10-23 at 4 50 42 PM" src="https://user-images.githubusercontent.com/66915274/197398945-d79ea2a7-a13e-4e6a-9e9c-40bdcd2dd502.png">

31 ◦ Crearemos un nuevo grupo de volumen. Los grupos de volúmenes agrupan particiones.

<img width="454" alt="Screen Shot 2022-10-23 at 4 52 04 PM" src="https://user-images.githubusercontent.com/66915274/197399021-29b21274-37c1-4fd9-8526-962969d1cce3.png">

32 ◦ Introduciremos el nombre que queremos darle. ```LVMGroup``` tal y como indica el subject.

<img width="695" alt="Screen Shot 2022-10-23 at 4 52 58 PM" src="https://user-images.githubusercontent.com/66915274/197399065-1ac8d80d-9e18-4b4a-a60f-11496e7de26d.png">

33 ◦ Seleccionaremos la partición donde queremos cear el grupo. 

<img width="590" alt="Screen Shot 2022-10-23 at 4 53 22 PM" src="https://user-images.githubusercontent.com/66915274/197399089-5ea5f48e-176c-4278-8b14-a13b7f5ee45c.png">

34 ◦ Ahora debemos crear todas las particiones lógicas. Dejo captura de los tamaños que he usado yo para cada una en una máquina de 12Gb , ya que VirtualBox no me permitía asginarle 30Gb de disco a mi máquina (como el ejemplo del subject), no es necesario un tamaño en concreto.

AQUÍ TENGO QUE AÑADIR CAPTURA, EN EDITOR WEB =)

El orden de la creación de las unidades lógicas será el mismo que indica el subject; empezamos por root y terminamos con var-log. Solo aparecen capturas de la creación de la primera unidad para que se refleje el proceso (ignorad el tamaño que se usa en la captura), las demás las haremos igual, simplemente cambiando nombre y tamaño.

<img width="457" alt="Screen Shot 2022-10-23 at 4 53 50 PM" src="https://user-images.githubusercontent.com/66915274/197399108-fb566eb4-664f-4509-8948-ab4ed04407b5.png">

35 ◦ Empezaremos escogiendo el grupo donde queremos que se creen. Seleccionamos el único disponible (el que acabamos de crear - LVM). 

<img width="760" alt="Screen Shot 2022-10-23 at 4 54 02 PM" src="https://user-images.githubusercontent.com/66915274/197399115-e7d3b313-763c-421c-a71d-850d318432e7.png">

36 ◦ Empezamos por ```root```; seleccionaremos el nombre del volumen lógico.

<img width="662" alt="Screen Shot 2022-10-23 at 4 55 42 PM" src="https://user-images.githubusercontent.com/66915274/197399188-6ae8c83b-057d-498f-b112-9116079b0808.png">

37 ◦ Tamaño, en mi caso será de 4g. De nuevo, no es importante que cumpla un tamaño específico, si en tu caso has asignado más o menos disco a tu máquina, ahora asignara espacio a cada unidad en proporción y listo. Lo siguientes paso dejo de ejemplo los tamaños que he usado yo para la máquina de 12Gb.

<img width="782" alt="Screen Shot 2022-10-23 at 4 56 21 PM" src="https://user-images.githubusercontent.com/66915274/197399216-c65f43ca-fb8e-4d05-9212-24ad2ee87b39.png">

38 ◦ Repetimos el proceso para ```swap``` y le asignamos size ```1g```.

39 ◦ Repetimos el proceso para ```home``` y le asignamos size ```2g```.

40 ◦ Repetimos el proceso para ```var``` y le asigno size ```1.2g```.

41 ◦ Repetimos el proceso para ```srv``` y le asigno size ```1.2g```.

42 ◦ Repetimos el proceso para ```tmp``` y le asigno size ```1.2g```.

43 ◦ Repetimos el proceso para ```var-log``` y le asigno size ```1.4g```.