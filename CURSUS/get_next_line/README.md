La función `get_next_line` tiene que leer una línea dentro de un fichero, al que accede por medio de un file descriptor `fd` que le entra como parámetro. Es decir, accede a un archivo, que tendrá texto, y comienza a leer caracteres hasta que encuentre un fin de línea `\n`.

La particularidad de la función es que, además de leer una línea hasta `\n`, también tiene que "recordar" hasta que posición del fichero ha leido cada vez que se ejecuta, para que cuando llamemos a la función esta lea la línea siguiente a la de la vez anterior.

Para desarrollar este proyecto vamos a necesitar comprender y aprender a implementar varios conceptos: file descriptors `fd`, funciones `open` y `read`, `variables estáticas`.
