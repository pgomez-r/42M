(EN PROCESO)

De momento, la idea que tengo para el proyecto es seguir los siguientes pasos:

	1) PARSING; conseguir procesar los argumentos que entren por consola, cumpliendo los requisitos del subject, y guardarlos en un array A. Luego, crear un array B del tamaño de A.
	2) Comprobar si A ya está ordenado -> RETURN
	3) Si A <= 5; función ordenar array pequeño
	4) Si A > 5; función ordenar array grande

Para pasar los argumentos a un array de enteros, creo que puedo usar una función que sea un versión modificada de nuestro ATOI, o quizá dos funciones, una para si los números entran como argumentos separados y otra para el caso en el que entren como un solo argumento.

Para ordenar el array grande, intentaré orientarlo con una versión de radix sort, simplificando los números para evitar negativos y pasándolos a binario para que el método se corresponda con las dos pilas.

Muy provisional, me queda mucho curro T_T