# Ft_irc
En este proyecto vamos a implementar un **servidor IRC**(Internet Relay Chat), un protocolo de chat que permite la comunicación en tiempo real a través de canales de texto. Vamos a ver en líneas generales lo que debemos conocer para luego ir ampliando información a medida que investiguemos.
Con este proyecto adqueriremos experiencia con la gestión de redes y el desarrollo orientado a sistemas distribuidos, aplicando conceptos avanzados de programación en C++, como la gestión de sockets, concurrencia y el manejo de eventos asíncronos, lo que involucra un entendimiento profundo de los protocolos TCP/IP y la arquitectura cliente-servidor.
Nos enfrentaremos a desafíos relacionados con la seguridad, el manejo eficiente de conexiones, interpretación de comandos IRC standar(RFC 1459) y la sincronización entre multiplesusuarios conectados simultáneamente.Está descrito en la RFC 1459.
* **RFC 1459**-> Internet Relay Chat Protocol, es el documento que define formalmente el protocolo IRC y establece las reglas y convenciones que deben seguir los clientes y servidores para interactuar en una red IRC.

El protocolo IRC (Internet Relay Chat) es un protocolo de comunicación en tiempo real diseñado para permitir la interacción entre múltiples usuarios a través de canales de chat o mensajes directos. Define cómo los clientes y servidores deben interactuar , así como los comandos y las respuestas que se intercambian para permitir la comunicación en un sistema distribuido. Aspectos más importantes del protocolo:

1. **Arquitectura del Protocolo IRC**
Cliente-servidor
* Clientes-> Usuarios que se conectan al servidor mediante software cliente.
* Servidores-> Intermediarios que permiten la conexión de múltiples clientes y la transmisión de mensajes entre ells. Pueden estar conectados entre sí para formar redes IRC.

**Componentes clave:**
* **Usuarios**-> Se conectan al servidor IRC a través de un cliente y se identifican mediante un *NICK*.
* **Canales**-> Son las salas de chat donde varios usuarios pueden comunicarse al mismo tiempo, los nombres comienzan con # o &.
* **Operadores**-> Usuarios con privilegios aministrativos dentro de un canal o la red IRC completa. Pueden administrar usuarios, moderar conversaciones y aplicar restricciones.

