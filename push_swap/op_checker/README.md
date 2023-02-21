Log muy sencillo para probar si las funciones que ejecutan las operaciones de push_swap están funcionando bien. Compila, ejecuta el programa con una serie de números y elige que instrucción ejecutar, se mostrará el resultado en pantalla. 

`operation_log.c` es el main, está listo para compilar con el resto de archivos .c y la librería .h

`operations_db.c` , `operations_ps.c` y `operations_rot.c` son los archivos donde tengo mis funciones para las operaciones, puedes sustituirlas por las tuyas, llamarlas en el main cumpliendo su prototipo y cambiar las definiciones en la librería, compila y listo.

- El programa siempre simplifica los números que le entran.

- Si ejecutas operaciones para el stack B y este está vacío puede ocurrir segmentation fault.