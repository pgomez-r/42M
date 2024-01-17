# Apuntes Minishell
Aqui guardaré info sintetizada sobre como iniciar el proyecto y continuarlo si cabe.

## Còmo funciona minishell:

Normalmente cada shell tiene un script que se carga desde un archivo llamado ``~/.<shell_name>rc .zshrc ó .bashrc``.

No es parte de este proyecto pero es bueno saberlo.

La entrada es a traves de ``get_next_line`` recorriendo la entrada y haciendo un ``split`` en cada línea. La primera "palabra" es el comando y el resto serian args que guardaremos en la matriz para su uso posterior.

### Dominio
Si el comando tiene un ``/``, se chequea la rut, si es correcta omitimos el siguiente paso.
De otra manera buscamos en el env una variable llamada ``$PATH``.
```shell
$> echo $PATH
/bin:/usr/bin:/home/user/.bin
```
Luego para cada comando hay que buscar en cada directorio listado en $PATH.

Para ls:
* ``ls`` no está  ``/bin/ls``.
* ``ls`` está en ``/usr/bin/ls``.
* ``/home/user/.bin``no se checkea porque ``ls`` ya se ha encontrado.

Cuando se ha encontrado el ejecutable, see crea un nuevo proceso con ``fork``, el comando se ejecuta con su arg gracias a ``execve`` y espera a que su hijo termine con ``wait``.

### Pequeños resumenes del man (traducción regulera...perdón!)
	Para info ampliada man [comando].
* ``fork`` -> Crea un nuevo proceso(hijo) que es una copia exacta del proceso padre excepto porque:
	* El hijo tiene su propio ``PID``.
	* El hijo tiene su propia copia de los descriptores del padre. Estos hacen referencia a los mismos objetos por lo que un (lseek) en un descriptor en el proceso hijo puede afectar a una lectura o escritura porterior por el padre.
	Esta copia de descriptor es usada tambien por shell para establecer entradas y salidas estandar para los procesos recien creados y los pipelines.
	* La utilización de recursos de los procesos secundarios se establecen en 0.
	
	Retorna 0 si toda ha ido bien.

* ``execve`` -> Transforma el proceso llamado en un nuevo proceso. El nuevo proceso se construye en base a un archivo ordinario, cuyo nombre indica la ruta, llamado new process file. Este archivo es un ejecutable o archivo de datos para un intèrprete. Un archivo ejecutable consta de un encabezado de id, seguido de páginas de datos que representan el programa inicial(texto) y el inicializado paginas de datos. El encabezado puede especificar páginas adicionales iniciadas a 0. Un interprete comienza con una linea con la forma:
	#! interpeter [arg ...]
Cuando un archivo intérprete es ``execve``, el sistema corre el interprete especificado. Si son especificados argumentos opcionales se convierten en primer, segundo.... El nombre del origen se convierte en el arg siguiente.
Los args para la invocación del interprete se desplazan para confertirse en argumentos finales dejando el argumento cero (nombre del archivo ejecutado) sin alterar.

* ``wait`` -> Suspende la ejecución de su proceso de llamada hasta que la información stat_loc este disponible para un proceso hijo terminado o reciba una señal. Al regresar del wait el stat_loc contiene info de terminación sobre el proceso.

### Builtins (funciones integradas)

Algún comando puede no tener el resultado deseado en un proceso hijo. Por ejemplo saliendo del shell o modificando el entorno afectaría solo al hijo y regresaría a los padres sin dejar nada.

Para estos casos shell tiene ``builtins`` que no se ejecutan en el proceso principal:
* ``exit``.
* ``setenv``.
* ``untetenv``.
* ``cd``.
Estas pueden ser incorporadas para asegurar el proyecto pero no son necesarias:
* ``echo``.
* ``env``.

Las builtin son checkeadas antes del comando, por lo que si se quiere ejecutar ``/usr/bin/env`` hay que escribir ``/usr/bin/env`` y solo ``env`` para las funciones integradas. ``man env`` y ``help env`` para ampliar info.

IMPORTANTE almacenar el valor de retorno ``$?``y devorverlo cuando salga del shell.