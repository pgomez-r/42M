# Born2beroot-Guía 💻

# Índice

0. [sgoingfre 📁](#0--sgoinfre)
1. [Descargar imagen de la maquina virtual 💿](#1--descargar-imagen-de-la-maquina-virtual-)
2. [Instalación de la maquina 🛠](#2--instalacion-de-la-maquina-)
3. [Instalación Debian 🌀](#3--instalación-debian-)
	
	3.1 [Particionado manual del disco 💾](#31--particionado-manual-del-disco)

4. [Configuración de la máquina virtual ⚙️](#4-configuración-de-la-máquina-virtual-%EF%B8%8F)

	4.1 [Instalación de sudo y configuración de usuarios y grupos 👤](#41---instalación-de-sudo-y-configuración-de-usuarios-y-grupos-)
	
	4.2 [Instalación y configuración de SSH 📶](#42---instalación-y-configuración-ssh-)
	
	4.3 [Conectarse via SSH 🗣](#4-3-conectarse-via-ssh-)

	4.4 [Instalación y configuración de UFW 🔥🧱](#4-4-instalació-y-configuración-de-ufw-)
	
	4.5 [Configurar contraseña fuerte para sudo 🔒](#4-5-configurar-contraseña-fuerte-para-sudo-)
	
	4.6 [Configuración de política de contraseñas fuerte 🔑](#4-6-configuración-de-política-de-contraseñas-fuerte-)
	
5. [Script 🚨](#5--script-)

	5.1 [Resultado total del script 🆗](#5-13-resultado-total-del-script)
	
6. [Crontab ⏰ vs SystemD ⌚](#6--crontab-vs-systemd)
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

<img width="690" alt="Screen Shot 2022-11-08 at 8 49 05 AM" src="https://user-images.githubusercontent.com/115219064/200511370-1f1d732f-f9fc-408a-b632-915bd428a9ad.png">

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

44 ◦ Una vez hayamos completado todos los pasos anteriores finalizaremos la configuración del gestor de volúmenes lógicos.

<img width="438" alt="Screen Shot 2022-10-23 at 5 09 51 PM" src="https://user-images.githubusercontent.com/66915274/197399904-c584fcdf-eb38-486f-af12-7374f1e04465.png">

45 ◦ Ahora debemos configurar todas las unidades para seleccionar el sistema de archivos que usarán y su punto de montaje de acuerdo a las indicaciones del subject. Lo haremos en el orden que aparecen, todas usaran el sistema de archivos Ext4 (menos swap) y como punto de montaje, el que coincide con el nombre de la unidad (en el caso de var-log, tenemos que introducirlo "manualmente").

<img width="783" alt="Screen Shot 2022-10-23 at 5 10 36 PM" src="https://user-images.githubusercontent.com/66915274/197399944-bccbe599-b80a-4abe-ac6c-d770447ea727.png">

46 ◦ Comenzamos por ```home```. Vamos a ver el proceso completo aquí, para las demás especifico los cambios y dejo solo captura de las excepciones en swap y en var-log. Lo primero es seleccionar ```Use as: do not use``` para poder elegir el sistema de archivos.

<img width="782" alt="Screen Shot 2022-10-23 at 5 10 55 PM" src="https://user-images.githubusercontent.com/66915274/197399976-9b871bda-9425-4dbe-b8c9-25c8c6d6c811.png">

47 ◦ Escogemos el sistema de archivos Ext4, es el sistema de archivos más utilizado en distribuciones Linux.  

<img width="412" alt="Screen Shot 2022-10-23 at 5 11 18 PM" src="https://user-images.githubusercontent.com/66915274/197400000-2e855fc9-10b1-4f3e-9c58-85b6ff02a4fb.png">

48 ◦ Una vez hayamos elegido sistema de archivos, nos aparecerán más opciones para configurar. Ahora debemos seleccionar el punto de montaje. 

<img width="782" alt="Screen Shot 2022-10-23 at 5 11 44 PM" src="https://user-images.githubusercontent.com/66915274/197400023-387a70aa-b491-43c0-91d2-cb378da9fc75.png">

49 ◦ Seleccionamos ```home``` como bien indica el subject.

<img width="515" alt="Screen Shot 2022-10-23 at 5 11 54 PM" src="https://user-images.githubusercontent.com/66915274/197400040-e79cad4f-368b-4cee-9ec0-942f38b2f785.png">

50 ◦ Una vez ya lo hemos seleccionado terminaremos la configuración de la partición.

<img width="785" alt="Screen Shot 2022-10-23 at 5 12 10 PM" src="https://user-images.githubusercontent.com/66915274/197400059-ab96f2c4-cd92-47cb-a9ee-61257537ee6a.png">

51 ◦ Repetimos mismo proceso para ```root```, pero para su punto de montaje escojemos la opción ```/```.

52 ◦ Repetimos el proceso para ```srv``` y cambiaremos su punto de montaje a ```srv```.

53 ◦ Para ```swap``` haremos una excepción ya el sistema de archivos será diferente. 

54 ◦ En el momento de seleccionar el sistema de archivos lo dejamos en ```swap area```. No tendremos que asignar un punto de montaje para swap.

<img width="370" alt="Screen Shot 2022-10-23 at 5 16 59 PM" src="https://user-images.githubusercontent.com/66915274/197400297-8eed129d-0ec0-49a8-8b2a-dd0d04055f75.png">

55 ◦ Una vez realizado el paso anterior terminaremos la configuración de la partición.

56 ◦ Seguimos con ```tmp```, aquí si volvemos a repetir el proceso "estandar", le asignamos ```tmp``` como punto de montaje.

57 ◦ Repetimos de nuevo el proceso para ```var``` con su respectivo punto de montaje.

58 ◦ Por último, seleccionamos ```var-log```, en este caso deberemos introducir manualmente el punto de montaje ```/var/log```.

![image](https://user-images.githubusercontent.com/66915274/197602673-5c18be85-1b0f-430b-b507-66711b807115.png)

![image](https://user-images.githubusercontent.com/66915274/197602699-fddadd2d-c54d-4313-8165-a93db1249b26.png)

59 ◦ Una vez hemos completado todos los pasos anteriores ya casi hemos acabado, debemos darle a finalizar el particionado para que se guarden todos los cambios en el disco.

![image](https://user-images.githubusercontent.com/66915274/197602907-4a3ba459-1a5d-468e-81dc-5206403cf034.png)

60 ◦ Aceptamos el mensaje y asi se guardaran los cambios. Asegurate que todas las particiones quedan igual que en la captura.

![image](https://user-images.githubusercontent.com/66915274/197602944-13ca67b2-bcc5-476c-84dc-aadc5e1d3baf.png)

61 ◦ Seleccionamos la opción ```No``` ya que no necesitamos paquetes adicionales. 

<img width="770" alt="Captura de pantalla 2022-07-13 a las 20 05 42" src="https://user-images.githubusercontent.com/66915274/178801099-2dda24f5-0d46-4184-8c44-a8fe0bf46527.png">

62 ◦ Escogemos nuestro País.

<img width="756" alt="Captura de pantalla 2022-07-13 a las 20 14 23" src="https://user-images.githubusercontent.com/66915274/178802653-d9e8504a-b60b-4441-8ee3-8d48ca4a6bf0.png">

63 ◦ Escogemos ```deb.debian.org``` ya que tenindo en cuenta nuestra region es donde tendremos una mejor conexión.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 15 00" src="https://user-images.githubusercontent.com/66915274/178802772-4f67cd99-60d5-4439-8502-317e81e07d70.png">

64 ◦ Esta opción la dejaremos vacía le daremos directamente a ```Continue```.

<img width="797" alt="Captura de pantalla 2022-07-13 a las 20 17 24" src="https://user-images.githubusercontent.com/66915274/178803208-2969acae-3fa7-423e-8a3c-bb7c76eff824.png">

65 ◦ Seleccionamos la opcion ```No``` ya que no queremos que los developers vean nuestras estadísticas aunque sean anónimas.

<img width="796" alt="Captura de pantalla 2022-07-13 a las 20 21 54" src="https://user-images.githubusercontent.com/66915274/178803926-a4efbc70-f3e2-4e6c-9809-9152478d8237.png">

66 ◦ Quitaremos todas las opciones de software (con la barra espaciadora) y le daremos a ```Continue```.

<img width="797" alt="Captura de pantalla 2022-07-13 a las 20 24 17" src="https://user-images.githubusercontent.com/66915274/178804377-e775b89e-93d4-482f-a4d0-0ef126f47719.png">

67 ◦ Seleccionaremos ```Yes``` para instalar [GRUB boot](https://es.wikipedia.org/wiki/GNU_GRUB) en el disco duro.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 26 24" src="https://user-images.githubusercontent.com/66915274/178804771-ba16e0b7-9f06-4c5b-9451-0bfd65efd2bb.png">

68 ◦ Escogeremos el dispositivo para la instalación del cargador de arranque ```/dev/sda (ata_VBOX_HARDDISK)```. Ahora la pantalla puede quedar completamente azul, sin nada, mientras empieza la instalación y puede que esté así varios minutos... no pasa nada, es normal.
<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 35 46" src="https://user-images.githubusercontent.com/66915274/178806441-f1bf3159-4e09-4c9a-9102-b3261c9000d8.png">

69 ◦ Le daremos a ```Continue``` para finalizar la instalación. 

<img width="794" alt="Captura de pantalla 2022-07-13 a las 20 39 30" src="https://user-images.githubusercontent.com/66915274/178807102-e2a9722e-791f-48a0-ae35-b05b36a37ed2.png">

## 4 Configuración de la máquina virtual ⚙️

➤ ```Start``` desde VirtualBox.

➤ Lo primero que nos va a aparece es el boot selector (GRUB boot loader), podemos seleccionar ```Debian GNU/Linux``` o esperar unos segundos y se seleccionara por defecto.

➤ Nos pedirá la contraseña de encriptación que establecimos durante la instalación previamente.

<img width="714" alt="Captura de pantalla 2022-07-13 a las 20 47 26" src="https://user-images.githubusercontent.com/66915274/178808699-f1024129-5f90-41d0-a9a8-4806f5bc114b.png">

➤ Debemos introducir el usuario y contraseña que habíamos creado antes.

<img width="798" alt="Captura de pantalla 2022-07-13 a las 20 48 38" src="https://user-images.githubusercontent.com/66915274/178808994-664025ac-36df-4332-8e44-505ecd2ca305.png">

### Ya tenemos todo listo para empezar a configurar nuestra máquina virtual Debian❗️

### 4.1 - Instalación de sudo y configuración de usuarios y grupos 👤

1 ◦ Para la instalación de sudo primero debemos estar en el usuario root, para ello pondremos ```su``` en el terminal e introduciremos la contraseña root (la establecimos durante la instalación). Una vez hemos accedido al usuario root, debemos usar el comando ```apt install sudo```, comienzan a instalarse los paquetes necesarios.

<img width="796" alt="Captura de pantalla 2022-07-14 a las 1 36 46" src="https://user-images.githubusercontent.com/66915274/178855273-fc76689c-224b-4368-b7b1-5d1954427aff.png">

2 ◦ Debemos reiniciar la máquina para que se apliquen los cambios. Para ello haremos uso del comando ```sudo reboot``` y esperaremos a que se reinicie. 

<img width="514" alt="Captura de pantalla 2022-07-14 a las 2 02 24" src="https://user-images.githubusercontent.com/66915274/178857108-a51988e1-084c-498c-86c6-98ab5a3b1305.png">

3 ◦ Una vez reiniciado debemos volver a introducir las contraseñas de cifrado y del usuario. Para verificar que hayamos instalado ```sudo``` correctamente entraremos de nuevo en el usuario root y pondremos el comando ```sudo -V```, este comando además de mostrarnos la versión de sudo también mostrará los argumentos pasados para configurar cuando se creó sudo y los plugins que  pueden mostrar información más detallada. (Opcional) ➤ Puesto que el output del comando es muy largo si deseamos verlo completamente debemos redireccionar la salida del mismo a un fichero ```sudo -V > file.txt``` y luego editar el fichero ```nano file.txt```. O poner ```| more``` despues del comando.

<img width="799" alt="Captura de pantalla 2022-07-14 a las 2 09 59" src="https://user-images.githubusercontent.com/66915274/178857742-96356272-abd6-44c4-a3e6-5e8b9f471146.png">

4 ◦ Siguiendo en el usuario root crearemos un usuario con nuestro login con el comando ```sudo adduser login``` como nostros ya hemos creado el usuario en la instalación nos debe aparecer que el usuario ya existe.

<img width="509" alt="Captura de pantalla 2022-07-14 a las 2 15 11" src="https://user-images.githubusercontent.com/66915274/178858240-95ce2a2b-004a-4bcb-981a-7990c1cc4fdd.png">

5 ◦ Ahora deberemos crear un nuevo grupo llamado ```user42```. Para crearlo debemos hacer ```sudo addgroup user42```. 

<img width="367" alt="Screen Shot 2022-10-26 at 6 30 52 PM" src="https://user-images.githubusercontent.com/66915274/198082677-d393243e-363a-4d1f-95d8-a6695336a47a.png">

Podemos comprobar si se ha creado con el comando ```getent group nombre_grupo``` o también podemos hacer ```cat /etc/group``` y podremos ver todos los grupos y los usuarios que hay dentro de ellos.

6 ◦ Con el comando ```sudo adduser user group``` incluiremos al usuario en el grupo. Debemos incluir al usuario en los grupos ```sudo``` y ```user42```.

<img width="422" alt="Screen Shot 2022-10-26 at 6 32 30 PM" src="https://user-images.githubusercontent.com/66915274/198083019-c5a442bb-c625-45ce-84e1-bcbca3a7dba5.png">

<img width="404" alt="Screen Shot 2022-10-26 at 6 34 09 PM" src="https://user-images.githubusercontent.com/66915274/198083377-bd4162c6-317b-474f-8bc4-e542be4dcfde.png">

7 ◦ Una vez los hayamos introducido para checkear que todo se haya hecho correctamente podemos ejecutar el comando ```getent group nombre_grupo``` o tambien podemos editar el fichero /etc/group ```nano /etc/group``` y en los grupos ```sudo``` y ```login42``` debera aparecer nuestro usuario.

<img width="328" alt="Screen Shot 2022-10-26 at 6 35 50 PM" src="https://user-images.githubusercontent.com/66915274/198083739-ad16e388-69c3-41d1-a061-e55dd66b0d14.png">

<img width="151" alt="Screen Shot 2022-10-26 at 6 36 18 PM" src="https://user-images.githubusercontent.com/66915274/198083854-0fba5296-a49f-44cc-8427-59a692e69288.png">

<img width="353" alt="Screen Shot 2022-10-26 at 6 39 22 PM" src="https://user-images.githubusercontent.com/66915274/198084464-f73352ee-ed21-478b-a44d-d86eb6d8a1cd.png">

<img width="183" alt="Screen Shot 2022-10-26 at 6 38 25 PM" src="https://user-images.githubusercontent.com/66915274/198084311-45a50162-ff89-4e7d-a3c5-45e7048520a4.png">

### 4.2 - Instalación y configuración SSH 📶

1 ◦ Lo primero que haremos será hacer ```sudo apt update``` para actualizar los repositorios que definimos en el archivo /etc/apt/sources.list

<img width="774" alt="Captura de pantalla 2022-07-14 a las 3 09 44" src="https://user-images.githubusercontent.com/66915274/178864173-aa5a08cf-8562-4484-a60a-3e1c7a533a28.png">

2 ◦ Acto seguido instalaremos la herramienta principal de conectividad para el inicio de sesión remoto con el protocolo SSH, esta herramienta es OpenSSH. Para instalarla debemos introducir el comando ```sudo apt install openssh-server```. En el mensaje de confirmación ponemos ```Y```, acto seguido esperaremos a que termine la instalación.

<img width="772" alt="Captura de pantalla 2022-07-14 a las 3 14 52" src="https://user-images.githubusercontent.com/66915274/178865991-cdb90f12-ebd8-4583-bcbb-70f47c86abe6.png">

Para comprobar que se haya instalado correctamente haremos ```sudo service ssh status``` y nos debe aparecer active.

<img width="702" alt="Captura de pantalla 2022-07-14 a las 3 53 59" src="https://user-images.githubusercontent.com/66915274/178876938-7fd74214-15df-4759-bf8d-52b53a8f4251.png">

3 ◦ Una vez terminada la instalación se han creado algunos ficheros que debemos editar. Podemos usar nano o vi, o también instalar vim si lo prefieres. El primer fichero que editaremos será ```/etc/ssh/sshd_config```, así que en consola escribimos ```sudo nano /etc/ssh/sshd_config```.

<img width="497" alt="Captura de pantalla 2022-07-14 a las 3 24 21" src="https://user-images.githubusercontent.com/66915274/178867150-273c75c1-c935-45f0-a551-1a115d3f6f6a.png">

4 ◦ Los ```#``` al comienzo de una línea significan que esta comentada, las líneas que vayamos a modificar deberás quitarle el comentario. Una vez estemos editando el fichero deberemos modificar las siguientes líneas:

➤ #Port 22 -> Port 4242

<img width="807" alt="Captura de pantalla 2022-07-14 a las 3 31 04" src="https://user-images.githubusercontent.com/66915274/178867929-0f8be11e-d0ca-4445-af05-a693d01411bd.png">

➤ #PermitRootLogin prohibit-password -> PermitRootLogin no

<img width="798" alt="Captura de pantalla 2022-07-14 a las 3 34 13" src="https://user-images.githubusercontent.com/66915274/178868266-fc6d6684-8196-4021-b884-a047a443a3ec.png">

Una vez hayamos modificado esas líneas debemos guardar los cambios realizados sobre el fichero y dejar de editarlo.

5 ◦ Ahora debemos editar el fichero ```/etc/ssh/ssh_config```.

<img width="501" alt="Captura de pantalla 2022-07-14 a las 3 48 56" src="https://user-images.githubusercontent.com/66915274/178872582-8277e687-8ab7-4087-bd17-a71e5e86d5e6.png">

Editaremos la siguiente línea: 

➤ #Port 22 -> Port 4242

<img width="795" alt="Captura de pantalla 2022-07-14 a las 3 50 29" src="https://user-images.githubusercontent.com/66915274/178875013-1969c13f-9e43-4f2a-a037-f384a8e87a78.png">

6 ◦ Por último debemos reiniciar el servicio ssh para que así se actualicen las modificaciones que acabamos de realizar. Para ello debemos escribir el comando ```sudo service ssh restart``` y una vez reseteado miraremos el estado actual con ```sudo service ssh status``` y para confirmar que se hayan realizado los cambios en la escucha del servidor debe aparecer el Puerto 4242.

<img width="713" alt="Captura de pantalla 2022-07-14 a las 3 56 56" src="https://user-images.githubusercontent.com/66915274/178880333-0e2ad7fd-674b-4b4f-b92a-25acbc36c8a5.png">

### 4-3 Conectarse via SSH 🗣

1 ◦ Para conectarnos por SSH, primero hay que habilitar los puertos que va a usar este servicio. Para ello primero cerramos la máquina, abrimos VirtualBox y vamos a configuración o settings.

<img width="832" alt="Captura de pantalla 2022-07-18 a las 10 15 13" src="https://user-images.githubusercontent.com/66915274/179470948-d9a863ef-f1a3-41fb-a103-25378064e747.png">

2 ◦ Una vez en configuración debemos pinchar sobre el apartado de ```Red``` , pincharemos sobre ```Avanzadas``` para que así nos muestre más opciones y le daremos a ```Reenvío de puertos```.

<img width="684" alt="Captura de pantalla 2022-07-18 a las 10 18 32" src="https://user-images.githubusercontent.com/66915274/179471690-cfbdbf4b-ab93-4b12-9504-2482712652a3.png">

3 ◦ Pincharemos sobre el siguiente emoticono para agregar una regla de reenvío.

<img width="585" alt="Captura de pantalla 2022-07-18 a las 10 21 24" src="https://user-images.githubusercontent.com/66915274/179471855-913a684d-c7b0-43e2-9e01-d2c954fe75a4.png">

4 ◦ Por último agregaremos el puerto ```4242``` al anfitrión y al invitado. Las IP's no son necesarias. Pincharemos sobre el botón de aceptar para que así se apliquen los cambios.

<img width="588" alt="Captura de pantalla 2022-07-18 a las 10 22 29" src="https://user-images.githubusercontent.com/66915274/179472105-5942b3ec-5c29-4d49-a00e-67f9cde289e8.png">

➤ Una vez habilitados los puertos desde VirtualBox, volvemos a abrir nuestra máquina virtual. Ahora, desde la consola de nuestro equipo real, escribimos ```ssh <tu_nombre__de_usuario>@localhost -p 4242```; nos pedirá la clave del usuario y una vez la introduzcamos ya nos saldrá el login en verde, lo que significa que estamos conectados. A partir de aquí, lo más recomendable es trabajar siempre desde nuestro terminal de la máquina real, ya que así te libras de todos los problemas de lag, parpadeos, lentitud y otros que suele tener la máqina virtual.

<img width="517" alt="Screen Shot 2022-10-27 at 12 40 23 AM" src="https://user-images.githubusercontent.com/66915274/198174777-28f7793b-273b-43ce-b1c2-4a890353cb8c.png">

<img width="566" alt="Screen Shot 2022-10-27 at 12 40 04 AM" src="https://user-images.githubusercontent.com/66915274/198174814-c1873c62-41dd-4c1d-ad2d-f268b2da0e4c.png">

### 4-4 Instalación y configuración de UFW 🔥🧱

1 ◦ Lo primero que debemos hacer el instalar UFW, para ello haremos uso del comando ```sudo apt install ufw``` acto seguido escribiremos una ```y``` para confirmar que deseamos instalarlo y esperaremos a que termine.

<img width="771" alt="Captura de pantalla 2022-07-14 a las 19 28 55" src="https://user-images.githubusercontent.com/66915274/179045920-4a9aec64-b1d7-4785-89a1-4a299aae21a3.png">

<img width="802" alt="Captura de pantalla 2022-07-14 a las 19 29 25" src="https://user-images.githubusercontent.com/66915274/179045994-19cdf6e0-be61-454b-9adc-ba1f9c2dfd84.png">

2 ◦ Una vez instalado debemos habilitarlo , para ello debemos poner el siguiente comando ```sudo ufw enable``` y acto seguido nos debe indicar que el firewall esta activo.

<img width="498" alt="Captura de pantalla 2022-07-14 a las 19 32 57" src="https://user-images.githubusercontent.com/66915274/179046565-307c042b-243e-4224-bcb2-d02859332352.png">

3 ◦ Ahora lo que debemos hacer es que nuestro firewall permita las conexiones que se lleven a cabo mediante el puerto 4242. Lo haremos con el siguiente comando ```sudo ufw allow 4242```.

<img width="514" alt="Captura de pantalla 2022-07-14 a las 19 34 12" src="https://user-images.githubusercontent.com/66915274/179046765-5277ec55-b8e4-4d4f-a617-a2a8758b80a8.png">

4 ◦ Por último comprobaremos que esta todo correctamente configurado mirando el estado de nuestro cortafuegos , en donde ya debe aparecer como permitidas las conexiones mediante el puerto 4242. Para ver el estado daremos uso del comando ```sudo ufw status```.

<img width="575" alt="Captura de pantalla 2022-07-14 a las 19 38 37" src="https://user-images.githubusercontent.com/66915274/179047574-8073045c-6e78-4b6f-8487-cb0f490a2cd0.png">

### 4-5 Configurar contraseña fuerte para sudo 🔒

1 ◦ Crearemos un fichero en la ruta /etc/sudoers.d/ a mi fichero yo le he decidido llamar sudo_config ya que en ese fichero se almacenará la configuración de la contraseña. El comando exacto para crear el fichero es ```touch /etc/sudoers.d/sudo_config```.

<img width="511" alt="Captura de pantalla 2022-07-14 a las 22 00 40" src="https://user-images.githubusercontent.com/66915274/179072822-2f86bd8b-216e-45e4-a15b-8fe3a49149ff.png">

2 ◦ Debemos crear el directorio sudo en la ruta /var/log porque cada comando que ejecutemos con sudo , tanto el input como el output debe quedar almacenado en ese directorio. Para crearlo utilizaremos el comando ```mkdir /var/log/sudo```.

<img width="502" alt="Captura de pantalla 2022-07-14 a las 21 56 53" src="https://user-images.githubusercontent.com/66915274/179072210-ad99e50d-fa57-494b-999d-3a80dd0f7849.png">

3 ◦ Debemos editar el fichero creado en el paso 1. Como he comentado anteriormente puedes utilizar el editor que mas te guste , pero yo dare uso de nano. Comando para editar el fichero:  ```nano /etc/sudoers.d/sudo_config```.

<img width="502" alt="Captura de pantalla 2022-07-14 a las 22 04 10" src="https://user-images.githubusercontent.com/66915274/179073389-5b2a9c16-811c-4133-87c6-479e770c880b.png">

4 ◦ Una vez estamos editando el fichero deberemos introducir los siguientes comandos para cumplir todos los requisitos que pide el subject.

```
Defaults  passwd_tries=3
Defaults  badpass_message="Mensaje de error personalizado"
Defaults  logfile="/var/log/sudo/sudo_config"
Defaults  log_input, log_output
Defaults  iolog_dir="/var/log/sudo"
Defaults  requiretty
Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

➤ Cómo debería verse el fichero.

<img width="1202" alt="Captura de pantalla 2022-07-16 a las 2 03 45" src="https://user-images.githubusercontent.com/66915274/179326003-1fd67295-4be2-47bd-98fc-d5821f5f1c4d.png">

🤔 <b>Qué hace cada comando❓ </b>

<img width="802" alt="Captura de pantalla 2022-07-16 a las 2 04 56" src="https://user-images.githubusercontent.com/66915274/179326915-b374f679-fa2e-4e02-8b38-cdb53c6354a6.png">

### 4-6 Configuración de política de contraseñas fuerte 🔑

1 ◦ El primer paso será editar el fichero login.defs.

<img width="493" alt="Captura de pantalla 2022-07-16 a las 2 54 06" src="https://user-images.githubusercontent.com/66915274/179327943-67432d4a-7042-44ea-96f4-5975556ce4dc.png">

2 ◦ Una vez estemos editando el fichero modificaremos los siguientes parametros: 

➤ PASS_MAX_DAYS 99999 -> PASS_MAX_DAYS 30

➤ PASS_MIN_DAYS 0 -> PASS_MIN_DAYS 2


<img width="802" alt="Captura de pantalla 2022-07-16 a las 3 05 49" src="https://user-images.githubusercontent.com/66915274/179328449-32a40f67-a18d-4f29-993b-94d013cd7670.png">

PASS_MAX_DAYS: Es el tiempo de expiración de la contraseña. El numero corresponde a días.

PASS_MIN_DAYS: El número mínimo de días permitido antes de modificar una contraseña.

PASS_WARN_AGE: El usuario recibira un mensaje de aviso indicando que faltan los dias especificados para que expire su contraseña.

3 ◦ Para poder seguir con la configuración debemos instalar los siguientes paquetes con este comando ```sudo apt install libpam-pwquality``` , acto seguido pondremos ```Y``` para confirmar la instalación y esperaremos a que termine. 

<img width="770" alt="Captura de pantalla 2022-07-16 a las 3 13 52" src="https://user-images.githubusercontent.com/66915274/179328708-c5054703-bdb0-4cca-82a8-6ab25ce42b40.png">

4 ◦ Lo siguiente que debemos hacer es volver a editar un fichero y modificar algunas líneas. Haremos ```nano /etc/pam.d/common-password```. 

<img width="500" alt="Captura de pantalla 2022-07-16 a las 3 27 02" src="https://user-images.githubusercontent.com/66915274/179329260-0e18bd27-a522-4c7c-86bf-21823eee0f8b.png">

5 ◦ Despues de retry=3 debemos añadir los siguientes comandos:

```
minlen=10
ucredit=-1
dcredit=-1
maxrepeat=3
reject_username
difok=7
enforce_for_root
```
➤ Así debe ser la línea ↙️

<img width="1127" alt="Captura de pantalla 2022-07-16 a las 3 34 33" src="https://user-images.githubusercontent.com/66915274/179329511-0619183a-8ccc-456b-8f27-3962fc542cc3.png">

➤ Así se debe ver en el fichero ↙️

<img width="800" alt="Captura de pantalla 2022-07-16 a las 3 38 08" src="https://user-images.githubusercontent.com/66915274/179329787-1b718843-9272-43e4-8d92-8d83933cc938.png">

🤔 <b>Que hace cada comando❓</b>

minlen=10 ➤ La cantidad minima de caracteres que debe contener la contraseña.

ucredit=-1 ➤ Como mínimo debe contener un caracter ```Mayus```. Ponemos el - ya que debe contener como mínimo un caracter, si ponemos + nos referimos a como maximo esos caracteres.

dcredit=-1 ➤Como mínimo debe contener un digito.

maxrepeat=3 ➤ No puede tener más de 3 veces seguidas el mismo caracter.

reject_username ➤ No puede contener el nombre del usuario.

difok=7 ➤  Debe tener al menos 7 caracteres que no sean parte de la antigua contraseña. 

enforce_for_root ➤ Implementaremos esta política para el usuario root.

## 5- Script 🚨

Esta es una parte muy importante del proyecto. Debes prestar atención en todo, muy importante no copiar y pegar directamente el fichero sin saber que hace cada cosa. En la evaluación debes explicar cada comando si el evaluador lo pide.

🧠 <b>Que es un script❓</b> Es una secuencia de comandos guardada en un fichero que cuando se ejecuta hara la funcion de cada comando.

### 5-1 Architecture 

Para poder ver la arquitectura del SO y su versión de kernel utilizaremos el comando ```uname -a``` ( "-a" == "--all" ) que basicamente printara toda la información excepto si el tipo de procesador es desconocido o la plataforma de hardware. 

<img width="715" alt="Screen Shot 2022-10-27 at 4 50 06 PM" src="https://user-images.githubusercontent.com/66915274/198322524-8c2d305f-bfe8-4e4a-bf31-6a883af71ad3.png">

### 5-2 Núcleos físicos

Para poder mostrar el numero de nucleos fisicos haremos uso del fichero /proc/cpuinfo el cual  proporciona información acerca del procesador: su tipo, marca, modelo, rendimiento, etc. Usaremos el comando ```grep "physical id" /proc/cpuinfo | wc -l``` con el comando grep buscaremos dentro del fichero "physical id" y con wc -l contaremos las lineas del resultado de grep. Esto lo hacemos ya que la manera de cuantificar los nucleos no es muy común. Si hay un procesador marcará 0 y si tiene más de un procesador, mostrará toda la información del procesador por separado contando los procesadores usando la notación cero. De esta manera simplemente contaremos las lineas que hay ya que es más cómodo cuantificarlo así.

<img width="596" alt="Screen Shot 2022-10-27 at 4 50 49 PM" src="https://user-images.githubusercontent.com/66915274/198322799-4bf2131e-7fba-4c9e-8d1b-bb9cc1b89e76.png">


### 5-3 Núcleos virtuales

Para poder mostrar el numero de nucleos virtuales es muy parecido al anterior. Haremos uso de nuevo del fichero /proc/cpuinfo , pero, en este caso utilizaremos el comando ```grep processor /proc/cpuinfo | wc -l```. El uso es practicamente el mismo al anterior solo que en vez de contar las lineas de "physical id" lo haremos de processor. Lo hacemos así por el mismo motivo de antes, la manera de cuantificar marca 0 si hay un procesador.

<img width="586" alt="Screen Shot 2022-10-27 at 4 55 48 PM" src="https://user-images.githubusercontent.com/66915274/198324254-3d0f247d-b767-4e02-9e69-11b4e0586280.png">


### 5-4 Memoria RAM

Para mostrar la memoria ram haremos uso del comando ```free``` para así ver al momento información sobre la ram, la parte usada, libre, reservada para otros recursos, etc. Para más info sobre el comando pondremos free --help. Nosotros daremos uso de free --mega ya que en el subject aparece esa unidad de medida.

<img width="672" alt="Captura de pantalla 2022-08-02 a las 2 46 10" src="https://user-images.githubusercontent.com/66915274/182268241-86b743bb-653d-4fef-acda-e7bfa59e38d7.png">

Una vez hemos ejecutado este comando debemos filtrar nuestra busqueda ya que no necesitamos toda la información que nos aporta , lo primero que debemos mostrar es la memoria usada, para ello haremos uso del comando ```awk``` que lo que hace este comando es para procesar datos basados en archivos de texto, es decir, podremos utilizar los datos que nos interesen de X fichero. Por último lo que haremos será comparar si la primera palabra de una fila es igual a "Mem:" printaremos la tercera palabra de esa fila que será la memoria usada. Todo el comando junto seria ```free --mega | awk '$1 == "Mem:" {print $3}'```. En el script el valor de retorno de este comando se lo asignaremos a una variable que concatenaremos con otras variables para que todo quede igual como especifica el subject.

<img width="621" alt="Captura de pantalla 2022-08-02 a las 2 55 21" src="https://user-images.githubusercontent.com/66915274/182269019-d5bb3107-f091-491f-a4ab-27edd357aec8.png">

Para obtener la memoria total el comando es practicamente igual al anterior lo único que deberemos cambiar es que en vez de printar la tercera palabra de la fila queremos la segunda ```free --mega | awk '$1 == "Mem:" {print $2}'```.

<img width="605" alt="Captura de pantalla 2022-08-02 a las 3 00 02" src="https://user-images.githubusercontent.com/66915274/182269450-318816e1-fc71-48b0-a860-278cc6050e05.png">

Por última parte debemos calcular el % de memoria usada. El comando de nuevo es parecido a los anteriores la única modificación que haremos en la parte del printeo. Como la operación para conseguir el tanto porciento no es exacta nos puede dar muchos decimales y en el subject solo aparecen 2 asique nosotros haremos lo mismo, por eso utilizamos ```%.2f``` para que asi solo se muestren 2 decimales. Otra cosa que quizás no sepas es en printf para que se muestre un ```%``` hay que poner ```%%```. Todo el comando ```free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'```.

<img width="798" alt="Captura de pantalla 2022-08-02 a las 3 51 01" src="https://user-images.githubusercontent.com/66915274/182274627-195476b2-1e17-4a4c-8d5c-2056e4e2bbb6.png">

### 5-5 Memoria del disco

Para poder ver la memoria del disco ocupada y disponible utilizaremos el comando ```df``` que significa "disk filesystem" , se utiliza para obtener un resumen completo del uso del espacio en disco. Como en el sibject indica la memoria utilizada se muestra en MB asi que entonces utilizaremos el flag -m. Acto seguido haremos un grep para que solo nos muestre las lineas que contengan "/dev/" y seguidamente volveremos a hacer otro grep con el flag -v para excluir las lineas que contengan "/boot". Por último utilizaremos el comando awk y sumaremos el valor de la tercera palabra de cada linea para una vez sumadas todas las lineas printar el resultado final de la suma. El comando entero es el siguiente: ```df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'```.

<img width="805" alt="Captura de pantalla 2022-08-03 a las 2 26 15" src="https://user-images.githubusercontent.com/66915274/182498837-4f883b25-e316-4c74-8f6b-a5e8b5d13289.png">

Para obtener el espacio total utilizaremos un comando muy parecido. Las unicas diferencias seran que los valores que sumaremos seran los $2 en vez de $3 y la otra diferencia es que en el subject aparece el tamaño total en Gb asique como el resultado de la suma nos da el numero en Mb debemos transformarlo a Gb , para ello debemos dividir el numero entre 1024 y quitar los decimales.

<img width="801" alt="Captura de pantalla 2022-08-03 a las 2 40 55" src="https://user-images.githubusercontent.com/66915274/182500104-0aaa1a6b-cf05-4a82-9c9a-8e163f1c1e98.png">

Por último debemos mostrar un porcentaje de la memoria usada. Para ello , de nuevo, utilizaremos un comando muy parecido a los dos anteriores. Lo unico que cambiaremos es que combinaremos los dos comandos anteriores para tener dos variables , una que representa la memoria usada y la otra la total. Hecho esto haremos una operacion para conseguir el tanto por ciento ```use/total*100``` y el resultado de esta operacion lo printaremos como aparece en el subject , entre parentesis y con el simbolo % al final. El comando final es este: ```df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}'```.

<img width="798" alt="Captura de pantalla 2022-08-03 a las 2 49 33" src="https://user-images.githubusercontent.com/66915274/182500836-dd4b068e-b6ce-4dc6-b832-f90acecfb71c.png">


### 5-6 Porcentaje uso de CPU

Para poder ver el porcentaje de uso de CPU haremos uso del comando ```vmstat``` este muestra estadísticas del sistema, permitiendo obtener un detalle general de los procesos, uso de memoria, actividad de CPU, estado del sistema, etc. Podriamos poner si ninguna opción pero en mi caso pondré un intervalo de segundos de 1 a 4. Tambien daremos uso del comando ```tail -1``` que este lo que nos va a permitir es que solo produzca el output la ultima linea, entonces de las 4 generadas solo se printara la ultima. Por ultimo solo printaremos la palabra 15 que es el uso de memoria disponible. El comando entero es el siguiente: ```vmstat 1 4 | tail -1 | awk '{print %15}'```. El resultado de este comando solo es una parte del resultado final ya que todavia hay que hacer alguna operación en el script para que quede bien. Lo que habria que hacer es a 100 restarle la cantidad que nos ha devuelto nuestro comando, el resultado de esa operación lo printaremos con un decimal y un % al final y ya estaría hecha la operación. 

<img width="580" alt="Captura de pantalla 2022-08-03 a las 0 33 39" src="https://user-images.githubusercontent.com/66915274/182484896-def71bf0-b7eb-49d8-b83b-a019d15f62f1.png">

### 5-7 Último reinicio

Para ver la fecha y hora de nuestro último reinicio haremos uso del comando ```who``` con el flag ```-b``` ya que con ese flag nos mostrará por pantalla el tiempo del último arranque del sistema. Como ya nos ha pasado anteriormente nos muestra más información de la que deseamos asique filtraremos y solo mostraremos lo que nos interesa, para ello haremos uso del comando awk y compararemos si la primera palabra de una linea es "system" se printara por pantalla la tercera palabra de esa linea , un espacio y la cuarta palabra. El comando entero seria el siguiente: ```who -b | awk '$1 == "system" {print $3 " " $4}'```.

<img width="661" alt="Captura de pantalla 2022-08-02 a las 12 24 58" src="https://user-images.githubusercontent.com/66915274/182352895-d985e675-5afc-445a-bcd3-68189702fe70.png">

### 5-8 Uso LVM

Para checkear si LVM esta activo o no haremos uso del comando lsblk , este nos muestra información de todos los dispositivos de bloque (discos duros, SSD, memorias, etc) entre toda la información que proporciona podemos ver lvm en el tipo de gestor. Para este comando haremos un if ya que o printaremos Yes o No. Basicamente la condicion que buscamos sera contar el numero de lineas en las que aparece "lvm" y si hay mas de 0 printamos Yes, si hay 0 se printara No. Todo el comando seria: ```if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi```.

<img width="801" alt="Captura de pantalla 2022-08-02 a las 22 38 43" src="https://user-images.githubusercontent.com/66915274/182468904-3789e22f-dbde-4874-b153-0d86497c55e2.png">

### 5-9 Conexiones TCP

Para mirar el numero de conexiones TCP establecidas. Utilizaremos el comando ```ss``` sustituyendo al ya obsoleto netstat. Filtraremos con el flag ```-ta``` para que solo se muestren las conexiones TCP. Por último haremos un grep para ver las que estan establecidas ya que tambien hay solo de escucha y cerraremos con wc -l para que cuente el numero de lineas. El comando queda tal que asi: ```ss -ta | grep ESTAB | wc -l```. 

<img width="479" alt="Captura de pantalla 2022-08-03 a las 0 53 36" src="https://user-images.githubusercontent.com/66915274/182487028-746244f8-2cda-4dc7-a14c-b2e5a7e0dc51.png">

### 5-10 Número de usuarios

Daremos uso del comando ```users``` que nos mostrará el nombre de los usuarios que hay, sabiendo esto, pondremos wc -w para que cuente la cantidad de palabras que hay en la salida del comando. El comando entero queda así ```users | wc -w```.

<img width="380" alt="Captura de pantalla 2022-08-02 a las 12 33 29" src="https://user-images.githubusercontent.com/66915274/182354436-282547cf-22c8-4b03-9484-6801c0466de7.png">


### 5-11 Dirección IP y MAC

Para obtener la dirección del host haremos uso del comando ```hostname -I``` y para obtener la MAC haremos uso del comando ```ip link``` que se utiliza para mostrar o modificar las interfaces de red. Como aparecen más de una interfaz, IP's etc. Utilizaremos el comando grep para buscar lo que deseamos y asi poder printar por pantalla solo lo que nos piden. Para ello pondremos ```ip link | grep "link/ether" | awk '{print $2}'``` y de esta manera solo printaremos la MAC.

<img width="639" alt="Captura de pantalla 2022-08-02 a las 14 53 14" src="https://user-images.githubusercontent.com/66915274/182379380-8e3b803d-d001-42ae-8aea-467e8c9f3ea9.png">

### 5-12 Número de comandos ejecutados con sudo

Para poder obtener el numero de comandos que son ejecutados con sudo haremos uso del comando jornalctl que este es una herramienta que se encarga de recopilar y administrar los registros del sistema. Acto seguido pondremos ```_COMM=sudo``` par así filtrar las entradas especificando su ruta. En nuestro ponemos ```_COMM``` ya que hace referencia a un script ejecutable. Una vez tengamos filtrada la busqueda y solo aparezcan los registros de sudo todavía deberemos filtrar un poco más ya que cuando incias o cierras sesion de root tambien aparece en el registro, entonces para terminar de filtrar pondremos un ```grep COMMAND``` y asi solo apareceran las lineas de comandos. Por ultimo pondremos ```wc -l``` para que asi nos salgan enumeradas las lineas. El comando entero es el siguiente: ```journalctl _COMM=sudo | grep COMMAND | wc -l)```. Para comprobar que funcione correctamente podemos correr el comando en el terminal, poner un comando que incluya sudo y volver a correr el comando y deberá
incrementar el número de ejecucciones de sudo.

<img width="632" alt="Captura de pantalla 2022-08-02 a las 23 50 39" src="https://user-images.githubusercontent.com/66915274/182479668-949b8eee-81f6-4593-83f4-99053d199f1b.png">

### 5-13 Resultado total del script

⚠️ Recuerda no hacer copia y pega si no sabes el funcionamiento de cada comando ⚠️

```
#!/bin/bash

# ARCH
arch=$(uname -a)

# CPU PHYSICAL
cpuf=$(grep "physical id" /proc/cpuinfo | wc -l)

# CPU VIRTUAL
cpuv=$(grep "processor" /proc/cpuinfo | wc -l)

# RAM
ram_total=$(free --mega | awk '$1 == "Mem:" {print $2}')
ram_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
ram_percent=$(free --mega | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')

# DISK
disk_total=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf ("%.1fGb\n"), disk_t/1024}')
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_percent=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t+= $2} END {printf("%d"), disk_u/disk_t*100}')

# CPU LOAD
cpul=$(vmstat 1 2 | tail -1 | awk '{printf $15}')
cpu_op=$(expr 100 - $cpul)
cpu_fin=$(printf "%.1f" $cpu_op)

# LAST BOOT
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

# LVM USE
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

# TCP CONNEXIONS
tcpc=$(ss -ta | grep ESTAB | wc -l)

# USER LOG
ulog=$(users | wc -w)

# NETWORK
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

# SUDO
cmnd=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

wall "	Architecture: $arch
	CPU physical: $cpuf
	vCPU: $cpuv
	Memory Usage: $ram_use/${ram_total}MB ($ram_percent%)
	Disk Usage: $disk_use/${disk_total} ($disk_percent%)
	CPU load: $cpu_fin%
	Last boot: $lb
	LVM use: $lvmu
	Connections TCP: $tcpc ESTABLISHED
	User log: $ulog
	Network: IP $ip ($mac)
	Sudo: $cmnd cmd"
```
Script visto desde nano ↙️

<img width="911" alt="Captura de pantalla 2022-08-03 a las 3 47 31" src="https://user-images.githubusercontent.com/66915274/182506484-f5a095b8-4751-461e-a114-f8e36b4cfa9a.png">

Resultado tras la ejecución del script ↙️

<img width="796" alt="Captura de pantalla 2022-08-03 a las 3 46 15" src="https://user-images.githubusercontent.com/66915274/182506357-f5466a97-380b-4b6d-9b79-89e01a31498a.png">

## 6- Crontab ⏰ vs SystemD ⌚

Para mostrar en pantalla el script cada 10 minutos, como pide el subject, tenemos varias opciones. En todas las guías que he consultado, l@s compañer@s han usado crontab, pero en mi caso he terminado usando un servicio "personalizado".

En el caso de usar cron, tenemos que editar el fichero crontab con el comando ```sudo crontab -u root -e```. Debemos añadir esta línea justo al final del arhicvo para que el script se ejecute cada 10 minutos: ```*/10 * * * * sh /ruta del script```. 

El problema de usar este método es que el script se va a ejecutar a cada 10 minutos del reloj, es decir, a las 10:00, 10:10, 10:20, 10:30... No son 10 minutos reales desde el momento de iniciar la máquina virtual o logearse, por ejemplo. Esto se puede corregir creando otro script, ```sleep.sh```, para compensar el "desfase". Lo que hace ```sleep``` es que, justo cuando se va a ejecutar ```monitoring``` lo detiene, y hace que espere el tiempo que faltaría para que se cumplan 10 minutos reales desde que se inició el sistema. Por ejemplo; arrancamos sistema a 10:45, ```sleep``` calcula que de la hora de inicio hasta el siguiente multiplo de 10 en el reloj son 05 minutos, así que cuando ```monitoring``` vaya a ejecutarse, lo retrasa esos 5 minutos.

El script sería así () y se incluye al final de crontab así () _tengo que añadirlo, como no he usado este método no lo tengo de momento_

La alternativa que he usado yo es crear un servicio de systemd con un timer. Básicamente se trata de crear dos archivos que se comunican entre si (.service y .timer), ajustar bien el timer y habilitar e iniciar el servicio, como ya hemos hecho antes con otros (como ssh por ejemplo).

