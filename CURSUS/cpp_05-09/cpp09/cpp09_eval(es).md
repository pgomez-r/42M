### General (prerrequisitos)

- El código debe compilarse con c++ y los indicadores -Wall -Wextra -Werror

- Este proyecto debe seguir el estándar C++98.

- El objetivo de este módulo es utilizar el STL. Se autoriza el uso de los contenedores.

*Cualquiera de estos casos significa SUSPENSO:*

- Una función se implementa (se desarrolla su código) en un archivo de encabezado .hpp (excepto las funciones template).

- Makefile compila con instrucciones diferentes a: c++ -Wall -Wextra -Werror -std=c++98

Cualquiera de estos significa que debes marcar el proyecto con *"Función prohibida"*:

- Uso de una función "C" (*alloc, *printf, free).

- Uso de una función no permitida en las pautas del ejercicio.

- Uso de una biblioteca externa o características de versiones distintas a C++98.

#### Ejercicio 00: Intercambio de Bitcoin

*Revisión de código*

- Exite un archivo Makefile con las reglas de compilación habituales.

- El código que el programa utiliza *al menos un contenedor*.

- La persona evaluada debe explicar por qué eligió utilizar este contenedor y no otro.

*Manejo de errores*
 
- Debe ser posible utilizar un archivo vacío o con errores (existe un ejemplo básico en el tema).

- El programa no debe detener su ejecución antes de haber realizado las operaciones sobre todo el archivo pasado como argumento.

- Prueba fecha incorrecta (formato no YYYY-MM-DD o dia no existente '42', etc)

- Prueba a introducir un valor mayor que 1000 o menor que 0.

*Uso principal*
- Ejecutar el programa con el archivo input.csv (adjunto al subject) como parámetro.

- Puedes modificar este archivo con los valores que desees.

- Compare algunas fechas manualmente con el valor especificado.

- Si la fecha no existe en la base de datos, el programa tendrá que utilizar la fecha inferior más cercana.

*Tricky tests*
- 2011-01-03 | 1....2 -> No es un número válido, pero muchos se lo comen como '1' y ejecutan con normalidad

- Si la fecha no existe en base de datos: ir a fecha más cercana *INFERIOR*; en mi caso he decidido también gestionar cuando una fecha es inferior que cualquiera de la base de datos, en ese caso usamos la primera fecha.

### Ejercicio 01: Notación polaca inversa
*Revisión de código*

- Existe un archivo Makefile con las reglas de compilación habituales.

- El código del programa utiliza al menos un contenedor.

- La persona evaluada debe explicar por qué eligió utilizar este contenedor y no otro.

- El contenedor elegido no puede estar en un ejercicio aterior.

*Uso principal*

- El programa se ejecuta correctamente utilizando diferentes fórmulas de tu elección.

- Subject: Your program must take an inverted Polish mathematical expression as *an argument.*

- No es necesario que el programa maneje expresiones con paréntesis o números decimales.

*Uso avanzado*

Aquí hay algunas pruebas:

./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

> Resultado: 42


./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -"

> Resultado: 42


./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /"

> Resultado: 15

*Tricky tests*

- División / 0 debe dar error.

- Inputs con operadores pegados al número:
./RPN "9 8 * 4 * 4 / 2 + 9 -8 -8 -1 -6 -"
Gestionarlo de alguna forma, o bien como invalid character/number, o interpretando los operadores como si estuvieran separados

### Ejercicio 02: PmergeMe

*Revisión de código*

- Existe un archivo Makefile con las reglas de compilación habituales.

- El código del programa utiliza al menos *dos* contenedores.

- La persona evaluada debe explicar por qué eligió utilizar estos contenedores y no otros.

- El programa usa algoritmo de ordenación por combinación e inserción y se utiliza para cada contenedor.

- Se debe utilizar el algoritmo Ford-Johnson y dar una breve explicación.

- Si uno de los contenedores elegidos aquí está incluido en uno de los ejercicios anteriores, suspenso.

*Uso principal*

- Ejectua el programa con entre 5 y 10 números enteros positivos diferentes.

- Ejecuta el programa utilizando el siguiente comando:

```
./PmergeMe `shuf -i 1-1000 -n 3000 | tr "\n" " "`
```

- Explicar la diferencia de tiempo utilizada para cada contenedor seleccionado.

