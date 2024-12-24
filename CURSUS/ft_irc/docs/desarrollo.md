# ft_irc desarrollo

Para la ejecución de este proyecto vamos a separarlo en cuatro partes:
* El servidor.
* El parseo de comandos.
* Los canales.
* El cliente.
Vamos a crear un MVP (un proyecto mínimo viable) con el que empezaremos a trabajar. Para ello vamos a comenzar con el server.

## The Server

* Gestión de conexiones de socket.
* Protección de las variables de nivel superior, como la contraseña del servidor. 
* Utiliza otro socket para comunicarse con el cliente.

La utilización de estos sockets implica:
* Crear el socket. La funcion *socket()* crea el socket TCP para el servidor. Establece un punto final de comunicación para que el server escuche las conexiones del cliente.
* Vincularlo a un puerto. La función *bind()* vincula el socket creado a un puerto y a una IP, esto asocia el socket con una dirección de red.
* Escuchar las conexiones entrantes. *listen()+ prepara el socket para aceptar conexiones entrantes, especifica el número máximo de conexiones que se pueden poner en cola para su aceptación.
* Aceptar las conexiones entrantes. Cada conexión aceptada es manejada por un nuevo socket, lo que permite que varios clientes interactúen con el server simultaneamente. La función *accept()* espera a que un cliente se conecte. Cuando se establece la conexión crea un nuevo socket(client_fd) para manejar la comunicacion con el cliente conectado.
* Leer datos del socket del cliente. La función *read()*  se encarga de esto recuperando los datos enviados por el cliente que luego pueden ser procesados por el server.

### Atributos

```cpp
std::string host;//Ip en la que el server escuchará conexiones entrantes.
int port;//puerto en el que el server estará escuchando
int server_socket;//socket principal, se usa para aceptar nuevas conexiones
/*Necesitamos algo para almacenar los clientes conectados(representados por su socket o ID), podria ser un mapa, un vector u otros. El mapa tiene un std::string y un int clave asociado. Podria servir bastante bien.*/
std::map<int, Client> clients;//Client es una clase la veremos mas adelante
/*Necesitamos almacenar los canales y los usuarios asociados a cada canal, de primeras probare con un std::map también*/
std::map<std::string, Channel> channels; //Channel será otra clase
/*Un conjunto de fd(sockets) para monitorear multiples conexiones simultáneas usando select(), poll() o epoll()*/
fd_set fds_set;
int max_fd; //para seguir el fd mas alto
std::string password; //contraseña del servidor
bool is_running;//flag para saber si el server esta corriendo o debe detenerse.
std::string server_name;
```

## The sockets

Son una abstracción que permite la comunicación entre diferentes procesos, ya sea en la misma máquina o en máquinas diferentes a través de una red. En el contexto del servidor los sockets se utilizan para aceptar conexiones entrantes y para comunicarse con los clientes conectados. De hecho y simplificando es un fd que permite la comunicación remota.
Hay varios tipos de sockets entre ellos los principales son:
* **Sockets de corriente**-> *SOCK_STREAM*. Utilizan el TCP (capa de transtporte) para comunicarse. Este protocolo hace cumplir una transmisión de datos confiable y conectada, a costa de un rendimiento ligeramente reducido.
* **Sockets de datagramas**-> *SOCK_DGRAM*. Utiliza UDP (capa de transporte). A diferencia de TCP, UDP permite la transmisión de datos sin conexión, que es rápida, pero sin garantia de recepción. (sin el handshake de 3 vias de TCP).

* **Conceptos clave**

1. **Creación de Socket** -> *socket()* -> return(fd) del punto de conexión.
```cpp
int socket(int domain, int type, int protocol);
/*
* domain: Especifica la familia de direcciones.
* type: Especifica el tipo de socket.
    SOCK_STREAM: Socket de flujo (TCP)
    SOCK_DGRAM: Socket de datagramas (UDP)
    SOCK_RAW: Socket sin procesar
* protocol: Especifica el protocolo a utilizar. Normalmente se establece en 0 para seleccionar el protocolo predeterminado para el tipo de socket especificado.*/
```
2. **Enlace (binding)**-> *bind()* Enlaza el socket con una IP y un puerto específico.
```cpp
    int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
/* 
* sockfd: El descriptor de archivo del socket que se va a asociar.
* addr: Un puntero a una estructura sockaddr que contiene la dirección y el puerto a los que se va a asociar el socket.
* addrlen: El tamaño de la estructura sockaddr.
```

3. **Escucha** -> *listen()* Pone el socket en modo escucha, listo para aceptar conexiones entrantes.
```cpp
int listen(int sockfd, int backlog);
/*
* sockfd-> fd del socket que se pondrá en escucha.
* backlog-> núm máximo de conexiones pendientes de estar en cola antes de rechazar nuevas conexiones
*/
```
4. **Aceptación de Conexiones** -> *accept()* acepta una conexiçon entrante y crea un nuevo socket para manejar la comunicacion con el cliente.
5. **Lectura y escritura** -> *read() y write()* leen y escriben datos en el socket.
6. **Cierre del socket** -> *close()*.

### <sys/sockets.h>

Este header define varias structs, tipos de datos y funciones para trabajar con sockets.
* **Funciones:**
    + socket(): Crea un nuevo socket.
    + bind(): Asocia un socket con una dirección específica y un puerto.
    + listen(): Pone un socket en modo de escucha, permitiendo que acepte conexiones entrantes.
    + accept(): Acepta una conexión entrante en un socket en modo de escucha.
    + connect(): Establece una conexión con un socket remoto.
    + setsockopt(): Establece opciones en un socket.
    ```cpp
    int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
    /*
    * sockfd-> fd del socket
    * level->level: El nivel en el que se define la opción. Los niveles más comunes son:
        + SOL_SOCKET: Opciones de socket a nivel de API de sockets.
        + IPPROTO_TCP: Opciones específicas del protocolo TCP.
        + IPPROTO_IP: Opciones específicas del protocolo IP.
    * optname: El nombre de la opción que se va a establecer. Algunos ejemplos comunes son:
        + SO_REUSEADDR: Permite reutilizar direcciones locales. Este es elque usaremos.
        + SO_KEEPALIVE: Habilita los mensajes de keep-alive en conexiones TCP.
        + SO_RCVBUF: Establece el tamaño del buffer de recepción.
        + SO_SNDBUF: Establece el tamaño del buffer de envío.
    * optval: Un puntero a un buffer que contiene el valor de la opción.
    * optlen: El tamaño del buffer apuntado por optval.
    */
    ```
    + getsockopt(): Obtiene opciones de un socket.
    + shutdown(): Cierra parcialmente una conexión de socket.
    + close(): Cierra un socket.
### <netinet/in.h>

Es parte de la familia de headers de la familia BSD(Berkeley Software Distribution). Define archivos y structs utilizados en programación de redes y sockets.
* Tipos definidos:
    + in_port_t-> Unsigned int de 16bits, usado para representar tipos de puerto.
    + in_addr_t-> Unsigned int de 32bits para representar direcciones IP.

* Structs definidas:
    + in_addr-> Contiene al menos el miembro s_addr de 32bits para la IP
    + sockaddr_in-> Contiene los siguientes miembros
        - sin_family-> int que indica la familia de protocolos de la IP, versión de protocolo de Internet: IPv4/IPv6 (AF_INET para IPv4)
        - sin_port-> Puerto al que nos gustaría conectarnos. Debemos proporcionar este puerto en el orden de bytes de red, no en el orden del host. Por ejemplo para conectarnos al puerto 3302, necesitaremos htons() de la siguiente manera htons(3302)-> veremos esto mas adelante.
        - sin_addr-> struct de tipo in_addr que contiene la representación int de una dirección IPv4.
        ```cpp
        struct sockaddr_in {
        sa_family_t sin_family;   // Familia de direcciones (AF_INET para IPv4)
        in_port_t sin_port;       // Puerto (en orden de bytes de red)
        struct in_addr sin_addr;  // Dirección IP (en orden de bytes de red)
        char sin_zero[8];         // Relleno para alinear con la estructura sockaddr
        };
        ```
* Macros
    El archivo <netinet/in.h> también define macros para utilizar como valores del argumento level en las funciones getsockopt() y setsockopt().

    + INADDR_ANY: Especifica que el socket debe vincularse a todas las interfaces locales disponibles. Valor: 0.0.0.0
        ```cpp
        address.sin_addr.s_addr = INADDR_ANY;
        ```
    + INADDR_LOOPBACK: Especifica la dirección de loopback(localhost). Valor 127.0.0.1
        ```cpp
        address.sin_addr.s_addr = INADDR_LOOPBACK;
        ```
    + INADDR_BROADCAST: Especifica la dirección de broadcast. Valor: 255.255.255.255
    + INADDR_NONE: Indica una dirección IP inválida. Valor: -1
        ```cpp
        if (inet_addr("invalid_ip") == INADDR_NONE) 
        {
        // Manejar dirección IP inválida
        }
        ```
    
* Funciones
    Siempre que queramos enviar y recibir datos de un ordenador a otro, debemos tener en cuenta que los sistemas pueden representar sus datos de dos formas distintas y opuestas. Tomemos como ejemplo el entero hexadecimal 2F0A(que es 12042 en decimal). Debido a su tamaño, este entero debe almacenarse en dos bytes: 2Fy 0A.
    Es lógico suponer que este entero siempre se almacenará en este orden: 2F, seguido de 0A. Este es el orden más común, conocido como “big endian”, ya que el extremo grande del número, el byte más significativo, se almacena primero. Pero este no siempre es el caso…
    En algunos sistemas, en particular aquellos con procesadores Intel o compatibles con Intel, es preferible almacenar los bytes de nuestro entero en orden inverso, con el extremo menos significativo o pequeño primero: 0Aseguido de 2F. A este ordenamiento lo llamamos “little endian”.
    El orden de bytes de la red siempre es big endian, pero el orden de bytes del host puede ser big endian o little endian, según su arquitectura.
    Para trabajar con este orden contamos con lar siguientes funciones:
    + htonl()-> Convierte un int de 32 bits del orden de bytes del host al orden de la red.
    + htons()-> Convierte un int de 16 bits del orden de bytes del host al orden de la red.
    + ntohl()-> Convierte un int de 32 bits del orden de bytes de la red al orden del host.
    + ntohs()-> Convierte un int de 32 bits del orden de bytes de la red al orden del host.

	## **<poll.h>**

	Proporciona una interfaz para la multiplexación de in/out permitiendo a los programas monitorear múltiples fd para ver si están listos para realizar operaciones de lectura/escritura. Es útil en aplicaciones que necesitan manejar múltiples conexiones de red simultaneamente (servidores).

	### **Funciones y estructuras clave**
	* **poll():** Función principal que se ultiliza para monitorear múltiples fd.
		```cpp
		int poll(struct pollfd *fds, nfds_t nfds, int timeout);
		/* 
		* fds: Un puntero a una matriz de estructuras pollfd que especifican los descriptores de archivos a monitorear y los eventos de interés.
		* nfds: El número de elementos en la matriz fds.
		* timeout: El tiempo de espera en milisegundos. Puede ser:
			* Un valor positivo para especificar el tiempo de espera.
			* 0 para retornar inmediatamente.
			* -1 para esperar indefinidamente.*/
		```
	* **struct pollfd:** Describe el fd que se va a monitorear:
		```cpp
		struct pollfd
		{
    		int fd;         // Descriptor de archivo a monitorear
   			short events;   // Eventos de interés
    		short revents;  // Eventos que ocurrieron
		};
		```	
		+ **Eventos Comunes**
			- POLLIN: Datos disponibles para leer.
			- POLLOUT: Espacio disponible para escribir.
			- POLLERR: Error en el descriptor de archivo.
			- POLLHUP: Cierre del descriptor de archivo.
* **fcntl()**
Se utiliza para realizar varias operaciones en fd. Puede cambiar las propiedades de un fd, duplicarlo y más.
```cpp
int fcntl(int fd, int cmd, ... /* arg */ );
/*
* fd: El descriptor de archivo en el que se va a realizar la operación.

* cmd: El comando que especifica la operación a realizar. Algunos comandos comunes son:
    * F_GETFL: Obtiene las banderas de estado del descriptor de archivo.
    * F_SETFL: Establece las banderas de estado del descriptor de archivo.
    * F_DUPFD: Duplica el descriptor de archivo.
    * F_GETFD: Obtiene las banderas del descriptor de archivo.
    * F_SETFD: Establece las banderas del descriptor de archivo.
arg: Un argumento opcional que se utiliza con algunos comandos.*/
```
En ft_irc lo usamos para setear la flag O_NONBLOCK  en el fd del socket del server. Esta flag setea el socket en modo no bloqueante, lo que hace que las operaciones como read() y write() en el socket retornarán inmediatamente, incluso si no hay datos disponibles para leer o la operación de escritura no se hubiera podido completar. Esto provee un mecanismo eficiente y flexible para manejar operaciones I/O de forma asíncrona sin bloquear la ejecución del programa.
Por ejemplo, si está conectado a un servidor a través de la herramienta NetCut(nc) y escribe algo en la terminal pero no presiona el botón de enviar, y luego intenta apagar el servidor, no podrá hacerlo porque hay una operación de lectura en progreso.
* **std::vector**
Plantilla de contenedor en la biblioteca estándar de C++ que proporciona una secuencia dinámica de elementos. Entre sus características contamos con:
* **Crecimiento Dinámico**: Pueden redimensionarse cuando se añaden y eliminan elementos.
* **Acceso aleatorio**: Permiten el acceso a los elementos en tiempo constante.
* **Almacenamiento contiguo**: Los elementos se almacenan en un bloque contiguo de memoria, lo que permite una buena localización de la caché.
    + **Métodos Comunes**
        * **Constructores:**
        - vector(): Constructor por defecto.
        - vector(size_type count): Constructor que crea un vector con count elementos.
        - vector(size_type count, const T& value): Constructor que crea un vector con count elementos inicializados a value.
        * **Capacidad:** 
        - size(): Devuelve el número de elementos en el vector.
        - capacity(): Devuelve el número de elementos que el vector puede contener antes de necesitar redimensionarse.
        - empty(): Devuelve true si el vector está vacío.
        - reserve(size_type new_cap): Reserva espacio para al menos new_cap elementos.
        - shrink_to_fit(): Reduce la capacidad del vector para que coincida con su tamaño.
        * **Modificadores:**
        - push_back(const T& value): Añade un elemento al final del vector.
        - pop_back(): Elimina el último elemento del vector.
        - insert(iterator pos, const T& value): Inserta un elemento en la posición pos.
        - erase(iterator pos): Elimina el elemento en la posición pos.
        - clear(): Elimina todos los elementos del vector.
        - resize(size_type count): Cambia el tamaño del vector a count elementos.
        * **Acceso a Elementos:**
        - operator[](size_type pos): Accede al elemento en la posición pos.
        - at(size_type pos): Accede al elemento en la posición pos con verificación de límites.
        - front(): Devuelve una referencia al primer elemento.
        - back(): Devuelve una referencia al último elemento.
        - data(): Devuelve un puntero al bloque de memoria subyacente.
        * **Iteradores:**
        - begin(): Devuelve un iterador al primer elemento.
        - end(): Devuelve un iterador al elemento siguiente al último.
        - rbegin(): Devuelve un iterador inverso al último elemento.
        - rend(): Devuelve un iterador inverso al elemento anterior al primero.
* **std::map**
std::map es una plantilla de contenedor en la biblioteca estándar de C++ que almacena pares clave-valor ordenados. Cada clave en un std::map es única, y los elementos se ordenan automáticamente según la clave.

* **Características Principales**
* Ordenado: Los elementos se almacenan en orden ascendente según las claves.
* Acceso Rápido: Permite el acceso, inserción y eliminación de elementos en tiempo logarítmico.
* Claves Únicas: Cada clave en el mapa es única.
* Métodos Comunes
Aquí tienes una lista de algunos de los métodos más comunes de std::map:
    * Constructores:
    - map(): Constructor por defecto.
    - map(const map& other): Constructor de copia.
    - map(map&& other): Constructor de movimiento.
    * Capacidad:
    - size(): Devuelve el número de eementos en el mapa.
    - empty(): Devuelve true si el mapa está vacío.
    * Modificadores:
    - insert(const value_type& value): Inserta un elemento en el mapa.
    - erase(iterator pos): Elimina el elemento en la posición pos.
    - clear(): Elimina todos los elementos del mapa.
    - emplace(Args&&... args): Construye y añade un nuevo elemento al mapa.
    * Acceso a Elementos:
    - operator[](const key_type& key): Accede al valor asociado con la clave key. Si la clave no existe, se crea un nuevo elemento.
    - at(const key_type& key  * ): Accede al valor asocido con la clave key con verificación de límites.
    * Operaciones de Búsqueda:
    - find(const key_type& key): Devuelve un iterador al elemento con la clave key, o end() si no se encuentra.
    - count(const key_type& key): Devuelve el número de elementos con la clave key (siempre será 0 o 1).
    * Iteradores:
    - begin(): Devuelve un iterador al primer elemento.
    - end(): Devuelve un iterador al elemento siguiente al último.
    - rbegin(): Devuelve un iterador inverso al último elemento.
    - rend(): Devuelve un iterador inverso al elemento anterior al primero.
* **Declaración:**
```cpp
    #include <map>
    std::map<std::string, int> myMap;
```

## Conexión cliente-servidor:

Para aceptar conexiones entrantes necesitamos hacer que el socket sea pasivo. Vamos a ver la diferencia entre socket pasivo y activo en una comunicación de red:
* **Socket Activo(IRC CLIENT)**
Representa la conexión del lado del cliente en un servidor IRC. El cliente inicia la comunicación  conectandose al server usando una conexión TCP/IP. Una vez conectado, el cliente puede enviar comandos y mensajes al server y recibir respuestas. El socket del cliente maneja el input del user, envia mensajes al server y procesa las respuestas del server.
* **Socket Pasivo(IRC SERVER)**
Representa la escucha del servidor que acepta las conexiones entrantes desde los clientes. El server escucha las conexiones entrantes de un puerto especifico, cuando una petición de conexión es recibida, el server acepta la conexión creando un nuevo socket para la comunicación con ese cliente. El socket del server maneja múltiples conexiones de clientes simultaneamente, manejando comandos y mensajes desde cada cliente conectado y mensajes de broadcast para tantos clientes como sea necesario.
Para hacer nuestro server pasivo podemos usar la llamada a sistema listen().



# Ejecución
1. Debemos hacer make en el directorio del proyecto para que compile y cree el ejecutable.
2. Ejecutamos con los parámetros necesarios.
```bash
./ircsrv <port> <password>
```
3. Abrimos un nuevo terminal, que será nuestro cliente y trabajaremos con netcat:
```bash
nc <port> <password>
```


## recv
Es una función usada en programación con sockets para recibir datos de un socket conectado. Comúnmente es usada en la comunicación por sockets con el protocolo TCP para leer los datos mandados la conexón remota.
```cpp
ssize_t recv(int sockfd, void* buf, size_t len, int flags)
/**
 * sockfd-> el fd del socket del que recibimos los datos.
 * buf-> Un untero al buffer donde almacenamos los datos recibidos.
 * len-> El máximo número de bytes a recibir y almacenar en el buffer.
 * flags-> Flags opcionales para controlar el comportamiento de la función
 *  * MSG_WAITALL
 *  * MSG_DONTWAIT
 *  * MSG_PEEK
 *  * MSG_TRUNK
 * Seleccionando las flags correctas podemos adaptar la operación de recepción a nuestras necesidades hacienla mas versatil y eficiente.*/
 ```