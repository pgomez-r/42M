# Ft_irc
En este proyecto vamos a implementar un **servidor IRC**(Internet Relay Chat), un protocolo de chat que permite la comunicación en tiempo real a través de canales de texto. Vamos a ver en líneas generales lo que debemos conocer para luego ir ampliando información a medida que investiguemos.
Con este proyecto adqueriremos experiencia con la gestión de redes y el desarrollo orientado a sistemas distribuidos, aplicando conceptos avanzados de programación en C++, como la gestión de sockets, concurrencia y el manejo de eventos asíncronos, lo que involucra un entendimiento profundo de los protocolos TCP/IP y la arquitectura cliente-servidor.
Nos enfrentaremos a desafíos relacionados con la seguridad, el manejo eficiente de conexiones, interpretación de comandos IRC standar(RFC 1459) y la sincronización entre multiplesusuarios conectados simultáneamente.


## Fases del proyecto 

1. **Investigación y planificación**

Antes de comenzar con el código debemos asegurarnos de comprender los siguientes conceptos.
* **Protocolo IRC**: Investigar la RFC 1459, que define el protocolo IRC, para entender los comandos *JOIN*, *PART*, *PRIVMSG*, *NICK*, ETC.
* **Sockets y Redes**: Familiarizarnos con el uso de sockets en TCP en C++ y la arqutectura cliente-servidor.
* **Manejo de Concurrencia**: El servidor debe ser capaz de manejar múltiples clientes de manera simultánea, por lo que tendremos que entender la programación asíncrona o multihilos.

2. **Estructura general del servidor**
Para diseñar la arquitectura del servidor necesitaremos definir los siguientes módulos:
* **Sockets**-> Gestionar la conexión con los clientes mediante sockets TCP.
* **Parsing**-> Debe interpretar los comandos recibidos por los clientes y determinar las acciones a tomar.
* **Gestión de Usuarios**-> Controla los nicks, los canales y las conexiones.
* **Comunicación**-> Envia y recibe mensajes entre clientes.
* **Seguridad**-> Implementa control de errores y seguridsd básica, como la validación de conexiones y la gestión de usuarios inactivos.
Planificar el diseño de cada uno de los módulos y discutir como interactuarán entre ellos.

3. **Implementación de Sockets**
Empezar por lo más básico estableciendo las conexiones.
* **Crear el socket del servidor**-> Configurar un socket para que escuche conexiones de un puerto específifco.
* **Aceptar conexiones**-> Manejar múltiples clientes usando select() o poll(), o mediante hilos(el uso de select es preferido por simplicidad).
* **Gestionar la desconexión de usuarios**.

4. **Parsing de comandos**
El servidor debe interpretar los comandos IRC correctamente.
* Implementar un parser que divida las cadenas recibidas en las distintas partes de un comando IRC.
* Manejar comandos clave como *NICK*, *JOIN*, *PART*, *PRIVMSG*, *KICK*, etc.

5. **Gestión de usuarios y canales**
* **Usuarios**-> Controlar el registro de usuarios con *NICK* y *USER*, asegurarse que los nicks sean únicos y gestionar los modos de usuarios(operadores, bans).
* **Canales**-> Implementar el soporte para múltiples canales, cada uno con su propia lista de usuarios y control de privilegios.

6. **Comunicación entre usuarios**
* Implementar el envio de mensajes privados *PRIVMSG* y mensajes en canales.
* Gestionar las respuestas y errores correspondientes cuando un mensaje no puede ser entregado.

7. **Gestión de eventos y concurrencia**
* Implementar un bucle principal que pueda gestionar múltiples conexiones a la vez de forma asíncrona o usando una estrategia como *select(),poll() o epoll()* sie es necesario.
* Asegurarse de que los datos se procesan de manera eficiente para evitar bloqueos o altas latencias.

8. **Errores y manejo de excepciones**
* Manejar errores de red y caídas de usuarios.
* Implementar límitea para evitar sobrecargas del servidor.(demasiada conexiones, mensajes largos...)

9. **Pruebas y validación**
* Probar el servidor con diferentes clientes como irssi o HexChat.
* Simular conexiones múltiples y pruebas de estrés para garantizar que el servidor maneje varios clientes a la vez.
* Validar que todos los comandos implementados sigan las especificaciones de la RFC 1459.