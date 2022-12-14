# Born2beroot-Gu铆a 馃捇

Esta es una gu铆a para instalar/configurar la m谩quina virtual cumpliendo todos los requisitos del subject, incluyendo los bonus. No incluye gu铆a de evaluaci贸n.

# 脥ndice

0. [sgoingfre 馃搧](#0-sgoinfre)
1. [Descargar imagen de la maquina virtual 馃捒](#1-descarga-de-debian)
2. [Instalaci贸n de la maquina 馃洜](#2--instalacion-de-la-maquina-)
3. [Instalaci贸n Debian 馃寑](#3--instalaci贸n-debian-)
	
	3.1 [Particionado manual del disco 馃捑](#31--particionado-manual-del-disco)

4. [Configuraci贸n de la m谩quina virtual 鈿欙笍](#4-configuraci贸n-de-la-m谩quina-virtual-%EF%B8%8F)

	4.1 [Instalaci贸n de sudo y configuraci贸n de usuarios y grupos 馃懁](#41---instalaci贸n-de-sudo-y-configuraci贸n-de-usuarios-y-grupos-)
	
	4.2 [Instalaci贸n y configuraci贸n de SSH 馃摱](#42---instalaci贸n-y-configuraci贸n-ssh-)
	
	4.3 [Conectarse via SSH 馃棧](#4-3-conectarse-via-ssh-)

	4.4 [Instalaci贸n y configuraci贸n de UFW 馃敟馃П](#4-4-instalaci贸n-y-configuraci贸n-de-ufw-)
	
	4.5 [Configurar contrase帽a fuerte para sudo 馃敀](#4-5-configurar-contrase帽a-fuerte-para-sudo-)
	
	4.6 [Configuraci贸n de pol铆tica de contrase帽as fuerte 馃攽](#4-6-configuraci贸n-de-pol铆tica-de-contrase帽as-fuerte-)
	
5. [Script 馃毃](#5--script-)

	5.1 [Resultado total del script 馃啑](#5-13-resultado-total-del-script)
	
6. [Crontab vs Systemd 鈱歖(#6--crontab--vs-systemd-)
7. [Signature.txt 馃摑](#7--signaturetxt-)
8. [Instalaci贸n y configuraci贸n de servicios extra 馃摪](#8--instalaci贸n-y-configuraci贸n-de-servicios-extra-)
	
	8.1 - [Lighttpd](#81---lighttpd)

	8.2 - [MariaDB](#82---mariadb)

	8.3 - [Php y WordPress](#83---php-y-wordpress)

	8.4 - [FTP (File Transfer Protocol)](#84---ftp-file-transfer-protocol)

	8.5 - [NTP (Network Time Protocol)](#85---ntp-network-time-protocol)

## 0. sgoinfre 
Importante tener creada la carpeta en sgoingfre/perso/<tu_login>, y modificar sus permisos (chmod 700)

Aqu铆 vamos a trabajar todo el proyecto, guardaremos la ISO del sistema operativo y el archivo que genera VirtualBox

## 1. Descarga de Debian馃捒
[Click aqui](https://www.debian.org/distrib/index.es.html) para descargar la ISO de Debian desde su web oficial. Seleccionar aquitectra amd64.

## 2- Instalacion de la maquina 馃洜

Para realizar la instalaci贸n se requiere de un software de virtualizaci贸n. En este tutorial haremos uso de [VirtualBox](https://www.virtualbox.org/). Si ya tienes VirtualBox instalado y dispones de la ISO Debian ya podemos empezar con el tutorial.

1 鈼? Debemos abrir VirtualBox y pinchar sobre ```Nueva```

<img width="836" alt="Captura de pantalla 2022-07-13 a las 18 02 05" src="https://user-images.githubusercontent.com/66915274/178779265-38eade6e-2789-4597-89e9-5beca2d3921a.png">

2 鈼? Escogemos el nombre de nuestra m谩quina (born2beroot) y la carpeta donde estar谩 ubicada. Importante introducir la maquina dentro de la carpeta sgoinfre ya que si no la ubicamos ah铆 nos quedaremos sin espacio y fallar谩 la instalaci贸n (dependiendo del campus la ruta de sgoinfre puede cambiar). 

<img width="928" alt="Screen Shot 2022-10-23 at 2 57 11 PM" src="https://user-images.githubusercontent.com/66915274/197393458-dda8da5f-2362-4d36-b740-0951ebf03d3c.png">

3 鈼? Dejamos la cantidad de memoria RAM que reservaremos para la m谩quina c贸mo est谩 por defecto (1024). 

<img width="685" alt="Captura de pantalla 2022-07-13 a las 13 06 05" src="https://user-images.githubusercontent.com/66915274/178781098-8aa07fbc-e1d2-4bee-8021-ddf052880364.png">

4 鈼? Seleccionamos la segunda opci贸n para asi crear un disco duro virtual ahora.

<img width="826" alt="Captura de pantalla 2022-07-13 a las 18 13 24" src="https://user-images.githubusercontent.com/66915274/178781390-289236e0-1732-4dd8-8d3d-34eb0a229a18.png">

5 鈼? Escogemos la primera opci贸n ```VDI``` ya que nos hemos descargado una imagen de disco.

<img width="829" alt="Captura de pantalla 2022-07-13 a las 18 16 35" src="https://user-images.githubusercontent.com/66915274/178781999-a42c3c6c-bc1e-4ad5-8bc5-b4b3f811c3f2.png">

6 鈼? Seleccionamos la primera opci贸n ```Reservado din谩micamente``` para que asi se vaya reservando memoria en la m谩quina real segun vayamos utilizandola en la virtual hasta llegado al l铆mite m谩ximo disponible en la virtual.

<img width="833" alt="Captura de pantalla 2022-07-13 a las 18 19 33" src="https://user-images.githubusercontent.com/66915274/178782529-fb309739-3169-4e20-b3e1-23d17a122a18.png">

7 鈼? Seleccionamos el tama帽o de disco, no es importante, el ejemplo de 30Gb del bonus en el subject es solo eso, un ejemplo. Luego deberemos darle a ```Crear```.

<img width="835" alt="Captura de pantalla 2022-07-13 a las 18 25 20" src="https://user-images.githubusercontent.com/66915274/178783666-4fa624a3-9c38-4c45-b6a8-d476c2864200.png">

8 鈼? Ahora vamos a selecionar la imagen ISO para instalar el SO. Debemos darle a ```configuraci贸n```

<img width="831" alt="Captura de pantalla 2022-07-13 a las 18 30 46" src="https://user-images.githubusercontent.com/66915274/178784822-38228e96-ca37-4cc0-b3ca-551829e4c8c8.png">

9 鈼? Acto seguido pincharemos encima de ```Almacenamiento``` , volveremos a pinchar sobre el emoticono 馃捒 que se encuentra a la derecha y de nuevo pincharemos sobre ```Seleccionar un archivo de disco```.

<img width="962" alt="Captura de pantalla 2022-07-13 a las 18 33 28" src="https://user-images.githubusercontent.com/66915274/178785148-2904cf4f-93c0-4866-a5d6-778390bddeb7.png">

10 鈼? Seleccionaremos la ISO que hab铆amos descargado, ```Abrir``` y despu茅s ```Aceptar```. 

<img width="790" alt="Captura de pantalla 2022-07-13 a las 18 38 39" src="https://user-images.githubusercontent.com/66915274/178786115-24f93fde-bc01-4e60-bf8d-20d7a5ae83be.png">

11 鈼? Una vez completados todos los pasos anteriores ya podemos ```Iniciar``` nuestra m谩quina virtual.

鉂椻潡 Posibles problemas al ejecutar la m谩quina virtual 鉂椻潡

 鈼? Teclas se pulsan repetidas veces: es por redimensionar (scale factor) la pantalla de la m谩quina virtual por encima del 150%, hay que bajarlo a ese valor como m谩ximo. 

 鈼? Lag/delay de la m谩quina virtual: en teor铆a, asignar m谩s memoria RAM a la m谩quina virtual, desde la configuraci贸n en VirtualBox, deber铆a solucionar este problema, aunque a mi nunca ha llegado a funcionar completamente fluida.

 鈼? "Parpadeao" de la pantalla en la terminal de la m谩quina virtual: esto es normal, le pasa a casi todos los compa帽eros, no he encontrado soluci贸n, mejor conectar por ssh lo antes posible y dejar de lado la terminal de la m谩quina virtual.

## 3- Instalaci贸n Debian 馃寑

1 鈼? Escogeremos la version sin interfaz gr谩fica ```Install``` ya que el subject indica que no se utilice interfaz gr谩fica

<img width="632" alt="Captura de pantalla 2022-07-13 a las 18 58 48" src="https://user-images.githubusercontent.com/66915274/178789643-e987c6d0-5b6f-4b98-ad4a-5c092a352183.png">

2 鈼? Escogeremos el idioma que usaremos para la instalaci贸n y el predeterminado que se le quedar谩 al sistema ```English```.  

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 00 41" src="https://user-images.githubusercontent.com/66915274/178789949-4fe83ac8-23b8-4f82-a034-a6d5e81d4f17.png">

3 鈼? Introducimos nuestro Pa铆s, territorio o zona. En mi caso pondre ```Other```.

<img width="791" alt="Captura de pantalla 2022-07-13 a las 19 07 50" src="https://user-images.githubusercontent.com/66915274/178791067-44230a4c-e647-46cb-9d6f-bc441bf0227b.png">

4 鈼? Como he seleccionado other debo indicar mi continente o region. En mi caso pongo ```Europe``` 馃嚜馃嚭. 

<img width="797" alt="Captura de pantalla 2022-07-13 a las 19 09 58" src="https://user-images.githubusercontent.com/66915274/178791387-78171f90-2834-42ab-aedb-9cf900d0ecd5.png">

5 鈼? Seleccionamos el pa铆s. En mi caso ```Spain``` 馃嚜馃嚫.

<img width="793" alt="Captura de pantalla 2022-07-13 a las 19 12 01" src="https://user-images.githubusercontent.com/66915274/178791824-7a34813c-eae9-4b5c-9873-cea158229e07.png">

6 鈼? Seleccionamos ```United States```.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 13 43" src="https://user-images.githubusercontent.com/66915274/178792054-4e72dfdd-8175-48f9-a06d-f2696fa752e3.png">

7 鈼? Configurarci贸n teclado: si te aparece la opci贸n (a mi en la 煤ltima versi贸n que use no me aperecia) selecciona ```Spanish```, para no volverte loco despu茅s con el teclado...
Si no te queda otra, selecciona ```American English```.

<img width="793" alt="Captura de pantalla 2022-07-13 a las 19 02 21" src="https://user-images.githubusercontent.com/66915274/178790230-d2571d4f-a546-4b43-bd44-c6a591d92d72.png">

8 鈼? En este paso debemos elegir el ```Host Name``` de la m谩quina, el cual debe ser tu login seguido de 42. 

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 17 23" src="https://user-images.githubusercontent.com/66915274/178792607-1cc585eb-ae32-4b2c-97fd-4fcf5bad4262.png">

9 鈼? ```Domain name```: lo dejamos en blanco, no se especifica nada en el subject.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 19 20 29" src="https://user-images.githubusercontent.com/66915274/178793113-b0934aac-fac4-4844-8412-aca124038fd0.png">

10 鈼? Debemos introducir una contrase帽a para la cuenta de administraci贸n del sistema. Importante apuntarla o hacer una foto ya que le daremos uso. Si quieres ver la contrase帽a para asegurarte de que la has escrito correctamente debes tabular hasta llegar a la opci贸n ```Show Password in Clear``` debes darle a la barra espaciadora y se mostrara la clave. Nos pedir谩 volver a introducirla para confirmar.

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 21 29" src="https://user-images.githubusercontent.com/66915274/178793296-c2c3b6c5-9744-4ba8-ac32-8e3c21c44f9b.png">

12 鈼? Nombre de nuestro nuevo usuario, debe ser nuestro nuestro login de 42. Nos pedir谩 introducirlo dos veces.

<img width="794" alt="Captura de pantalla 2022-07-13 a las 19 26 20" src="https://user-images.githubusercontent.com/66915274/178794178-901f7951-a978-458d-a925-4586026784f7.png">

13 鈼? Ahora debemos introducir la contrase帽a de nuestro nuevo usuario. Como la anterior , repetiremos el proceso para comprobar que no la hayas escrito mal y tambien es importante que la guardes porque le daremos uso m谩s adelante. Yo personalmente he usado siempre la misma contrase帽a para todas las situaciones en las que nos piden establecer una.

<img width="790" alt="Captura de pantalla 2022-07-13 a las 19 30 08" src="https://user-images.githubusercontent.com/66915274/178794862-94de8c7a-282e-4a83-9903-d3b8439122ea.png">

14 鈼? Seleccionamos la hora de nuestra ubicaci贸n.

<img width="796" alt="Captura de pantalla 2022-07-13 a las 19 31 41" src="https://user-images.githubusercontent.com/66915274/178795105-956854e1-deff-4851-8eba-26cdefb1e06f.png">

15 鈼? Vamos a hacer las particiones de forma manual, para hacer el bonus. Esocgeremos la opci贸n ```Manual```.

### 3.1- Particionado manual del disco

1 鈼? En el momento de escoger el particionado de disco seleccionaremos manual. De esta manera podremos editar las particiones una a una.

<img width="789" alt="Screen Shot 2022-10-23 at 4 30 48 PM" src="https://user-images.githubusercontent.com/66915274/197397840-b6ae9d65-a6aa-4a5d-a03f-856d9ce81644.png">

2 鈼? En este apartado nos muestra una descripci贸n general de nuestras particiones y puntos de montaje. Actualmente no tenemos particiones hechas. Para crear una nueva tabla de particiones debemos escoger el dispositivo donde queremos crearlas. En nuestro caso escogeremos el 煤nico disponible.

<img width="793" alt="Screen Shot 2022-10-23 at 4 35 39 PM" src="https://user-images.githubusercontent.com/66915274/197398114-44abc561-d34d-47c9-b512-581b4ec6fddb.png">

3 鈼? Aceptamos el mensaje de confirmaci贸n. B谩sicamente nos avisa que si ya hay particiones en el dispositivo seran eliminadas y que si estamos seguros de crear una nueva tabla de particiones vac铆a..

<img width="770" alt="Screen Shot 2022-10-23 at 4 36 08 PM" src="https://user-images.githubusercontent.com/66915274/197398137-b9fe1f96-5907-462e-8a50-44b71ae2aefe.png">

4 鈼? Una vez hemos completado el paso anterior podemos ver como nos aparece nuestra tabla de particiones vac铆a. Ahora debemos configurarla , para ello debemos seleccionarla.

<img width="786" alt="Screen Shot 2022-10-23 at 4 36 35 PM" src="https://user-images.githubusercontent.com/66915274/197398172-b05fa7aa-e5b4-40cb-afd4-03a1404d7885.png">

5 鈼? Crearemos una nueva partici贸n.

<img width="512" alt="Screen Shot 2022-10-23 at 4 36 54 PM" src="https://user-images.githubusercontent.com/66915274/197398199-70570553-de1b-49a9-8c44-da9a1e4b5c1e.png">

Empezaremos creando esta:

![image](https://user-images.githubusercontent.com/66915274/197427077-48636236-4012-4edf-b0e4-319db502e685.png)

6 鈼? Como bien indica el subject el tama帽o de la partici贸n debe ser de 500 megabytes.

<img width="777" alt="Screen Shot 2022-10-23 at 4 37 27 PM" src="https://user-images.githubusercontent.com/66915274/197398241-604b2bb2-7303-412a-b382-40bfbf443ed0.png">

7 鈼? Escogemos el tipo de la partici贸n. Escogemos primaria ya que ser谩 la partici贸n donde se encontrar谩 instalado el Sistema Operativo.

<img width="457" alt="Screen Shot 2022-10-23 at 4 37 38 PM" src="https://user-images.githubusercontent.com/66915274/197398253-2c0f8205-3d3f-4ab7-94a3-70c37ee014d9.png">

8 鈼? Seleccionaremos beginning ya que queremos que la nueva partici贸n se cree al principio del espacio disponible.

<img width="787" alt="Screen Shot 2022-10-23 at 4 37 52 PM" src="https://user-images.githubusercontent.com/66915274/197398265-c63d7b32-55b7-45ad-86b3-166e44cfd598.png">

9 鈼? En la siguiente captura nos muestra los detalles de la partici贸n. Modificaremos el punto de montaje al que escifica el subject.

<img width="781" alt="Screen Shot 2022-10-23 at 4 38 27 PM" src="https://user-images.githubusercontent.com/66915274/197398293-2487ded0-2584-48c4-a5ea-1f2464ec39f9.png">

10 鈼? Escogemos boot como el punto de montaje de nuestra partici贸n.

<img width="577" alt="Screen Shot 2022-10-23 at 4 38 49 PM" src="https://user-images.githubusercontent.com/66915274/197398322-51b9854b-ab32-4d81-8126-3ef3913858a6.png">

11 鈼? Terminamos de configurar la partici贸n actual.

<img width="787" alt="Screen Shot 2022-10-23 at 4 39 07 PM" src="https://user-images.githubusercontent.com/66915274/197398336-72b17153-73dc-48a5-b7d3-839877e8983b.png">

12 鈼? Una vez hemos completado el paso anterior ya nos debe aparecer la partici贸n. Ahora debemos crear una partici贸n l贸gica con todo el espacio disponible del disco, que no tenga punto de montaje y que este encriptada. Para ello seleccionamos el espacio libre donde queremos crearla.

<img width="781" alt="Screen Shot 2022-10-23 at 4 39 37 PM" src="https://user-images.githubusercontent.com/66915274/197398367-ee8a1f5d-3941-4a86-a775-90f29b1c955e.png">

![image](https://user-images.githubusercontent.com/66915274/197431553-718358bb-6570-41dd-b114-09acc347999d.png)

13 鈼? Creamos nueva partici贸n.

<img width="462" alt="Screen Shot 2022-10-23 at 4 39 58 PM" src="https://user-images.githubusercontent.com/66915274/197398396-843c7fb3-b945-4305-a960-02aa9d4ca940.png">

14 鈼? Seleccionamos el tama帽o m谩ximo.

<img width="779" alt="Screen Shot 2022-10-23 at 4 40 26 PM" src="https://user-images.githubusercontent.com/66915274/197398425-63205376-839f-4986-a8d0-981cdaa380e4.png">

15 鈼? Seleccionamos el tipo de particion, en este caso l贸gica.

<img width="466" alt="Screen Shot 2022-10-23 at 4 40 53 PM" src="https://user-images.githubusercontent.com/66915274/197398448-49c99180-9a3d-4dd4-a9ce-d680bfdefa1c.png">

16 鈼? Modificaremos el punto de montaje.

<img width="788" alt="Screen Shot 2022-10-23 at 4 41 44 PM" src="https://user-images.githubusercontent.com/66915274/197398500-188cc4fb-4eb5-4a56-893b-58838877c056.png">

17 鈼? Escogeremos la opci贸n de no montarlo.

<img width="590" alt="Screen Shot 2022-10-23 at 4 42 11 PM" src="https://user-images.githubusercontent.com/66915274/197398518-f6fb7588-8c53-40a9-9ceb-238d6a62d942.png">

18 鈼? Terminamos de configurar la partici贸n actual.

<img width="788" alt="Screen Shot 2022-10-23 at 4 42 41 PM" src="https://user-images.githubusercontent.com/66915274/197398541-922f2c4d-ed5a-4d92-8083-ccf57aec3dee.png">

19 鈼? Configuraremos vol煤menes encriptados. Para asi poder encriptar nuestra partici贸n.

<img width="786" alt="Screen Shot 2022-10-23 at 4 43 08 PM" src="https://user-images.githubusercontent.com/66915274/197398562-2369fa90-7db9-4ba3-abed-7ac15ede8b81.png">

20 鈼? Aceptamos el mensaje de confirmaci贸n.

<img width="777" alt="Screen Shot 2022-10-23 at 4 43 27 PM" src="https://user-images.githubusercontent.com/66915274/197398573-9720e351-04f4-49f0-a3dc-fe0ce1ada296.png">

21 鈼? Creamos los vol煤menes encriptados.

<img width="596" alt="Screen Shot 2022-10-23 at 4 43 46 PM" src="https://user-images.githubusercontent.com/66915274/197398595-b36ab8da-86c6-483a-99fd-079293a92570.png">

22 鈼? Seleccionamos en que partici贸n queremos realizar la encriptaci贸n.

<img width="568" alt="Screen Shot 2022-10-23 at 4 44 06 PM" src="https://user-images.githubusercontent.com/66915274/197398615-7c9f8e45-7885-4f39-84eb-e3a056eeb2c7.png">

23 鈼? Terminamos de configurar la partici贸n actual.

<img width="787" alt="Screen Shot 2022-10-23 at 4 44 35 PM" src="https://user-images.githubusercontent.com/66915274/197398649-06749ec8-903d-4b1a-af2a-c2dad77bcaec.png">

24 鈼? Finalizamos ya que no queremos crear mas vol煤menes encriptados.

<img width="589" alt="Screen Shot 2022-10-23 at 4 44 49 PM" src="https://user-images.githubusercontent.com/66915274/197398663-0bd74c65-b3fd-430c-b3e6-4f1e0c76ae8d.png">

25 鈼? Aceptamos el mensaje de confirmaci贸n. Nos comenta que que se encriptara todo lo que hay dentro de la partici贸n y que no debe tardar mucho en terminar.

<img width="783" alt="Screen Shot 2022-10-23 at 4 45 06 PM" src="https://user-images.githubusercontent.com/66915274/197398670-91db3e3e-b271-4e1b-ad8a-28ceb06e0897.png">

26 鈼? (Opcional) Le damos a cancel para saltar el paso; no hay nada que encriptar ya que la partici贸n esta vac铆a.

<img width="789" alt="Screen Shot 2022-10-23 at 4 45 27 PM" src="https://user-images.githubusercontent.com/66915274/197398685-6603ef31-d499-46da-949f-ade8e2a05bf9.png">

27 鈼? De nuevo deberemos poner una contrase帽a, esta vez ser谩 la frase de encriptaci贸n. Como te he comentado previamente deber谩s repetir el proceso y la debes anotar ya que ser谩 importante en un futuro.

<img width="779" alt="Screen Shot 2022-10-23 at 4 48 38 PM" src="https://user-images.githubusercontent.com/66915274/197398855-0c93f419-897e-4eee-9499-18321d8e8dfd.png">

28 鈼? Repetimos la frase de encriptaci贸n.

<img width="722" alt="Screen Shot 2022-10-23 at 4 49 01 PM" src="https://user-images.githubusercontent.com/66915274/197398875-3fa85638-7105-42bf-bbc2-e189fbbc1918.png">

29 鈼? Configuraremos el gestor de volumenes logicos. 

<img width="785" alt="Screen Shot 2022-10-23 at 4 50 17 PM" src="https://user-images.githubusercontent.com/66915274/197398933-85e0025e-0a4d-41f0-8fd0-5f0c8ee32e9b.png">

30 鈼? Aceptaremos en mensaje de confirmaci贸n ya que estamos de acuerdo con que se guarden los cambion en el disco.

<img width="786" alt="Screen Shot 2022-10-23 at 4 50 42 PM" src="https://user-images.githubusercontent.com/66915274/197398945-d79ea2a7-a13e-4e6a-9e9c-40bdcd2dd502.png">

31 鈼? Crearemos un nuevo grupo de volumen. Los grupos de vol煤menes agrupan particiones.

<img width="454" alt="Screen Shot 2022-10-23 at 4 52 04 PM" src="https://user-images.githubusercontent.com/66915274/197399021-29b21274-37c1-4fd9-8526-962969d1cce3.png">

32 鈼? Introduciremos el nombre que queremos darle. ```LVMGroup``` tal y como indica el subject.

<img width="695" alt="Screen Shot 2022-10-23 at 4 52 58 PM" src="https://user-images.githubusercontent.com/66915274/197399065-1ac8d80d-9e18-4b4a-a60f-11496e7de26d.png">

33 鈼? Seleccionaremos la partici贸n donde queremos cear el grupo. 

<img width="590" alt="Screen Shot 2022-10-23 at 4 53 22 PM" src="https://user-images.githubusercontent.com/66915274/197399089-5ea5f48e-176c-4278-8b14-a13b7f5ee45c.png">

34 鈼? Ahora debemos crear todas las particiones l贸gicas. Dejo captura de los tama帽os que he usado yo para cada una en una m谩quina de 12Gb , ya que VirtualBox no me permit铆a asginarle 30Gb de disco a mi m谩quina (como el ejemplo del subject), no es necesario un tama帽o en concreto.

<img width="690" alt="Screen Shot 2022-11-08 at 8 49 05 AM" src="https://user-images.githubusercontent.com/115219064/200511370-1f1d732f-f9fc-408a-b632-915bd428a9ad.png">

El orden de la creaci贸n de las unidades l贸gicas ser谩 el mismo que indica el subject; empezamos por root y terminamos con var-log. Solo aparecen capturas de la creaci贸n de la primera unidad para que se refleje el proceso (ignorad el tama帽o que se usa en la captura), las dem谩s las haremos igual, simplemente cambiando nombre y tama帽o.

<img width="457" alt="Screen Shot 2022-10-23 at 4 53 50 PM" src="https://user-images.githubusercontent.com/66915274/197399108-fb566eb4-664f-4509-8948-ab4ed04407b5.png">

35 鈼? Empezaremos escogiendo el grupo donde queremos que se creen. Seleccionamos el 煤nico disponible (el que acabamos de crear - LVM). 

<img width="760" alt="Screen Shot 2022-10-23 at 4 54 02 PM" src="https://user-images.githubusercontent.com/66915274/197399115-e7d3b313-763c-421c-a71d-850d318432e7.png">

36 鈼? Empezamos por ```root```; seleccionaremos el nombre del volumen l贸gico.

<img width="662" alt="Screen Shot 2022-10-23 at 4 55 42 PM" src="https://user-images.githubusercontent.com/66915274/197399188-6ae8c83b-057d-498f-b112-9116079b0808.png">

37 鈼? Tama帽o, en mi caso ser谩 de 4g. De nuevo, no es importante que cumpla un tama帽o espec铆fico, si en tu caso has asignado m谩s o menos disco a tu m谩quina, ahora asignara espacio a cada unidad en proporci贸n y listo. Lo siguientes paso dejo de ejemplo los tama帽os que he usado yo para la m谩quina de 12Gb.

<img width="782" alt="Screen Shot 2022-10-23 at 4 56 21 PM" src="https://user-images.githubusercontent.com/66915274/197399216-c65f43ca-fb8e-4d05-9212-24ad2ee87b39.png">

38 鈼? Repetimos el proceso para ```swap``` y le asignamos size ```1g```.

39 鈼? Repetimos el proceso para ```home``` y le asignamos size ```2g```.

40 鈼? Repetimos el proceso para ```var``` y le asigno size ```1.2g```.

41 鈼? Repetimos el proceso para ```srv``` y le asigno size ```1.2g```.

42 鈼? Repetimos el proceso para ```tmp``` y le asigno size ```1.2g```.

43 鈼? Repetimos el proceso para ```var-log``` y le asigno size ```1.4g```.

44 鈼? Una vez hayamos completado todos los pasos anteriores finalizaremos la configuraci贸n del gestor de vol煤menes l贸gicos.

<img width="438" alt="Screen Shot 2022-10-23 at 5 09 51 PM" src="https://user-images.githubusercontent.com/66915274/197399904-c584fcdf-eb38-486f-af12-7374f1e04465.png">

45 鈼? Ahora debemos configurar todas las unidades para seleccionar el sistema de archivos que usar谩n y su punto de montaje de acuerdo a las indicaciones del subject. Lo haremos en el orden que aparecen, todas usaran el sistema de archivos Ext4 (menos swap) y como punto de montaje, el que coincide con el nombre de la unidad (en el caso de var-log, tenemos que introducirlo "manualmente").

<img width="783" alt="Screen Shot 2022-10-23 at 5 10 36 PM" src="https://user-images.githubusercontent.com/66915274/197399944-bccbe599-b80a-4abe-ac6c-d770447ea727.png">

46 鈼? Comenzamos por ```home```. Vamos a ver el proceso completo aqu铆, para las dem谩s especifico los cambios y dejo solo captura de las excepciones en swap y en var-log. Lo primero es seleccionar ```Use as: do not use``` para poder elegir el sistema de archivos.

<img width="782" alt="Screen Shot 2022-10-23 at 5 10 55 PM" src="https://user-images.githubusercontent.com/66915274/197399976-9b871bda-9425-4dbe-b8c9-25c8c6d6c811.png">

47 鈼? Escogemos el sistema de archivos Ext4, es el sistema de archivos m谩s utilizado en distribuciones Linux.  

<img width="412" alt="Screen Shot 2022-10-23 at 5 11 18 PM" src="https://user-images.githubusercontent.com/66915274/197400000-2e855fc9-10b1-4f3e-9c58-85b6ff02a4fb.png">

48 鈼? Una vez hayamos elegido sistema de archivos, nos aparecer谩n m谩s opciones para configurar. Ahora debemos seleccionar el punto de montaje. 

<img width="782" alt="Screen Shot 2022-10-23 at 5 11 44 PM" src="https://user-images.githubusercontent.com/66915274/197400023-387a70aa-b491-43c0-91d2-cb378da9fc75.png">

49 鈼? Seleccionamos ```home``` como bien indica el subject.

<img width="515" alt="Screen Shot 2022-10-23 at 5 11 54 PM" src="https://user-images.githubusercontent.com/66915274/197400040-e79cad4f-368b-4cee-9ec0-942f38b2f785.png">

50 鈼? Una vez ya lo hemos seleccionado terminaremos la configuraci贸n de la partici贸n.

<img width="785" alt="Screen Shot 2022-10-23 at 5 12 10 PM" src="https://user-images.githubusercontent.com/66915274/197400059-ab96f2c4-cd92-47cb-a9ee-61257537ee6a.png">

51 鈼? Repetimos mismo proceso para ```root```, pero para su punto de montaje escojemos la opci贸n ```/```.

52 鈼? Repetimos el proceso para ```srv``` y cambiaremos su punto de montaje a ```srv```.

53 鈼? Para ```swap``` haremos una excepci贸n ya el sistema de archivos ser谩 diferente. 

54 鈼? En el momento de seleccionar el sistema de archivos lo dejamos en ```swap area```. No tendremos que asignar un punto de montaje para swap.

<img width="370" alt="Screen Shot 2022-10-23 at 5 16 59 PM" src="https://user-images.githubusercontent.com/66915274/197400297-8eed129d-0ec0-49a8-8b2a-dd0d04055f75.png">

55 鈼? Una vez realizado el paso anterior terminaremos la configuraci贸n de la partici贸n.

56 鈼? Seguimos con ```tmp```, aqu铆 si volvemos a repetir el proceso "estandar", le asignamos ```tmp``` como punto de montaje.

57 鈼? Repetimos de nuevo el proceso para ```var``` con su respectivo punto de montaje.

58 鈼? Por 煤ltimo, seleccionamos ```var-log```, en este caso deberemos introducir manualmente el punto de montaje ```/var/log```.

![image](https://user-images.githubusercontent.com/66915274/197602673-5c18be85-1b0f-430b-b507-66711b807115.png)

![image](https://user-images.githubusercontent.com/66915274/197602699-fddadd2d-c54d-4313-8165-a93db1249b26.png)

59 鈼? Una vez hemos completado todos los pasos anteriores ya casi hemos acabado, debemos darle a finalizar el particionado para que se guarden todos los cambios en el disco.

![image](https://user-images.githubusercontent.com/66915274/197602907-4a3ba459-1a5d-468e-81dc-5206403cf034.png)

60 鈼? Aceptamos el mensaje y asi se guardaran los cambios. Asegurate que todas las particiones quedan igual que en la captura.

![image](https://user-images.githubusercontent.com/66915274/197602944-13ca67b2-bcc5-476c-84dc-aadc5e1d3baf.png)

61 鈼? Seleccionamos la opci贸n ```No``` ya que no necesitamos paquetes adicionales. 

<img width="770" alt="Captura de pantalla 2022-07-13 a las 20 05 42" src="https://user-images.githubusercontent.com/66915274/178801099-2dda24f5-0d46-4184-8c44-a8fe0bf46527.png">

62 鈼? Escogemos nuestro Pa铆s.

<img width="756" alt="Captura de pantalla 2022-07-13 a las 20 14 23" src="https://user-images.githubusercontent.com/66915274/178802653-d9e8504a-b60b-4441-8ee3-8d48ca4a6bf0.png">

63 鈼? Escogemos ```deb.debian.org``` ya que tenindo en cuenta nuestra region es donde tendremos una mejor conexi贸n.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 15 00" src="https://user-images.githubusercontent.com/66915274/178802772-4f67cd99-60d5-4439-8502-317e81e07d70.png">

64 鈼? Esta opci贸n la dejaremos vac铆a le daremos directamente a ```Continue```.

<img width="797" alt="Captura de pantalla 2022-07-13 a las 20 17 24" src="https://user-images.githubusercontent.com/66915274/178803208-2969acae-3fa7-423e-8a3c-bb7c76eff824.png">

65 鈼? Seleccionamos la opcion ```No``` ya que no queremos que los developers vean nuestras estad铆sticas aunque sean an贸nimas.

<img width="796" alt="Captura de pantalla 2022-07-13 a las 20 21 54" src="https://user-images.githubusercontent.com/66915274/178803926-a4efbc70-f3e2-4e6c-9809-9152478d8237.png">

66 鈼? Quitaremos todas las opciones de software (con la barra espaciadora) y le daremos a ```Continue```.

<img width="797" alt="Captura de pantalla 2022-07-13 a las 20 24 17" src="https://user-images.githubusercontent.com/66915274/178804377-e775b89e-93d4-482f-a4d0-0ef126f47719.png">

67 鈼? Seleccionaremos ```Yes``` para instalar [GRUB boot](https://es.wikipedia.org/wiki/GNU_GRUB) en el disco duro.

<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 26 24" src="https://user-images.githubusercontent.com/66915274/178804771-ba16e0b7-9f06-4c5b-9451-0bfd65efd2bb.png">

68 鈼? Escogeremos el dispositivo para la instalaci贸n del cargador de arranque ```/dev/sda (ata_VBOX_HARDDISK)```. Ahora la pantalla puede quedar completamente azul, sin nada, mientras empieza la instalaci贸n y puede que est茅 as铆 varios minutos... no pasa nada, es normal.
<img width="792" alt="Captura de pantalla 2022-07-13 a las 20 35 46" src="https://user-images.githubusercontent.com/66915274/178806441-f1bf3159-4e09-4c9a-9102-b3261c9000d8.png">

69 鈼? Le daremos a ```Continue``` para finalizar la instalaci贸n. 

<img width="794" alt="Captura de pantalla 2022-07-13 a las 20 39 30" src="https://user-images.githubusercontent.com/66915274/178807102-e2a9722e-791f-48a0-ae35-b05b36a37ed2.png">

## 4 Configuraci贸n de la m谩quina virtual 鈿欙笍

鉃? ```Start``` desde VirtualBox.

鉃? Lo primero que nos va a aparece es el boot selector (GRUB boot loader), podemos seleccionar ```Debian GNU/Linux``` o esperar unos segundos y se seleccionara por defecto.

鉃? Nos pedir谩 la contrase帽a de encriptaci贸n que establecimos durante la instalaci贸n previamente.

<img width="714" alt="Captura de pantalla 2022-07-13 a las 20 47 26" src="https://user-images.githubusercontent.com/66915274/178808699-f1024129-5f90-41d0-a9a8-4806f5bc114b.png">

鉃? Debemos introducir el usuario y contrase帽a que hab铆amos creado antes.

<img width="798" alt="Captura de pantalla 2022-07-13 a las 20 48 38" src="https://user-images.githubusercontent.com/66915274/178808994-664025ac-36df-4332-8e44-505ecd2ca305.png">

### Ya tenemos todo listo para empezar a configurar nuestra m谩quina virtual Debian鉂楋笍

### 4.1 - Instalaci贸n de sudo y configuraci贸n de usuarios y grupos 馃懁

1 鈼? Para la instalaci贸n de sudo primero debemos estar en el usuario root, para ello pondremos ```su``` en el terminal e introduciremos la contrase帽a root (la establecimos durante la instalaci贸n). Una vez hemos accedido al usuario root, debemos usar el comando ```apt install sudo```, comienzan a instalarse los paquetes necesarios.

<img width="796" alt="Captura de pantalla 2022-07-14 a las 1 36 46" src="https://user-images.githubusercontent.com/66915274/178855273-fc76689c-224b-4368-b7b1-5d1954427aff.png">

2 鈼? Debemos reiniciar la m谩quina para que se apliquen los cambios. Para ello haremos uso del comando ```sudo reboot``` y esperaremos a que se reinicie. 

<img width="514" alt="Captura de pantalla 2022-07-14 a las 2 02 24" src="https://user-images.githubusercontent.com/66915274/178857108-a51988e1-084c-498c-86c6-98ab5a3b1305.png">

3 鈼? Una vez reiniciado debemos volver a introducir las contrase帽as de cifrado y del usuario. Para verificar que hayamos instalado ```sudo``` correctamente entraremos de nuevo en el usuario root y pondremos el comando ```sudo -V```, este comando adem谩s de mostrarnos la versi贸n de sudo tambi茅n mostrar谩 los argumentos pasados para configurar cuando se cre贸 sudo y los plugins que  pueden mostrar informaci贸n m谩s detallada. (Opcional) 鉃? Puesto que el output del comando es muy largo si deseamos verlo completamente debemos redireccionar la salida del mismo a un fichero ```sudo -V > file.txt``` y luego editar el fichero ```nano file.txt```. O poner ```| more``` despues del comando.

<img width="799" alt="Captura de pantalla 2022-07-14 a las 2 09 59" src="https://user-images.githubusercontent.com/66915274/178857742-96356272-abd6-44c4-a3e6-5e8b9f471146.png">

4 鈼? Siguiendo en el usuario root crearemos un usuario con nuestro login con el comando ```sudo adduser login``` como nostros ya hemos creado el usuario en la instalaci贸n nos debe aparecer que el usuario ya existe.

<img width="509" alt="Captura de pantalla 2022-07-14 a las 2 15 11" src="https://user-images.githubusercontent.com/66915274/178858240-95ce2a2b-004a-4bcb-981a-7990c1cc4fdd.png">

5 鈼? Ahora deberemos crear un nuevo grupo llamado ```user42```. Para crearlo debemos hacer ```sudo addgroup user42```. 

<img width="367" alt="Screen Shot 2022-10-26 at 6 30 52 PM" src="https://user-images.githubusercontent.com/66915274/198082677-d393243e-363a-4d1f-95d8-a6695336a47a.png">

Podemos comprobar si se ha creado con el comando ```getent group nombre_grupo``` o tambi茅n podemos hacer ```cat /etc/group``` y podremos ver todos los grupos y los usuarios que hay dentro de ellos.

6 鈼? Con el comando ```sudo adduser user group``` incluiremos al usuario en el grupo. Debemos incluir al usuario en los grupos ```sudo``` y ```user42```.

<img width="422" alt="Screen Shot 2022-10-26 at 6 32 30 PM" src="https://user-images.githubusercontent.com/66915274/198083019-c5a442bb-c625-45ce-84e1-bcbca3a7dba5.png">

<img width="404" alt="Screen Shot 2022-10-26 at 6 34 09 PM" src="https://user-images.githubusercontent.com/66915274/198083377-bd4162c6-317b-474f-8bc4-e542be4dcfde.png">

7 鈼? Una vez los hayamos introducido para checkear que todo se haya hecho correctamente podemos ejecutar el comando ```getent group nombre_grupo``` o tambien podemos editar el fichero /etc/group ```nano /etc/group``` y en los grupos ```sudo``` y ```login42``` debera aparecer nuestro usuario.

<img width="328" alt="Screen Shot 2022-10-26 at 6 35 50 PM" src="https://user-images.githubusercontent.com/66915274/198083739-ad16e388-69c3-41d1-a061-e55dd66b0d14.png">

<img width="151" alt="Screen Shot 2022-10-26 at 6 36 18 PM" src="https://user-images.githubusercontent.com/66915274/198083854-0fba5296-a49f-44cc-8427-59a692e69288.png">

<img width="353" alt="Screen Shot 2022-10-26 at 6 39 22 PM" src="https://user-images.githubusercontent.com/66915274/198084464-f73352ee-ed21-478b-a44d-d86eb6d8a1cd.png">

<img width="183" alt="Screen Shot 2022-10-26 at 6 38 25 PM" src="https://user-images.githubusercontent.com/66915274/198084311-45a50162-ff89-4e7d-a3c5-45e7048520a4.png">

### 4.2 - Instalaci贸n y configuraci贸n SSH 馃摱

1 鈼? Lo primero que haremos ser谩 hacer ```sudo apt update``` para actualizar los repositorios que definimos en el archivo /etc/apt/sources.list

<img width="774" alt="Captura de pantalla 2022-07-14 a las 3 09 44" src="https://user-images.githubusercontent.com/66915274/178864173-aa5a08cf-8562-4484-a60a-3e1c7a533a28.png">

2 鈼? Acto seguido instalaremos la herramienta principal de conectividad para el inicio de sesi贸n remoto con el protocolo SSH, esta herramienta es OpenSSH. Para instalarla debemos introducir el comando ```sudo apt install openssh-server```. En el mensaje de confirmaci贸n ponemos ```Y```, acto seguido esperaremos a que termine la instalaci贸n.

<img width="772" alt="Captura de pantalla 2022-07-14 a las 3 14 52" src="https://user-images.githubusercontent.com/66915274/178865991-cdb90f12-ebd8-4583-bcbb-70f47c86abe6.png">

Para comprobar que se haya instalado correctamente haremos ```sudo service ssh status``` y nos debe aparecer active.

<img width="702" alt="Captura de pantalla 2022-07-14 a las 3 53 59" src="https://user-images.githubusercontent.com/66915274/178876938-7fd74214-15df-4759-bf8d-52b53a8f4251.png">

3 鈼? Una vez terminada la instalaci贸n se han creado algunos ficheros que debemos editar. Podemos usar nano o vi, o tambi茅n instalar vim si lo prefieres. El primer fichero que editaremos ser谩 ```/etc/ssh/sshd_config```, as铆 que en consola escribimos ```sudo nano /etc/ssh/sshd_config```.

<img width="497" alt="Captura de pantalla 2022-07-14 a las 3 24 21" src="https://user-images.githubusercontent.com/66915274/178867150-273c75c1-c935-45f0-a551-1a115d3f6f6a.png">

4 鈼? Los ```#``` al comienzo de una l铆nea significan que esta comentada, las l铆neas que vayamos a modificar deber谩s quitarle el comentario. Una vez estemos editando el fichero deberemos modificar las siguientes l铆neas:

鉃? #Port 22 -> Port 4242

<img width="807" alt="Captura de pantalla 2022-07-14 a las 3 31 04" src="https://user-images.githubusercontent.com/66915274/178867929-0f8be11e-d0ca-4445-af05-a693d01411bd.png">

鉃? #PermitRootLogin prohibit-password -> PermitRootLogin no

<img width="798" alt="Captura de pantalla 2022-07-14 a las 3 34 13" src="https://user-images.githubusercontent.com/66915274/178868266-fc6d6684-8196-4021-b884-a047a443a3ec.png">

Una vez hayamos modificado esas l铆neas debemos guardar los cambios realizados sobre el fichero y dejar de editarlo.

5 鈼? Ahora debemos editar el fichero ```/etc/ssh/ssh_config```.

<img width="501" alt="Captura de pantalla 2022-07-14 a las 3 48 56" src="https://user-images.githubusercontent.com/66915274/178872582-8277e687-8ab7-4087-bd17-a71e5e86d5e6.png">

Editaremos la siguiente l铆nea: 

鉃? #Port 22 -> Port 4242

<img width="795" alt="Captura de pantalla 2022-07-14 a las 3 50 29" src="https://user-images.githubusercontent.com/66915274/178875013-1969c13f-9e43-4f2a-a037-f384a8e87a78.png">

6 鈼? Por 煤ltimo debemos reiniciar el servicio ssh para que as铆 se actualicen las modificaciones que acabamos de realizar. Para ello debemos escribir el comando ```sudo service ssh restart``` y una vez reseteado miraremos el estado actual con ```sudo service ssh status``` y para confirmar que se hayan realizado los cambios en la escucha del servidor debe aparecer el Puerto 4242.

<img width="713" alt="Captura de pantalla 2022-07-14 a las 3 56 56" src="https://user-images.githubusercontent.com/66915274/178880333-0e2ad7fd-674b-4b4f-b92a-25acbc36c8a5.png">

### 4-3 Conectarse via SSH 馃棧

1 鈼? Para conectarnos por SSH, primero hay que habilitar los puertos que va a usar este servicio. Para ello primero cerramos la m谩quina, abrimos VirtualBox y vamos a configuraci贸n o settings.

<img width="832" alt="Captura de pantalla 2022-07-18 a las 10 15 13" src="https://user-images.githubusercontent.com/66915274/179470948-d9a863ef-f1a3-41fb-a103-25378064e747.png">

2 鈼? Una vez en configuraci贸n debemos pinchar sobre el apartado de ```Red``` , pincharemos sobre ```Avanzadas``` para que as铆 nos muestre m谩s opciones y le daremos a ```Reenv铆o de puertos```.

<img width="684" alt="Captura de pantalla 2022-07-18 a las 10 18 32" src="https://user-images.githubusercontent.com/66915274/179471690-cfbdbf4b-ab93-4b12-9504-2482712652a3.png">

3 鈼? Pincharemos sobre el siguiente emoticono para agregar una regla de reenv铆o.

<img width="585" alt="Captura de pantalla 2022-07-18 a las 10 21 24" src="https://user-images.githubusercontent.com/66915274/179471855-913a684d-c7b0-43e2-9e01-d2c954fe75a4.png">

4 鈼? Por 煤ltimo agregaremos el puerto ```4242``` al anfitri贸n y al invitado. Las IP's no son necesarias. Pincharemos sobre el bot贸n de aceptar para que as铆 se apliquen los cambios.

<img width="588" alt="Captura de pantalla 2022-07-18 a las 10 22 29" src="https://user-images.githubusercontent.com/66915274/179472105-5942b3ec-5c29-4d49-a00e-67f9cde289e8.png">

鉃? Una vez habilitados los puertos desde VirtualBox, volvemos a abrir nuestra m谩quina virtual. Ahora, desde la consola de nuestro equipo real, escribimos ```ssh <tu_nombre__de_usuario>@localhost -p 4242```; nos pedir谩 la clave del usuario y una vez la introduzcamos ya nos saldr谩 el login en verde, lo que significa que estamos conectados. A partir de aqu铆, lo m谩s recomendable es trabajar siempre desde nuestro terminal de la m谩quina real, ya que as铆 te libras de todos los problemas de lag, parpadeos, lentitud y otros que suele tener la m谩qina virtual.

<img width="517" alt="Screen Shot 2022-10-27 at 12 40 23 AM" src="https://user-images.githubusercontent.com/66915274/198174777-28f7793b-273b-43ce-b1c2-4a890353cb8c.png">

<img width="566" alt="Screen Shot 2022-10-27 at 12 40 04 AM" src="https://user-images.githubusercontent.com/66915274/198174814-c1873c62-41dd-4c1d-ad2d-f268b2da0e4c.png">

### 4-4 Instalaci贸n y configuraci贸n de UFW 馃敟馃П

1 鈼? Lo primero que debemos hacer el instalar UFW, para ello haremos uso del comando ```sudo apt install ufw``` acto seguido escribiremos una ```y``` para confirmar que deseamos instalarlo y esperaremos a que termine.

<img width="771" alt="Captura de pantalla 2022-07-14 a las 19 28 55" src="https://user-images.githubusercontent.com/66915274/179045920-4a9aec64-b1d7-4785-89a1-4a299aae21a3.png">

<img width="802" alt="Captura de pantalla 2022-07-14 a las 19 29 25" src="https://user-images.githubusercontent.com/66915274/179045994-19cdf6e0-be61-454b-9adc-ba1f9c2dfd84.png">

2 鈼? Una vez instalado debemos habilitarlo , para ello debemos poner el siguiente comando ```sudo ufw enable``` y acto seguido nos debe indicar que el firewall esta activo.

<img width="498" alt="Captura de pantalla 2022-07-14 a las 19 32 57" src="https://user-images.githubusercontent.com/66915274/179046565-307c042b-243e-4224-bcb2-d02859332352.png">

3 鈼? Ahora lo que debemos hacer es que nuestro firewall permita las conexiones que se lleven a cabo mediante el puerto 4242. Lo haremos con el siguiente comando ```sudo ufw allow 4242```.

<img width="514" alt="Captura de pantalla 2022-07-14 a las 19 34 12" src="https://user-images.githubusercontent.com/66915274/179046765-5277ec55-b8e4-4d4f-a617-a2a8758b80a8.png">

4 鈼? Por 煤ltimo comprobaremos que esta todo correctamente configurado mirando el estado de nuestro cortafuegos , en donde ya debe aparecer como permitidas las conexiones mediante el puerto 4242. Para ver el estado daremos uso del comando ```sudo ufw status```.

<img width="575" alt="Captura de pantalla 2022-07-14 a las 19 38 37" src="https://user-images.githubusercontent.com/66915274/179047574-8073045c-6e78-4b6f-8487-cb0f490a2cd0.png">

### 4-5 Configurar contrase帽a fuerte para sudo 馃敀

1 鈼? Crearemos un fichero en la ruta /etc/sudoers.d/ a mi fichero yo le he decidido llamar sudo_config ya que en ese fichero se almacenar谩 la configuraci贸n de la contrase帽a. El comando exacto para crear el fichero es ```touch /etc/sudoers.d/sudo_config```.

<img width="511" alt="Captura de pantalla 2022-07-14 a las 22 00 40" src="https://user-images.githubusercontent.com/66915274/179072822-2f86bd8b-216e-45e4-a15b-8fe3a49149ff.png">

2 鈼? Debemos crear el directorio sudo en la ruta /var/log porque cada comando que ejecutemos con sudo , tanto el input como el output debe quedar almacenado en ese directorio. Para crearlo utilizaremos el comando ```mkdir /var/log/sudo```.

<img width="502" alt="Captura de pantalla 2022-07-14 a las 21 56 53" src="https://user-images.githubusercontent.com/66915274/179072210-ad99e50d-fa57-494b-999d-3a80dd0f7849.png">

3 鈼? Debemos editar el fichero creado en el paso 1. Como he comentado anteriormente puedes utilizar el editor que mas te guste , pero yo dare uso de nano. Comando para editar el fichero:  ```nano /etc/sudoers.d/sudo_config```.

<img width="502" alt="Captura de pantalla 2022-07-14 a las 22 04 10" src="https://user-images.githubusercontent.com/66915274/179073389-5b2a9c16-811c-4133-87c6-479e770c880b.png">

4 鈼? Una vez estamos editando el fichero deberemos introducir los siguientes comandos para cumplir todos los requisitos que pide el subject.

```
Defaults  passwd_tries=3
Defaults  badpass_message="Mensaje de error personalizado"
Defaults  logfile="/var/log/sudo/sudo_config"
Defaults  log_input, log_output
Defaults  iolog_dir="/var/log/sudo"
Defaults  requiretty
Defaults  secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
```

鉃? C贸mo deber铆a verse el fichero.

<img width="1202" alt="Captura de pantalla 2022-07-16 a las 2 03 45" src="https://user-images.githubusercontent.com/66915274/179326003-1fd67295-4be2-47bd-98fc-d5821f5f1c4d.png">

馃 <b>Qu茅 hace cada comando鉂? </b>

<img width="802" alt="Captura de pantalla 2022-07-16 a las 2 04 56" src="https://user-images.githubusercontent.com/66915274/179326915-b374f679-fa2e-4e02-8b38-cdb53c6354a6.png">

### 4-6 Configuraci贸n de pol铆tica de contrase帽as fuerte 馃攽

1 鈼? El primer paso ser谩 editar el fichero login.defs.

<img width="493" alt="Captura de pantalla 2022-07-16 a las 2 54 06" src="https://user-images.githubusercontent.com/66915274/179327943-67432d4a-7042-44ea-96f4-5975556ce4dc.png">

2 鈼? Una vez estemos editando el fichero modificaremos los siguientes parametros: 

鉃? PASS_MAX_DAYS 99999 -> PASS_MAX_DAYS 30

鉃? PASS_MIN_DAYS 0 -> PASS_MIN_DAYS 2


<img width="802" alt="Captura de pantalla 2022-07-16 a las 3 05 49" src="https://user-images.githubusercontent.com/66915274/179328449-32a40f67-a18d-4f29-993b-94d013cd7670.png">

PASS_MAX_DAYS: Es el tiempo de expiraci贸n de la contrase帽a. El numero corresponde a d铆as.

PASS_MIN_DAYS: El n煤mero m铆nimo de d铆as permitido antes de modificar una contrase帽a.

PASS_WARN_AGE: El usuario recibira un mensaje de aviso indicando que faltan los dias especificados para que expire su contrase帽a.

3 鈼? Para poder seguir con la configuraci贸n debemos instalar los siguientes paquetes con este comando ```sudo apt install libpam-pwquality``` , acto seguido pondremos ```Y``` para confirmar la instalaci贸n y esperaremos a que termine. 

<img width="770" alt="Captura de pantalla 2022-07-16 a las 3 13 52" src="https://user-images.githubusercontent.com/66915274/179328708-c5054703-bdb0-4cca-82a8-6ab25ce42b40.png">

4 鈼? Lo siguiente que debemos hacer es volver a editar un fichero y modificar algunas l铆neas. Haremos ```nano /etc/pam.d/common-password```. 

<img width="500" alt="Captura de pantalla 2022-07-16 a las 3 27 02" src="https://user-images.githubusercontent.com/66915274/179329260-0e18bd27-a522-4c7c-86bf-21823eee0f8b.png">

5 鈼? Despues de retry=3 debemos a帽adir los siguientes comandos:

```
minlen=10
ucredit=-1
dcredit=-1
maxrepeat=3
reject_username
difok=7
enforce_for_root
```
鉃? As铆 debe ser la l铆nea 鈫欙笍

<img width="1127" alt="Captura de pantalla 2022-07-16 a las 3 34 33" src="https://user-images.githubusercontent.com/66915274/179329511-0619183a-8ccc-456b-8f27-3962fc542cc3.png">

鉃? As铆 se debe ver en el fichero 鈫欙笍

<img width="800" alt="Captura de pantalla 2022-07-16 a las 3 38 08" src="https://user-images.githubusercontent.com/66915274/179329787-1b718843-9272-43e4-8d92-8d83933cc938.png">

馃 <b>Que hace cada comando鉂?</b>

minlen=10 鉃? La cantidad minima de caracteres que debe contener la contrase帽a.

ucredit=-1 鉃? Como m铆nimo debe contener un caracter ```Mayus```. Ponemos el - ya que debe contener como m铆nimo un caracter, si ponemos + nos referimos a como maximo esos caracteres.

dcredit=-1 鉃omo m铆nimo debe contener un digito.

maxrepeat=3 鉃? No puede tener m谩s de 3 veces seguidas el mismo caracter.

reject_username 鉃? No puede contener el nombre del usuario.

difok=7 鉃?  Debe tener al menos 7 caracteres que no sean parte de la antigua contrase帽a. 

enforce_for_root 鉃? Implementaremos esta pol铆tica para el usuario root.

## 5- Script 馃毃

Esta es una parte muy importante del proyecto. Debes prestar atenci贸n en todo, muy importante no copiar y pegar directamente el fichero sin saber que hace cada cosa. En la evaluaci贸n debes explicar cada comando si el evaluador lo pide.

馃 <b>Que es un script鉂?</b> Es una secuencia de comandos guardada en un fichero que cuando se ejecuta hara la funcion de cada comando.

### 5-1 Architecture 

Para poder ver la arquitectura del SO y su versi贸n de kernel utilizaremos el comando ```uname -a``` ( "-a" == "--all" ) que basicamente printara toda la informaci贸n excepto si el tipo de procesador es desconocido o la plataforma de hardware. 

<img width="715" alt="Screen Shot 2022-10-27 at 4 50 06 PM" src="https://user-images.githubusercontent.com/66915274/198322524-8c2d305f-bfe8-4e4a-bf31-6a883af71ad3.png">

### 5-2 N煤cleos f铆sicos

Para poder mostrar el numero de nucleos fisicos haremos uso del fichero /proc/cpuinfo el cual  proporciona informaci贸n acerca del procesador: su tipo, marca, modelo, rendimiento, etc. Usaremos el comando ```grep "physical id" /proc/cpuinfo | wc -l``` con el comando grep buscaremos dentro del fichero "physical id" y con wc -l contaremos las lineas del resultado de grep. Esto lo hacemos ya que la manera de cuantificar los nucleos no es muy com煤n. Si hay un procesador marcar谩 0 y si tiene m谩s de un procesador, mostrar谩 toda la informaci贸n del procesador por separado contando los procesadores usando la notaci贸n cero. De esta manera simplemente contaremos las lineas que hay ya que es m谩s c贸modo cuantificarlo as铆.

<img width="596" alt="Screen Shot 2022-10-27 at 4 50 49 PM" src="https://user-images.githubusercontent.com/66915274/198322799-4bf2131e-7fba-4c9e-8d1b-bb9cc1b89e76.png">


### 5-3 N煤cleos virtuales

Para poder mostrar el numero de nucleos virtuales es muy parecido al anterior. Haremos uso de nuevo del fichero /proc/cpuinfo , pero, en este caso utilizaremos el comando ```grep processor /proc/cpuinfo | wc -l```. El uso es practicamente el mismo al anterior solo que en vez de contar las lineas de "physical id" lo haremos de processor. Lo hacemos as铆 por el mismo motivo de antes, la manera de cuantificar marca 0 si hay un procesador.

<img width="586" alt="Screen Shot 2022-10-27 at 4 55 48 PM" src="https://user-images.githubusercontent.com/66915274/198324254-3d0f247d-b767-4e02-9e69-11b4e0586280.png">


### 5-4 Memoria RAM

Para mostrar la memoria ram haremos uso del comando ```free``` para as铆 ver al momento informaci贸n sobre la ram, la parte usada, libre, reservada para otros recursos, etc. Para m谩s info sobre el comando pondremos free --help. Nosotros daremos uso de free --mega ya que en el subject aparece esa unidad de medida.

<img width="672" alt="Captura de pantalla 2022-08-02 a las 2 46 10" src="https://user-images.githubusercontent.com/66915274/182268241-86b743bb-653d-4fef-acda-e7bfa59e38d7.png">

Una vez hemos ejecutado este comando debemos filtrar nuestra busqueda ya que no necesitamos toda la informaci贸n que nos aporta , lo primero que debemos mostrar es la memoria usada, para ello haremos uso del comando ```awk``` que lo que hace este comando es para procesar datos basados en archivos de texto, es decir, podremos utilizar los datos que nos interesen de X fichero. Por 煤ltimo lo que haremos ser谩 comparar si la primera palabra de una fila es igual a "Mem:" printaremos la tercera palabra de esa fila que ser谩 la memoria usada. Todo el comando junto seria ```free --mega | awk '$1 == "Mem:" {print $3}'```. En el script el valor de retorno de este comando se lo asignaremos a una variable que concatenaremos con otras variables para que todo quede igual como especifica el subject.

<img width="621" alt="Captura de pantalla 2022-08-02 a las 2 55 21" src="https://user-images.githubusercontent.com/66915274/182269019-d5bb3107-f091-491f-a4ab-27edd357aec8.png">

Para obtener la memoria total el comando es practicamente igual al anterior lo 煤nico que deberemos cambiar es que en vez de printar la tercera palabra de la fila queremos la segunda ```free --mega | awk '$1 == "Mem:" {print $2}'```.

<img width="605" alt="Captura de pantalla 2022-08-02 a las 3 00 02" src="https://user-images.githubusercontent.com/66915274/182269450-318816e1-fc71-48b0-a860-278cc6050e05.png">

Por 煤ltima parte debemos calcular el % de memoria usada. El comando de nuevo es parecido a los anteriores la 煤nica modificaci贸n que haremos en la parte del printeo. Como la operaci贸n para conseguir el tanto porciento no es exacta nos puede dar muchos decimales y en el subject solo aparecen 2 asique nosotros haremos lo mismo, por eso utilizamos ```%.2f``` para que asi solo se muestren 2 decimales. Otra cosa que quiz谩s no sepas es en printf para que se muestre un ```%``` hay que poner ```%%```. Todo el comando ```free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}'```.

<img width="798" alt="Captura de pantalla 2022-08-02 a las 3 51 01" src="https://user-images.githubusercontent.com/66915274/182274627-195476b2-1e17-4a4c-8d5c-2056e4e2bbb6.png">

### 5-5 Memoria del disco

Para poder ver la memoria del disco ocupada y disponible utilizaremos el comando ```df``` que significa "disk filesystem" , se utiliza para obtener un resumen completo del uso del espacio en disco. Como en el sibject indica la memoria utilizada se muestra en MB asi que entonces utilizaremos el flag -m. Acto seguido haremos un grep para que solo nos muestre las lineas que contengan "/dev/" y seguidamente volveremos a hacer otro grep con el flag -v para excluir las lineas que contengan "/boot". Por 煤ltimo utilizaremos el comando awk y sumaremos el valor de la tercera palabra de cada linea para una vez sumadas todas las lineas printar el resultado final de la suma. El comando entero es el siguiente: ```df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'```.

<img width="805" alt="Captura de pantalla 2022-08-03 a las 2 26 15" src="https://user-images.githubusercontent.com/66915274/182498837-4f883b25-e316-4c74-8f6b-a5e8b5d13289.png">

Para obtener el espacio total utilizaremos un comando muy parecido. Las unicas diferencias seran que los valores que sumaremos seran los $2 en vez de $3 y la otra diferencia es que en el subject aparece el tama帽o total en Gb asique como el resultado de la suma nos da el numero en Mb debemos transformarlo a Gb , para ello debemos dividir el numero entre 1024 y quitar los decimales.

<img width="801" alt="Captura de pantalla 2022-08-03 a las 2 40 55" src="https://user-images.githubusercontent.com/66915274/182500104-0aaa1a6b-cf05-4a82-9c9a-8e163f1c1e98.png">

Por 煤ltimo debemos mostrar un porcentaje de la memoria usada. Para ello , de nuevo, utilizaremos un comando muy parecido a los dos anteriores. Lo unico que cambiaremos es que combinaremos los dos comandos anteriores para tener dos variables , una que representa la memoria usada y la otra la total. Hecho esto haremos una operacion para conseguir el tanto por ciento ```use/total*100``` y el resultado de esta operacion lo printaremos como aparece en el subject , entre parentesis y con el simbolo % al final. El comando final es este: ```df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf("(%d%%)\n"), use/total*100}'```.

<img width="798" alt="Captura de pantalla 2022-08-03 a las 2 49 33" src="https://user-images.githubusercontent.com/66915274/182500836-dd4b068e-b6ce-4dc6-b832-f90acecfb71c.png">


### 5-6 Porcentaje uso de CPU

Para poder ver el porcentaje de uso de CPU haremos uso del comando ```vmstat``` este muestra estad铆sticas del sistema, permitiendo obtener un detalle general de los procesos, uso de memoria, actividad de CPU, estado del sistema, etc. Podriamos poner si ninguna opci贸n pero en mi caso pondr茅 un intervalo de segundos de 1 a 4. Tambien daremos uso del comando ```tail -1``` que este lo que nos va a permitir es que solo produzca el output la ultima linea, entonces de las 4 generadas solo se printara la ultima. Por ultimo solo printaremos la palabra 15 que es el uso de memoria disponible. El comando entero es el siguiente: ```vmstat 1 4 | tail -1 | awk '{print %15}'```. El resultado de este comando solo es una parte del resultado final ya que todavia hay que hacer alguna operaci贸n en el script para que quede bien. Lo que habria que hacer es a 100 restarle la cantidad que nos ha devuelto nuestro comando, el resultado de esa operaci贸n lo printaremos con un decimal y un % al final y ya estar铆a hecha la operaci贸n. 

<img width="580" alt="Captura de pantalla 2022-08-03 a las 0 33 39" src="https://user-images.githubusercontent.com/66915274/182484896-def71bf0-b7eb-49d8-b83b-a019d15f62f1.png">

### 5-7 脷ltimo reinicio

Para ver la fecha y hora de nuestro 煤ltimo reinicio haremos uso del comando ```who``` con el flag ```-b``` ya que con ese flag nos mostrar谩 por pantalla el tiempo del 煤ltimo arranque del sistema. Como ya nos ha pasado anteriormente nos muestra m谩s informaci贸n de la que deseamos asique filtraremos y solo mostraremos lo que nos interesa, para ello haremos uso del comando awk y compararemos si la primera palabra de una linea es "system" se printara por pantalla la tercera palabra de esa linea , un espacio y la cuarta palabra. El comando entero seria el siguiente: ```who -b | awk '$1 == "system" {print $3 " " $4}'```.

<img width="661" alt="Captura de pantalla 2022-08-02 a las 12 24 58" src="https://user-images.githubusercontent.com/66915274/182352895-d985e675-5afc-445a-bcd3-68189702fe70.png">

### 5-8 Uso LVM

Para checkear si LVM esta activo o no haremos uso del comando lsblk , este nos muestra informaci贸n de todos los dispositivos de bloque (discos duros, SSD, memorias, etc) entre toda la informaci贸n que proporciona podemos ver lvm en el tipo de gestor. Para este comando haremos un if ya que o printaremos Yes o No. Basicamente la condicion que buscamos sera contar el numero de lineas en las que aparece "lvm" y si hay mas de 0 printamos Yes, si hay 0 se printara No. Todo el comando seria: ```if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi```.

<img width="801" alt="Captura de pantalla 2022-08-02 a las 22 38 43" src="https://user-images.githubusercontent.com/66915274/182468904-3789e22f-dbde-4874-b153-0d86497c55e2.png">

### 5-9 Conexiones TCP

Para mirar el numero de conexiones TCP establecidas. Utilizaremos el comando ```ss``` sustituyendo al ya obsoleto netstat. Filtraremos con el flag ```-ta``` para que solo se muestren las conexiones TCP. Por 煤ltimo haremos un grep para ver las que estan establecidas ya que tambien hay solo de escucha y cerraremos con wc -l para que cuente el numero de lineas. El comando queda tal que asi: ```ss -ta | grep ESTAB | wc -l```. 

<img width="479" alt="Captura de pantalla 2022-08-03 a las 0 53 36" src="https://user-images.githubusercontent.com/66915274/182487028-746244f8-2cda-4dc7-a14c-b2e5a7e0dc51.png">

### 5-10 N煤mero de usuarios

Daremos uso del comando ```users``` que nos mostrar谩 el nombre de los usuarios que hay, sabiendo esto, pondremos wc -w para que cuente la cantidad de palabras que hay en la salida del comando. El comando entero queda as铆 ```users | wc -w```.

<img width="380" alt="Captura de pantalla 2022-08-02 a las 12 33 29" src="https://user-images.githubusercontent.com/66915274/182354436-282547cf-22c8-4b03-9484-6801c0466de7.png">


### 5-11 Direcci贸n IP y MAC

Para obtener la direcci贸n del host haremos uso del comando ```hostname -I``` y para obtener la MAC haremos uso del comando ```ip link``` que se utiliza para mostrar o modificar las interfaces de red. Como aparecen m谩s de una interfaz, IP's etc. Utilizaremos el comando grep para buscar lo que deseamos y asi poder printar por pantalla solo lo que nos piden. Para ello pondremos ```ip link | grep "link/ether" | awk '{print $2}'``` y de esta manera solo printaremos la MAC.

<img width="639" alt="Captura de pantalla 2022-08-02 a las 14 53 14" src="https://user-images.githubusercontent.com/66915274/182379380-8e3b803d-d001-42ae-8aea-467e8c9f3ea9.png">

### 5-12 N煤mero de comandos ejecutados con sudo

Para poder obtener el numero de comandos que son ejecutados con sudo haremos uso del comando jornalctl que este es una herramienta que se encarga de recopilar y administrar los registros del sistema. Acto seguido pondremos ```_COMM=sudo``` par as铆 filtrar las entradas especificando su ruta. En nuestro ponemos ```_COMM``` ya que hace referencia a un script ejecutable. Una vez tengamos filtrada la busqueda y solo aparezcan los registros de sudo todav铆a deberemos filtrar un poco m谩s ya que cuando incias o cierras sesion de root tambien aparece en el registro, entonces para terminar de filtrar pondremos un ```grep COMMAND``` y asi solo apareceran las lineas de comandos. Por ultimo pondremos ```wc -l``` para que asi nos salgan enumeradas las lineas. El comando entero es el siguiente: ```journalctl _COMM=sudo | grep COMMAND | wc -l)```. Para comprobar que funcione correctamente podemos correr el comando en el terminal, poner un comando que incluya sudo y volver a correr el comando y deber谩
incrementar el n煤mero de ejecucciones de sudo.

<img width="632" alt="Captura de pantalla 2022-08-02 a las 23 50 39" src="https://user-images.githubusercontent.com/66915274/182479668-949b8eee-81f6-4593-83f4-99053d199f1b.png">

### 5-13 Resultado total del script

鈿狅笍 Recuerda no hacer copia y pega si no sabes el funcionamiento de cada comando 鈿狅笍

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
Script visto desde nano 鈫欙笍

<img width="911" alt="Captura de pantalla 2022-08-03 a las 3 47 31" src="https://user-images.githubusercontent.com/66915274/182506484-f5a095b8-4751-461e-a114-f8e36b4cfa9a.png">

Resultado tras la ejecuci贸n del script 鈫欙笍

<img width="796" alt="Captura de pantalla 2022-08-03 a las 3 46 15" src="https://user-images.githubusercontent.com/66915274/182506357-f5466a97-380b-4b6d-9b79-89e01a31498a.png">

El script termina con `wall` porque este comando lo que hace es escribir en pantalla de las terminales de todos los usuarios un mensaje, admite texto entre comillas a la vez que el valor de variables, por eso primero establecemos cada variable del script y luego con `wall` a帽adimos todo entre comillas y a帽adimos el texto necesario para cada apartado a mostrar. 

## 6- Crontab 鈴? vs SystemD 鈱?

Para mostrar en pantalla el script cada 10 minutos, como pide el subject, tenemos varias opciones. En todas las gu铆as que he consultado, l@s compa帽er@s han usado crontab, pero en mi caso he terminado usando un servicio "personalizado".

En el caso de usar cron, tenemos que editar el fichero crontab con el comando ```sudo crontab -u root -e```. Debemos a帽adir esta l铆nea justo al final del arhicvo para que el script se ejecute cada 10 minutos: ```*/10 * * * * sh /ruta del script```. 

El problema de usar este m茅todo es que el script se va a ejecutar a cada 10 minutos del reloj, es decir, a las 10:00, 10:10, 10:20, 10:30... No son 10 minutos reales desde el momento de iniciar la m谩quina virtual o logearse, por ejemplo. Esto se puede corregir creando otro script, ```sleep.sh```, para compensar el "desfase". 

Este script primero calcula los minutos y segundos del inicio de sistema
```
BOOT_MIN=$(uptime -s | cut -d ":" -f 2)
BOOT_SEC=$(uptime -s | cut -d ":" -f 3)
```
Se calcula el n煤mero de segundos hasta el siguiente :10 del reloj. 
Ejemplo: inicio de sistema a 11:43:36
43 % 10 = 3 minutos despu茅s de las 11:40 
3 * 60 = 180 segundos despu茅s de las 11:40
180 + 36 = el inicio de sesi贸n ha sido 216 segundos en total despu茅s de las 11:40

`DELAY=$(bc <<< $BOOT_MIN%10*60+$BOOT_SEC)`

Hacemos un delay de ese tiempo total que hemos calculado antes, cuando sean las 11:50, sleep har谩 un delay de 216 segundos
`sleep $DELAY`

SCRIPT `sleep.sh`

```
#!bin/bash

BOOT_MIN=$(uptime -s | cut -d ":" -f 2)
BOOT_SEC=$(uptime -s | cut -d ":" -f 3)

DELAY=$(bc <<< $BOOT_MIN%10*60+$BOOT_SEC)

sleep $DELAY
```

Por 煤ltimo, habr铆a que a帽adir la ruta del script a crontab ANTES de la ruta de `monitoring.sh`, y usar el booleano `&&`, para que no se ejecute monitoring hasta que termine de ejecutarse `sleep.sh`.

La alternativa que he usado yo es crear un servicio de systemd con un timer. B谩sicamente se trata de crear dos archivos que se comunican entre si (```monitoring.service``` y ```monitoring.timer```), ajustar bien el timer y habilitar e iniciar el servicio, como ya hemos hecho antes con otros (como ssh por ejemplo).

Para esto, nos vamos a la carpeta ```/etc/systemd/system```, aqu铆 creamos los dos archivos: touch ```monitoring.service``` y ```monitoring.timer```. Vamos a editarlos con nano o vim para que tengan la siguiente estructura:

`$sudo nano monitoring.service`, escribimos las siguientes l铆neas:

>[Unit]

>Description=monitoring.sh

>Wants=monitoring.timer

>[Service]

>Type=oneshot

>ExecStart=<ruta_del_script>

>[Install]

>WantedBy=multi_user.target

`$ sudo nano monitoring.timer`, escribimos las siguientes l铆neas:

>[Unit]

>Description=monitoring.sh

>Requires=monitoring.service

>[Timer]

>Unit=monitoring.service

>AccuraySec=1ms

>OnStartupSec=10m

>OnUnitActiveSec=10m

>[Install]

>WantedBy=timers.target

Ya hemos creado el servicio, ahora recargamos el administrador de configuraciones de systemctl para que se "registre" el nuevo servicio. Esto tambi茅n tendremos que hacerlo en la evaluaci贸n cuando hagamos cambios en el tiempo de ejecuci贸n del script o detengamos el servicio (IMPORTANTE!).

`$ sudo systemctl daemon-reload`

Para terminar, tenemos que habilitar el servicio que hemos creado para que siempre se ejecute al iniciar nuestra m谩quina virtual.

`$ sudo systemctl enable monitoring.service`

Y s铆 queremos iniciarlo en la sesi贸n actual sin reiniciar.

`$ sudo systemctl start monitoring.service`


## 7- Signature.txt 馃摑

Para obtener la firma lo primero que debemos hacer es apagar la m谩quina virtual ya que una vez la enciendas o modifiques algo la firma cambiar谩.

<img width="834" alt="Captura de pantalla 2022-08-03 a las 4 47 32" src="https://user-images.githubusercontent.com/66915274/182513283-1cfc319f-982d-47cf-a596-8475d4c96616.png">

El siguiente paso ser谩 ubicarnos en la ruta donde tengamos el .vdi de nuestra maquina virtual. 

<img width="465" alt="Screen Shot 2022-08-03 at 4 57 37 AM" src="https://user-images.githubusercontent.com/66915274/182514499-f0ad5ba7-c0c2-493e-b0ae-9b79c970816e.png">

Por 煤ltimo haremos ```$ shasum nombremaquina.vdi``` y esto nos dara la firma. El resultado de esta firma es lo que tendremos a帽adir a nuestro fichero signature.txt para posteriormente subir el fichero al repositorio de la intra. Muy importante no volver a abrir la maquina ya que se modificara la firma. Para las correcciones recuerda clonar la maquina ya que asi podras encenderla sin miedo a que cambie la firma.

<img width="416" alt="Screen Shot 2022-08-03 at 4 58 48 AM" src="https://user-images.githubusercontent.com/66915274/182514627-f11026d0-de0d-447d-a2e4-31a3c1af0f35.png">

## 8- Instalaci贸n y configuraci贸n de servicios extra 馃摪

### 8.1 - Lighttpd

1 鈼? Instalaci贸n de paquetes de lighttpd.

<img width="791" alt="Screen Shot 2022-10-27 at 4 09 24 AM" src="https://user-images.githubusercontent.com/66915274/198174389-428c30e0-c437-4bc1-b8df-40dd2fb0c0ce.png">

2 鈼? Permitimos las conexiones mediante el puerto 80 con el comando ```sudo ufw allow 80```.

<img width="306" alt="Screen Shot 2022-10-27 at 4 15 24 AM" src="https://user-images.githubusercontent.com/66915274/198175046-8ea3f052-32f1-4107-a9a1-c9271d6c9ce6.png">

3 鈼? Checkeamos que realmente hayamos permitido ```sudo ufw status```. Debe aparecer el puerto 80 y allow. 

<img width="460" alt="Screen Shot 2022-10-27 at 4 15 45 AM" src="https://user-images.githubusercontent.com/66915274/198175075-da6833f1-2360-4e08-b708-99f920b8215c.png">

### 8.2 - MariaDB

Instalamos el servidor de MariaDB.

`$ sudo apt install mariadb-server` 

<img width="797" alt="Screen Shot 2022-10-27 at 4 17 09 AM" src="https://user-images.githubusercontent.com/66915274/198175218-65dec75f-5727-425c-97d0-2baa2b8cd457.p
ng">

Verificamos que se haya instalado bien (opcional).

`$ sudo dpkg -l | grep mariadb-server`

Instalamos el servicio mysql_server.

`$ sudo mysql_service_installation`

<img width="629" alt="Screen Shot 2022-10-27 at 4 19 25 AM" src="https://user-images.githubusercontent.com/66915274/198175511-d826b699-770e-4142-b464-cd6a91211d6a.png">

Aceptamos todas los [Y/N] excepto los dos primeros (N, N, Y, Y, Y, Y).

<img width="704" alt="Screen Shot 2022-10-27 at 1 00 20 AM" src="https://user-images.githubusercontent.com/66915274/198175719-b22bd572-ab50-4590-9298-5f5a69f98862.png">

<img width="551" alt="Screen Shot 2022-10-27 at 1 00 40 AM" src="https://user-images.githubusercontent.com/66915274/198175732-eff97e65-d8ef-4b44-8930-62d58d910598.png">

Entramos a MariaDB.

`$ sudo mariadb`

Ahora estamos en la "consola" de MariaDB, tiene sus propios comandos y sintaxis, nosotros vamos a usar los siguientes para crear un usuario, una base de datos y otras configuraciones.

Primero, vamos a crear una base de datos nueva, con el nombre que queramos, sin espacios ni s铆mbolos (al menos en mi caso, me di贸 problemas al intentar a帽adir barra baja o gui贸n).

`$ CREATE DATABASE <nombre_base_datos>;`

Ahora creamos un nuevo usuario, en el local host y con la contrase帽a que queramos.  Importante: tanto el usuario como la contrase帽a se escribir谩n entre comillas simples, pero no es el caso del local host.

`$ CREATE USER '<user_name>'@localhost IDENTIFIED BY '<password>';`

Concedemos permisos a nuestro usuario, la sintaxis es un poco rara aqu铆 tambi茅n, el nombre de la base de datos ir谩 sin comillas, pero user, pass y, ahora s铆, host estar谩n entre comillas simples.

`$ GRANT ALL ON <nombre_base_datos>.* TO '<user_name>'@'localhost' IDENTIFIED BY '<password>' WITH GRANT OPTION;` 

"Refrescamos" los privilegios de MariaDB con el comando `$ FLUSH PRIVILEGES;`.

Salimos de MariaDB con el comando `$ exit`.

Si queremos comprobar que tanto usuario como base de datos se han a帽adido correctamente, podemos acceder a MariaDB con nuestro usuario `$ mariadb -u <nombre_usuario> -p <password>` y una vez logeados, usar el comando `$ SHOW DATABASES;`.

### 8.3 - Php y WordPress

Instalamos el CGI (interfaz de entrada com煤n) y MYSQL (sistema gesti贸n de bases de datos) para PHP.

`sudo apt install php-cgi php-mysql`

Para comprobar que se instal贸 correctamente, podemos usar el comando `dpkg -ll | grep php`.

Antes de instalar `WordPress`, vamos a necesitar tener instalado en nuestro sistema el comando `wget`, ya que este nos permite recuperar archivos de servidores web, qu茅 es como vamos a descargar el archivo comprimido para instalar `WordPress`.

`sudo apt install wget`

Ahora que tenemos `wget`instalado, vamos a descargar el `.tar` que contiene el instalador y lo vamos a guardar en `/var/www/html`.

`sudo wget http://wordpress.org/latest.tar.gz -P /var/www/html`

Extraemos el contenido del `.tar` con el comando `sudo tar -xzvf /var/www/html/latest.tar.gz`

Eliminamos el archivo `.tar` que ya hemos extraido y no necesitamos con `sudo rm /var/www/html/latest.tar.gz`.

Copiamos el contenido de `/var/www/html/wordpress` a `/var/www/html` con el comando `sudo cp -r /var/www/html/wordpress/* /var/www/html`.

Borramos la carpeta `/var/www/html/wordpress`, que ha quedado vac铆a al mover antes su contenido, usando el comando `sudo rm -rf /var/www/html/wordpress`.

Ahora vamos a crear y modificar el archivo de configuraci贸n de `WordPress`, para ello primero copiamos el archivo por defecto de configuraci贸n con el comando: 

`cp /var/www/html/wp-config-sample.php /var/www/html/wp-config.php`. 

Y luego lo modificamos con `sudo nano /var/www/html/wp-config.php`.

Editamos las siguientes l铆neas: 

```
23 define( 'DB_NAME', 'database_name_here' );^M
26 define( 'DB_USER', 'username_here' );^M
29 define( 'DB_PASSWORD', 'password_here' );^M
```

A帽adimos en la 23 el nombre de nuestra base de datos creada antes en `MariaDB`, en la 24 nuestro nombre de usuario para `MariaDB` y en la siguiente su password (todo entre comillas simples).

El 煤ltimo paso para tener todos los servicios necesarios para WordPress ser谩 habilitar en `Lighttpd` los 煤ltimos m贸dulos que hemos instalado, lo que haremos con los siguientes comandos: 

```
$ sudo lighty-enable-mod fastcgi
$ sudo lighty-enable-mod fastcgi-php
$ sudo service lighttpd force-reload

```

Ya podemos ir a nuestro navegador y escribir en la barra de direcci贸n `localhost` o introducir la IP de nuestro equipo (system preferences/network/ethernet/IP address/10.13.X.X).

Nos aparece la ventana de login de Wordpress, tenemos que usar user y pass del usuario de la m谩quina virtual y ya estaremos dentro de nuestro wordpress.

### 8.4 - FTP (File Transfer Protocol)

Una opci贸n para el servicio extra que pide el subject para la parte BONUS.

Instalamos `FTP` con el comando `sudo apt install vsftpd`.

Podemos comprobar si se ha instalado correctamente con el comando `dpkg -l | grep vsftpd`. 

Permitimos la conexion por el puerto 21 `con sudo ufw allow 21`. (Luego tendremos tambi茅n que habilitarlo desde la `configuraci贸n` de nuestra m谩quina virtual en `VirtualBox`).

Establecemos la carpeta root para el usuario que se conecte v铆a `FTP` con permisos de escritura (si no, no podremos crear ni mover ningun archivo aunque estemos conectados por `FTP`). Para eso usamos los siguientes comandos:

```
$ sudo mkdir /home/<username>/ftp
$ sudo mkdir /home/<username>/ftp/files
$ sudo chown nobody:nogroup /home/<username>/ftp
$ sudo chmod a-w /home/<username>/ftp
```
Luego, editamos el archivo de configuraci贸n de `vsftpd` con el comando `sudo nano /etc/vsftpd.conf`, haciendo las siguientes modificaciones:

Descomentamos (borramos #) la l铆nea 31, `write_enable=YES` y la l铆nea 114, `chroot_local_user=YES`. 

A帽adimos las siguientes l铆neas al final del archivo:

```
userlist_enable=YES
userlist_file=/etc/vsftpd.userlist
userlist_deny=NO
allow_writeable_chroot=YES
```

鉂椻潡 Recuerda habilitar el puerto 21 desde la configuraci贸n de nuestra m谩quina virtual en VirtualBox 鉂椻潡

Ya deber铆amos tenerlo todo listo para poder conectar a nuestra m谩quina usando `$ ftp <ip_number>` desde otro terminal o equipo conecntado a la misma red y desde 茅l poder crear y modificar archivos. 

Al acceder, nos pedir谩 el login y pass de nuestro usuario en la m谩quina virtual. Una vez dentro, no podremos movernos de la carpeta "raiz", que es la carpeta que hemos establecido nosotros y que en nuestro sistema se encuentra en `/home/<user_name>/ftp`.

### 8.5 - NTP (Network Time Protocol)

Otra opci贸n (m谩s sencilla) para el servicio extra del BONUS. Muy sencillo, se trata de un servicio con el que elegimos con qu茅 servidor web queremos sincronizar el reloj de nuestro equipo. 

Instalamos el servicio `ntp` con el comando `sudo apt-get ntp`.

Habilitamos el puerto 123 para este servicio, con `sudo ufw allow 123`.

Editamos el archivo de configuraci贸n de `ntp` para a帽adir el servidor web que hemos elegido para sincronizar con nuestro reloj: `sudo nano /etc/ntp.conf`. Dentro del archivo, comenta los servidores anteriores y a帽ade el nuevo al final con un denominaci贸n de servidor antes, por ejemplo `server 0` o `pool 0` seguido de la url. Quedar铆a algo as铆: 

```
# pool 0.debian.pool.ntp.org iburst
# pool 1.debian.pool.ntp.org iburst
# pool 2.debian.pool.ntp.org iburst
# pool 3.debian.pool.ntp.org iburst
server 0.pool.ntp.org
```

Ahora tenemos que habilitar el servicio, para que se ejecute siempre desde el inicio de sesi贸n, con el comando `sudo systemctl enable ntp.service`.

Reiniciamos el servicio para que se apliquen los cambios en el manager de servicios del sistema, `sudo systemctl restart ntp`.

Por 煤ltimo, para sincronizar el reloj de nuestro equipo con el servidor podemos instalar el cliente de apt usando el comando `sudo apt install ntpdate` y luego ejecutarlo con el nombre del servidor: `sudo ntpdate -u <server_url>`.