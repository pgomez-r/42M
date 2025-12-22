# Explicación de mini_serv

El objetivo de este documento es explicar la **lógica** detrás de `mini_serv` para comprender los pasos necesarios para construirlo desde cero, en lugar de memorizar código.

Imagina que estás construyendo una sala de chat básica. Tienes un portero (el servidor) y gente que entra y sale (los clientes).

## 1. El Concepto Principal: `select()`

Lo más importante de este ejercicio es la función `select`.
Normalmente, si le dices a un programa "lee de este cliente", el programa se queda congelado esperando hasta que ese cliente hable. Si tienes 100 clientes, no puedes congelarte esperando a uno solo.

**`select`** es como un guardia de seguridad con muchas cámaras. Le das una lista de "cámaras" (clientes/sockets) y le dices: *"Avísame si alguien se mueve"*.
- Si nadie hace nada, `select` espera.
- Si alguien habla o intenta entrar, `select` te despierta y te dice: "¡Oye! Hay actividad".

## 2. La Estructura (Los ingredientes)

Para que esto funcione, necesitas preparar el terreno antes de empezar el bucle principal.

### A. La "Ficha" del Cliente (`struct s_client`)
Necesitas guardar dos cosas de cada persona que entra:
1.  Su **ID** (para decir "cliente 1 dijo hola").
2.  Un **Buzón (buffer)** (`msg`): Porque los mensajes pueden llegar a trozos. Si alguien envía "Ho" y luego "la\n", necesitas guardar "Ho" hasta que llegue el resto.

### B. Las Variables Globales (Tu mesa de trabajo)
-   `clients[2048]`: Un array para guardar las fichas de todos los posibles clientes.
-   `fd_set`: Son las listas para `select`.
    -   `current`: La lista maestra de todos los conectados.
    -   `read_set` y `write_set`: Copias de trabajo para que `select` las use.
-   `maxfd`: El número más alto de "cámara" activa (necesario para que `select` sepa hasta dónde mirar).
-   `gid`: Un contador global para dar IDs (0, 1, 2...).
-   `buffers`: Uno para recibir (`recv_buffer`) y otro para enviar (`send_buffer`).

## 3. Las Herramientas (Funciones auxiliares)

Antes del `main`, creas dos herramientas para no repetir código:

1.  **`err(msg)`**: Si algo falla fatalmente, escribes el error y cierras el programa (`exit(1)`).
2.  **`send_to_all(except)`**: Esta es clave.
    -   Recorre todos los clientes (desde 0 hasta `maxfd`).
    -   Si el cliente está listo para escribir (`FD_ISSET` en `write_set`) y **no es el que envió el mensaje** (`fd != except`), le envías el mensaje.

## 4. El Flujo del Programa (La Receta)

Ahora, dentro del `main`, sigue estos pasos lógicos:

### Paso 1: Configuración Inicial (El Portero)
1.  **Validar argumentos**: Asegúrate de que te dieron un puerto.
2.  **Crear el Socket (`socket`)**: Es como abrir la puerta del local.
3.  **Preparar la dirección (`servaddr`)**: Dices "escucharé en 127.0.0.1" y en el puerto que me digan.
4.  **Bind y Listen**:
    -   `bind`: Pegas el socket a esa dirección.
    -   `listen`: Le dices al sistema operativo "empieza a aceptar gente".
5.  **Inicializar `select`**:
    -   Limpias la lista maestra (`FD_ZERO`).
    -   Añades tu propio socket (`sockfd`) a la lista. Él es el primero, porque es el que recibe a los nuevos.
    -   `maxfd` empieza siendo tu socket.

### Paso 2: El Bucle Infinito (La Fiesta)
Aquí es donde ocurre la magia. Todo esto va dentro de un `while(1)`.

1.  **Copiar las listas**: `select` es destructivo (borra lo que no tiene actividad), así que siempre copias `current` en `read_set` y `write_set` antes de llamar a `select`.
2.  **Llamar a `select(...)`**: El programa se pausa aquí hasta que pase algo.
3.  **El Barrido (`for fd = 0` hasta `maxfd`)**:
    Cuando `select` vuelve, recorres todos los números posibles para ver quién activó la alarma (`FD_ISSET`).

    Hay **dos casos** posibles cuando alguien activa la alarma de lectura (`read_set`):

    **CASO A: Es el socket del servidor (`fd == sockfd`)**
    -   ¡Alguien nuevo quiere entrar!
    -   Aceptas la conexión (`accept`).
    -   Actualizas `maxfd` si es necesario.
    -   Le das un ID (`gid++`).
    -   Lo añades a la lista maestra (`FD_SET`).
    -   Avisas a todos: "server: client X just arrived\n".

    **CASO B: Es un cliente existente (`fd != sockfd`)**
    -   ¡Alguien está hablando! Lees su mensaje con `recv`.
    -   **Opción 1: `recv <= 0` (Se fue)**
        -   Avisas a todos: "server: client X just left\n".
        -   Lo borras de la lista (`FD_CLR`) y cierras su socket (`close`).
        -   Limpias su buffer.
    -   **Opción 2: `recv > 0` (Envió texto)**
        -   Aquí está el truco del buffer. No puedes enviar directamente lo que recibes porque puede estar incompleto.
        -   Recorres lo recibido byte a byte y lo vas copiando en `clients[fd].msg`.
        -   **Si encuentras un `\n`**:
            -   Significa que el mensaje terminó.
            -   Pones un `\0` al final para hacerlo string válido.
            -   Preparas el mensaje: "client X: [mensaje]".
            -   Usas `send_to_all` para enviarlo.
            -   Limpias el buffer de ese cliente para el siguiente mensaje.

## Resumen para tu Prueba Técnica

Para reproducirlo de memoria, recuerda este esqueleto:

1.  **Structs y Globals**: Array de clientes, buffers grandes, fd_sets.
2.  **Main**: Socket -> Bind -> Listen -> FD_SET(sockfd).
3.  **While(1)**:
    -   `select` (¡recuerda copiar los sets antes!).
    -   `for` loop (0 a maxfd).
    -   `if (FD_ISSET)`:
        -   ¿Es `sockfd`? -> `accept` (Nuevo cliente).
        -   ¿Es otro? -> `recv` (Mensaje).
            -   ¿`<= 0`? -> Desconexión.
            -   ¿`> 0`? -> Bucle copiando al buffer del cliente. Si ves `\n`, envías y limpias.
