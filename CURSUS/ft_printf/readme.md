Nuestra función va a replicar el comportamiento de printf (man printf), que imprime en pantalla un texto así como el valor de cualquier tipo de variable. 

Según su prototipo, recibe como parámetros una cadena de caracteres y un número indeterminado de variables de cualquier tipo, cuyo valor también imprime dentro de la cadena char, en la posición donde se hace referencia a cada variable, esta referencia se hace con especificadores de formato (%d, %s, %x, etc).Los especificadores de formato % deben coincidir en orden y tipo con las variables a las que hacen referencia, que añadimos después y separadas por comas.

`printf("Hola, el num es %d, gracias.\n", 4)` = `Hola, el num es 4, gracias.`

Además de esto, printf cuenta y devuelve (en return, aunque no sea visible) el número de caracteres que ha imprimido. Nuestra réplica debe hacer lo mismo.

El output final de printf (en pantalla, no el return de la función) es siempre una cadena char, ya que es una impresión en pantalla y también sabemos que el primer parámetro que recibe es una const char* donde se encuentran los especificadores de formato que indican el tipo de variable de los otros parámetros. 
Por lo tanto, vamos a hacer que nuestra función imprima uno a uno cada char de la cadena que entra como primer parámetro y que cuando encuentre un % dentro de esta compruebe a qué tipo de variable hace referencia, la obtenga desde los argumentos (`va_list`/`va_arg`) y luego la convierta a char, en el formato deseado, para poder imprimirla caracter a caracter en pantalla.
