# ft_irc subject

* Debe desarrollar un servidor IRC en C++ 98.
* No debe desarrollar un cliente.
* No debe manejar la comunicación de servidor a servidor.

Su ejecutable se ejecutará de la siguiente manera:
./ircserv <port> <password>
* port: El número de puerto en el que su servidor IRC estará escuchando las conexiones
IRC entrantes.
* password: La contraseña de conexión. Será necesaria para cualquier cliente IRC que intente
conectarse a su servidor.

*Incluso si poll() se menciona en el asunto y la escala de evaluación,puede usar cualquier equivalente como select(), kqueue() o epoll().*

### Requisitos
* El servidor debe ser capaz de manejar varios clientes al mismo tiempo y nunca colgarse.
* No se permite la bifurcación. Todas las operaciones de E/S deben ser no bloqueantes.
* Solo se puede usar 1 poll() (o equivalente) para manejar todas estas operaciones (lectura, escritura, pero también escucha, etc.).

*Como debe usar descriptores de archivos no bloqueantes, es posible usar funciones de lectura/recepción o escritura/envío sin poll() (o equivalente), y su servidor no se bloquearía. Pero consumiría más recursos del sistema. Por lo tanto, si intenta leer/recibir o escribir/enviar en cualquier descriptor de archivo sin usar poll() (o equivalente), su calificación será 0.*

* Existen varios clientes de IRC. Debe elegir uno de ellos como referencia. Su cliente de referencia se usará durante el proceso de evaluación.
* Su cliente de referencia debe poder conectarse a su servidor sin encontrar ningún error.
* La comunicación entre el cliente y el servidor debe realizarse a través de TCP/IP (v4 o v6).
* El uso del cliente de referencia con el servidor debe ser similar al uso con cualquier servidor oficial de IRC. Sin embargo, solo debe implementar las siguientes características:
	+ Debe poder autenticarse, establecer un apodo, un nombre de usuario, unirse a un canal, enviar y recibir mensajes privados utilizando el cliente de referencia.
	+ Todos los mensajes enviados desde un cliente a un canal deben reenviarse a todos los demás clientes que se hayan unido al canal.
	+ Debe tener operadores y usuarios regulares.
	+ Luego, debe implementar los comandos que son específicos para los operadores de canal:
		* KICK: expulsa a un cliente del canal
		* INVITE: invita a un cliente a un canal
		* TOPIC: cambia o visualiza el tema del canal
		* MODE: cambia el modo del canal:
			* i: establece o elimina el canal solo para invitados
			* t: establece o elimina las restricciones del comando TOPIC para los operadores de canal
			* k: establece o elimina la clave del canal (contraseña)
			* o: otorga o quita privilegios de operador de canal
			* l: Establecer/eliminar el número de users para el canal.

Verifique absolutamente todos los errores y problemas posibles (recepción de datos parciales, ancho de banda bajo,
etc.). Para asegurarse de que su servidor procesa correctamente todo lo que le envía, puede realizar la siguiente
prueba simple utilizando nc:
```bash
\$> nc 127.0.0.1 6667
com^Dman^Dd
\$>
```
Use ctrl+D para enviar el comando en varias partes: ’com’, luego 'man’, luego ’d\n’.
Para procesar un comando, primero debe agregar los paquetes recibidos para reconstruirlo.

### Parte adicional(bonus)
A continuación, se muestran las funciones adicionales que puede agregar a su servidor IRC para que se parezca aún más a un servidor IRC real:
* Manejar la transferencia de archivos.
* Un bot.
La parte adicional solo se evaluará si la parte obligatoria es
PERFECTA. Perfecto significa que la parte obligatoria se ha realizado de manera integral
y funciona sin fallas. Si no has aprobado TODOS los
requisitos obligatorios, tu parte extra no será evaluada en absoluto.