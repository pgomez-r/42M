(EN PROCESO)

De momento, la idea que tengo para el proyecto es hacerlo usando arrays y seguir los siguientes pasos:

0) A medida que avanza el proyecto nos va a hacer falta usar estructuras, ya que no nos van a dar las líneas, ni tampoco podemos declarar más de 5 variables por función ni usar prototipos de funciones que reciban más de cuatro argumentos. Muy recomendable buscar y aprender a usar estructuras antes de nada, en mi caso yo guardo varios arrays dentro de la estructura y sus respectivos tamaños, es importante llevar siempre la cuenta de estos tamaños.

1) Guardar todos los argumentos que le entran al main en una tabla de cadenas char, es decir, un doble puntero `char **argumentos`. Cada cadena sería, idealmente, un número de n dígitos (3, 4345, -24...).

2) Comprobar la validaez de argumentos, es decir de cada cadena dentor de **argumentos, con varias funciones para verificar si: son dígitos (contemplando que pueda ser número negativo '-'), no hay duplicados, no hay ningún número que salga de los límites de un INT (max y min).

3) Si todas las comprobaciones están OK, pasamos a guardar el contenido de **argumentos, que ya sabemos que son número válidos, en un array INT. Alojamos memoria suficiente y hacemos un bucle de atoi hasta que cada argumentos[i] quede guardado en array[i].

4) Simplificar los números de nuestro array para que vayan desde el número 1. Ej: 4 8 2 == 2 3 1. Así evitas negativos, 0 (por si quieres usar el valor 0 como alarma para errores) y te aseguras que todos los números del array sean consecutivos entre si una vez ordenados.

5) Cuando ya tenemos nuestro array, necesitamos una función que compruebe antes de nada si el array que hemos creado ya está ordenado, para que si es así, hagamos return y listo. Si no está ordenado, alojamos memoria para un array de enteros del mismo tamaño que A, que será nuestra pila B.

6) Ya tenemos los números comprobados, guardados en array A y el array B listo. Ahora toca programar todas las operaciones que nos pide el subject e ir comprobando que se comportan como deben. Muy importante que los push actualicen los tamaños de ambos stacks, por ejemplo push_a sumaría +1 al size de A y restaría -1 al size de B.

7) Cuando estén programadas las operaciones, empezamos con la ordenación. Yo la he estructurado, de menos a más, así:
	- Array A tiene solo 2 números -> ya sabemos que no están ordenados, porque si lo estuvieran nuestra comprobación anterior ya hubiera detenido el programa, por lo tanto hacemos SA para intercambiar la posición de ambos números y return, estamos listos.

	- Array A tiene 5 o menos números -> hacemos primero una función que ordene 3 números, en ese caso solo van a darse X situaciones, hay que contemplarlas todas en esa función y que ordene cada una. La función de <=5 números manda 1 o 2 números a B, hasta quedar 3 en A, llama a la función de ordenar 3, los deja ordenados y luego devuelve los número de B en el orden correcto.

	- Array A tiene más de 5 números, aquí es donde hay que volverse loco: la idea es calcular el LIS de A primero, luego enviar a B todos los número que no pertenecen a LIS y después ir devolviendo cada número de B a A en su sitio ya ordenado. Para esto, cada vez que vayamos a mandar un número de vuelta a la pila A, hay que hacer un cálculo de cuantos movimientos tanto en A como en B habría que hacer para colocar cada número de B en su lugar correspondiente y así elegir siempre el que necesite menos movimientos.

	*LIS = longest increasing subsequence, mayor subsecuencia creciente dentro de un array de números, sin cambiar de posición ningún número. (Ej. del array {0, 4, 12, 2, 10, 6, 9, 13, 3, 11, 7, 15} el LIS sería {0, 2, 6, 9, 11, 15})

8) Cuando funcione correctamente, este método dejaría B vacío y A ordenado, aunque no desde la posición [0], puede pasar (y suele pasar) que quede ordenado a partir de una posición hasta el final y continue por el principio, por ejemplo así {8 9 10 1 2 3 4 5 6 7}. Por eso hace falta para terminar una función que encuentre en qué posición está el número de menor valor y lo haga rotar hasta la primera posición.
