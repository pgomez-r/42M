# Funciones autorizadas Minishell

* **readline->** <readline/readline.h> <readline/history.h> Se utiliza para leer una linea de texto desde stdin(el teclado). Hay que enlazar el programa para usar esta bibllioteca usando la flag -lreadline al compilar el programa.
```C
//prototipo
char	*readline(const char *prompt);
```
* **rl_clear_history->** <readline/readline.h> <readline/history.h> Se utiliza para limpiar el historuial de comandos cuando el usuario introduce *"clear history"*.
```C
//prototipo
void	rl_clear_history(void);
```
* **rl_on_new_line->** <readline/readline.h> <readline/history.h> Se usa para informar a la biblioteca *readline* que el cursor se encuentra en una nueva linea.
```C
void	rl_on_new_line(void);
```
* **rl_replace_line->** <readline/readline.h> <readline/history.h> Reemplaza la linea de entrada con el texto dado.
```C
int rl_replace_line(const char *text, int clear_undo);
//text-> puntero a la string que reemplazará la linea actual.
//clear_undo-> int que si es != 0 indica a la biblioteca que debe guardar la linea de entrada original en el historial de deshacer.
//return (0) si todo esta OK y (-1) si no ha podido reemplazar la linea
```
* **rl_redisplay->** <readline/readline.h> <readline/history.h> Redibuja la linea de entrada actual. (Actualiza solo la visualizacion despues de que haya sido modificada por *rl_replace_line*).
```C
void rl_redisplay(void);
```
* **add_history->** <readline/readline.h> <readline/history.h> Agrega una linea de entrada del user al historial de comandos despues de ser leida por *readline*.
```C
void add_history(const char *line);
```
* **access->** Se utiliza para comprobar los permisos de acceso de un archivo. Las macros son combinables mediante '|'.
	* F_OK: Comprueba la existencia del archivo.
	* R_OK: Comprueba si el archivo tiene permisos de lectura.
	* W_OK: Comprueba si el archivo tiene permisos de escritura.
	* X_OK: Comprueba si el archivo tiene permisos de ejecución.
```C
int access(const char *pathname, int mode);
//mode = MACROS de comprobación
```
* **open->** <fcntl.h> Se utiliza para abrir un archivo y obtener un fd. Return un int que será el nº de fd o -1 si hubo un error. Siempre que se use hay que cerrar los descriptores con la función close. Las macros son combinables mediante '|'.
	* O_RDONLY: Abre el archivo solo para lectura.
	* O_WRONLY: Abre el archivo solo para escritura.
	* O_RDWR: Abre el archivo para lectura y escritura.
	* O_CREAT: Crea el archivo si no existe.
	* O_EXCL: Si O_CREAT también está especificado, la llamada a open fallará si el archivo ya existe.
	* O_TRUNC: Si el archivo ya existe y es un archivo regular, lo trunca a longitud cero.
	* O_APPEND: Los datos se añadirán al final del archivo.
```C
int open(const char *pathname, int flags);
```
* **read->** Se utiliza para leer datos de un fd. Return (el num de bytes leidos) o (-1) si hay algun error al leer el archivo. Tras su uso hay que cerrar los fd con *close*.
```C
ssize_t read(int fd, void *buf, size_t count);
//fd: Un descriptor de archivo de donde se leerán los datos.
//buf: Un puntero a un búfer donde se almacenarán los datos leídos.
//count: El número máximo de bytes que se deben leer.
```
* **close->** Cierra un fd cuando se ha terminado de usar. Return(0)->todo OK o (-1) Error.
```C
int close(int fd);
```
* **fork->** Se utiliza para crear un nuevo proceso que será una copia del proceso padre.Return(0)->todo OK o (-1) Error.
```C
pid_t fork(void);
```
* **wait->** <sys/wait.h> Hace que un proceso espere hasta que un proceso hijo termine.Return (PID del proceso hijo que terminó) o (-1) Error.
```C
pid_t wait(int *status);
//status -> puntero a un int donde se puede almacenar el estado de salida del proceso hijo, NULL si no queremos.
```
* **waitpid->** <sys/wait.h> Se usa para hacer que un proceso se espere a que termine un proceso hijo concreto. Return (PID del proceso hijo que terminó o 0 si se especificó WNOHANG) o (-1) Error.
	* WNOHANG: Si no hay ningún proceso hijo que haya terminado, waitpid retorna inmediatamente en lugar de bloquear. Esto es útil para escribir programas que necesitan hacer otras cosas mientras esperan que los procesos hijos terminen.
	* WUNTRACED y WCONTINUED: Estas opciones hacen que waitpid también retorne si uno de los procesos hijos ha sido detenido o reanudado.
```C
pid_t waitpid(pid_t pid, int *status, int options);
//pid: El PID del proceso hijo que se quiere esperar.
//status: Un puntero a un entero donde waitpid puede almacenar el estado de salida del proceso hijo.
//options: Las opciones que controlan el comportamiento de waitpid.
```
* **wait3->** Se usa para suspender un proceso hasta que el proceso hijo termine y para obtener información sobre el uso de recursos del proceso hijo. Return (PID del proceso hijo que terminó) o (-1) Error.
```C
pid_t wait3(int *status, int options, struct rusage *rusage);
//status: Un puntero a un entero donde wait3 puede almacenar el estado de salida del proceso hijo.
//options: Las opciones que controlan el comportamiento de wait3. Mismas que waitpid.
//rusage: Un puntero a una estructura rusage donde wait3 puede almacenar información sobre el uso de recursos del proceso hijo.
```
* **wait4->** Se usa para suspender un proceso hasta que un proceso hijo concreto termine y para obtener información sobre el uso de recursos del proceso hijo. Return (PID del proceso hijo que terminó) o (-1) Error.
```C
pid_t wait4(pid_t pid, int *status, int options, struct rusage *rusage);

//pid: El PID del proceso hijo que se quiere esperar.
//status: Un puntero a un entero donde wait4 puede almacenar el estado de salida del proceso hijo.
//options: Las opciones que controlan el comportamiento de wait4. Mismas que waitpid.
//rusage: Un puntero a una estructura rusage donde wait4 puede almacenar información sobre el uso de recursos del proceso hijo.
```
* **signal->** <signal.h> Se usa para cambiar el comportamiento del proceso cuando recibe una señal específica. Return (puntero a la funcion de manejo de señales anterior para esa señal) o (SIG_ERR) si Error.
```C
void (*signal(int signum, void (*handler)(int)))(int);
//signum: El número de la señal que quieres manejar.
//handler: Un puntero a la función que se debe ejecutar cuando se recibe esa señal.
```
* **sigaction->** Se utiliza para cambiar el comportamiento del proceso cuando recibe una señal específica. Es más flexible y portátil que *signal*.
```C
int sigaction(int signum, const struct sigaction *act, struct sigaction *oldact);
//signum: El número de la señal que quieres manejar.
//act: Un puntero a una estructura sigaction que especifica el nuevo comportamiento para esa señal.
//oldact: Un puntero a una estructura sigaction donde sigaction puede almacenar el comportamiento anterior para esa señal.
struct sigaction {
    void     (*sa_handler)(int);
    void     (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t   sa_mask;
    int        sa_flags;
    void     (*sa_restorer)(void);
};
//sa_handler es un puntero a la función que se debe ejecutar cuando se recibe la señal.
//sa_sigaction es un puntero a una función que se debe ejecutar cuando se recibe la señal, pero que también recibe información adicional sobre la señal.
//sa_mask es un conjunto de señales que se deben bloquear mientras se maneja la señal.
//sa_flags son opciones que controlan el comportamiento de sigaction.
//sa_restorer es un puntero a una función que se debe ejecutar después de manejar la señal. Este campo está obsoleto y no se debe usar.
```
* **kill->** Se usa para enviar una señal a un proceso o grupo de procesos. Return(0)->todo OK o (-1) Error.
```C
int kill(pid_t pid, int sig);
//pid: El PID del proceso al que quieres enviar la señal.
//sig: El número de la señal que quieres enviar.
```
* **getcwd->** Se usa para obtener el directorio de trabajo actual del proceso.
```C
char *getcwd(char *buf, size_t size);
//buf: Un puntero a un búfer donde getcwd puede almacenar el directorio de trabajo actual.
//size: El tamaño del búfer.
//Return(*bufer) o (NULL) si hubo Error.
```
* **chdir->** Se usa para cambiar el directorio de trabajo actual del proceso. Return(0)->todo OK o (-1) Error.
```C
int chdir(const char *path);
//path: Una cadena que especifica el nuevo directorio de trabajo.
```
* **stat->** Se usa para obtener información sobre un archivo. Return(0)->todo OK o (-1) Error.
```C
int stat(const char *pathname, struct stat *statbuf);
//pathname: Una cadena que especifica el nombre del archivo.
//statbuf: Un puntero a una estructura stat donde stat puede almacenar la información del archivo.
struct stat {
    dev_t     st_dev;     /* ID of device containing file */
    ino_t     st_ino;     /* inode number */
    mode_t    st_mode;    /* protection */
    nlink_t   st_nlink;   /* number of hard links */
    uid_t     st_uid;     /* user ID of owner */
    gid_t     st_gid;     /* group ID of owner */
    dev_t     st_rdev;    /* device ID (if special file) */
    off_t     st_size;    /* total size, in bytes */
    blksize_t st_blksize; /* blocksize for filesystem I/O */
    blkcnt_t  st_blocks;  /* number of 512B blocks allocated */
    time_t    st_atime;   /* time of last access */
    time_t    st_mtime;   /* time of last modification */
    time_t    st_ctime;   /* time of last status change */
};
```
