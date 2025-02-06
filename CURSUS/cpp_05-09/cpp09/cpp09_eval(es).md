Introducción
Por favor, siga las reglas a continuación:

Manténgase educado, cortés, respetuoso y constructivo durante todo el proceso de evaluación. El bienestar de la comunidad depende de ello.

Trabaje con el estudiante o el grupo que se está evaluando para identificar posibles problemas en su proyecto. Tómese el tiempo para analizar y debatir los problemas identificados.

Comprenda que puede haber diferencias en la forma en que los compañeros interpretan las instrucciones y el alcance del proyecto. Mantenga siempre una mente abierta y califique de la manera más honesta posible. La pedagogía es eficaz solo cuando las evaluaciones de los compañeros se toman en serio.


Pautas
Por favor, siga las pautas a continuación:

Calificar únicamente el trabajo enviado al repositorio Git del estudiante o grupo evaluado.

Verifique que el repositorio Git pertenezca al estudiante y que el proyecto sea el esperado. Asegúrese de que Git clone se use en una carpeta vacía.

Verifique cuidadosamente que no se utilicen alias maliciosos para engañar al evaluador y lograr que califique contenido no oficial.

Si corresponde, revise junto con el estudiante cualquier script utilizado para pruebas o automatización.

Si no has completado la tarea que estás evaluando, lee todo el tema antes de comenzar la evaluación.

Utilice las banderas disponibles para informar sobre un repositorio vacío, un programa que no funciona, un error de Norm o trampas. El proceso de evaluación finaliza con una calificación final de 0 (o -42 por trampas). Sin embargo, excepto en casos de trampas, se anima a los estudiantes a revisar el trabajo en conjunto para identificar errores que se deben evitar en el futuro.

Recuerde que no se tolerarán errores de segmentación ni otras terminaciones inesperadas del programa durante la evaluación. Si esto ocurre, la calificación final será 0. Utilice la bandera correspondiente.

No debería ser necesario editar ningún archivo, excepto el archivo de configuración, si existe. Si es necesario editar un archivo, explique las razones al estudiante evaluado y asegúrese de que haya un acuerdo mutuo.

Verificar la ausencia de fugas de memoria. Toda la memoria asignada en el montón debe liberarse correctamente antes de que finalice el programa.

Puede utilizar herramientas como leaks, valgrind o e_fence para comprobar si hay fugas de memoria. Si encuentra fugas de memoria, marque la casilla correspondiente.

Archivos adjuntos
Descargue los archivos adjuntos a continuación:

tema.pdf
cpp_09.tgz
entrada.csv
Parte obligatoria
Pruebas preliminares
Si se sospecha que se ha hecho trampa, la evaluación se detiene aquí. Utilice la bandera "Hacer trampa" para denunciarlo. Tome esta decisión con calma, sensatez y, por favor, utilice este botón con precaución.

*Prerrequisitos*

El código debe compilarse con c++ y los indicadores -Wall -Wextra -Werror

No olvides que este proyecto debe seguir el estándar C++98. Por lo tanto, NO se espera que se utilice C++11 (y versiones posteriores).

El objetivo de este módulo es utilizar el STL. Luego, se autoriza el uso de los contenedores.

Cualquiera de estos significa que no debes calificar el ejercicio en cuestión:

Una función se implementa en un archivo de encabezado (excepto las funciones de plantilla).

Un Makefile se compila sin los indicadores necesarios y/o otro compilador que no sea C++.

Cualquiera de estos significa que debes marcar el proyecto con "Función prohibida":

Uso de una función "C" (*alloc, *printf, free).

Uso de una función no permitida en las pautas del ejercicio.

Uso de una biblioteca externa o características de versiones distintas a C++98.



Sí

No
Ejercicio 00: Intercambio de Bitcoin
Para este primer ejercicio, tendrás que buscar un makefile con las reglas de compilación habituales y los archivos solicitados en el tema.

*Revisión de código*

Verifique que exista un archivo Makefile con las reglas de compilación habituales.

Compruebe en el código que el programa utiliza al menos un contenedor.

La persona evaluada debe explicar por qué eligió utilizar este contenedor y no otro.

En caso contrario la evaluación finaliza aquí.



Sí

No
Manejo de errores
Manejo de errores

Debe ser posible utilizar un archivo vacío o con errores (existe un ejemplo básico en el tema). El programa no debe detener su ejecución antes de haber realizado las operaciones sobre todo el archivo pasado como argumento.

Puedes utilizar una fecha incorrecta.

Puede introducir un valor mayor que 1000 o menor que 0.

Si hay algún problema durante la ejecución, la evaluación se detiene aquí.



Sí

No
Uso principal
Uso principal

Ahora debes utilizar el archivo "input.csv" ubicado en la parte superior de esta página.

Puedes modificar este archivo con los valores que desees.

Debes ejecutar el programa con el archivo input.csv como parámetro.

Compare algunas fechas manualmente con el valor especificado.

Si la fecha no existe en la base de datos, el programa tendrá que utilizar la fecha inferior más cercana.



Sí

No
Ejercicio 01: Notación polaca inversa
Para este segundo ejercicio, tendrás que buscar un makefile con las reglas de compilación habituales y los archivos solicitados en el asunto.

*Revisión de código*

Verifique que exista un archivo Makefile con las reglas de compilación habituales.

Compruebe en el código que el programa utiliza al menos un contenedor.

La persona evaluada debe explicar por qué eligió utilizar este contenedor y no otro.

En caso contrario la evaluación finaliza aquí.

Si el contenedor elegido aquí está presente en el primer ejercicio entonces la evaluación se detiene aquí.



Sí

No
Uso principal
Uso principal

Comprueba que el programa se ejecuta correctamente utilizando diferentes fórmulas de tu elección.

No es necesario que el programa maneje expresiones con paréntesis o números decimales.

Si hay algún problema durante la ejecución, la evaluación se detiene aquí.



Sí

No
Uso avanzado
Comprueba que el programa se ejecuta correctamente utilizando diferentes fórmulas de tu elección.

Aquí hay algunas pruebas:

``golpe

8 9 * 9 - 9 - 9 - 4 - 1 +

> Resultado: 42


9 8 * 4 * 4 / 2 + 9 -8 -8 -1 -6 -

> Resultado: 42


1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /

> Resultado: 15

`

Puedes utilizar los ejemplos del tema si no sabes qué fórmula utilizar.

Si hay algún problema durante la ejecución, la evaluación se detiene aquí.



Sí

No

### Ejercicio 02: PmergeMe

Como es habitual, debe haber suficientes pruebas para demostrar que el programa funciona como se espera. Si no las hay, no califique este ejercicio. Si alguna clase que no sea de interfaz no está en la forma de clase canónica ortodoxa, no califique este ejercicio.

*Revisión de código*

Compruebe que se incluye un archivo Makefile con las reglas de compilación habituales.

Compruebe en el código que el programa utiliza al menos dos contenedores.

En caso contrario la evaluación finaliza aquí.

La persona evaluada debe explicar por qué eligió utilizar estos contenedores y no otros.

Compruebe en el código que el algoritmo de ordenación por combinación e inserción esté presente y se utilice para cada contenedor. Se debe utilizar el algoritmo Ford-Johnson.

Se espera una breve explicación. En caso de duda, la evaluación se detiene aquí.

Si uno de los contenedores elegidos aquí está incluido en uno de los ejercicios anteriores, la evaluación se detiene aquí.



Sí

No
Uso principal
Ahora puede comprobar manualmente que el programa funciona correctamente utilizando entre 5 y 10 números enteros positivos diferentes de su elección como argumentos del programa.

Si esta primera prueba funciona y da una secuencia ordenada de números, puedes continuar.

En caso contrario la evaluación se detiene ahora.

Ahora debes comprobar esta operación utilizando el siguiente comando como argumento del programa:

Para Linux:

``golpe

shuf -i 1-1000 -n 3000 | tr "\n" " "

`

Para OSX:

``golpe

jot -r 3000 1 1000 | tr '\n' ' '

`

Si el comando funciona correctamente, la persona evaluada debería poder explicar la diferencia de tiempo utilizada para cada contenedor seleccionado.

Si hay algún problema durante la ejecución y/o explicación la evaluación se detiene aquí.