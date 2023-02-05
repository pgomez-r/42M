# LIS -> Longest increasing subsequence

## Encontrando LIS con programación dinámica

[Tutorial_EN](https://cp-algorithms.com/sequences/longest_increasing_subsequence.html)

- `array_a` = array inicial/original, del que queremos calcular su LIS, primero en tamaño y luego para devolver un array con todos los elementos que forman esa subsecuencia

- `size_a`= número total de elementos del array original

- `array_a[0 ... size_a - 1]` = vamos a comprobar cada indice del array `array_a[0]`, `array_a[1]`, ... hasta el último, que sería `size - 1 `(si size es 10 tenemos 10 elemtnos, pero el último índice es el 9, ya que empezamos por el índice 0)

- `array_lis` = creamos un array con el mismo tamaño que `array_a` (malloc(sizeof)...), en cada índice de este nuevo array lo que vamos a guardar es el número de elementos que tendría la mayor subsecuencia creciente (LIS) posible que terminase en ese mismo índice de la cadena original. Ejemplo:

``array_a = {8,3,4,6,5,2,0,7,9,1}
array_lis = {1,1,2,2,3,1,1,4,5,2}

Si calculasemos cual sería la mayor subsecuencia creciente hasta llegar a `array_a[4]` (`array_a[4] = 6`) esta sería de 3 elementos {3, 4, 5}, en `array_A[8] = 9`, `array_lis[8] = 5`, y las cadenas crecientes posibles serían o bien {3, 4, 5, 7, 9} o {3, 4, 6, 7, 9}.``

- Calculamos cada LIS desde `array_lis[0]` hasta `array_lis[size_a - 1]`. Al final, el índice con mayor número será el tamaño/longitud del LIS real de la cadena `array_a`
