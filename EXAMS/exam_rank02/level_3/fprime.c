/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:11:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/17 21:37:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*PROGRAMA(incluye main) -> se permite uso de printf y atoi */

#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	num;
	int	i;

	if (ac != 2)
		return (printf("\n"), 1);
	num = atoi(av[1]);
	if (num == 1)
		return (printf("1\n"), 0);
	i = 1;
	while (++i <= num)
	{
		if (num % i == 0)
		{
			printf("%d", i);
			if (i != num)
				printf("*");
			num = num / i;
			i = 1;
		}
	}
	return (printf("\n"), 0);
}

/*Según el subject, el input (los argumentos que recibe el programa) es
siempre válido, así que no tenemos que contemplar la validación o parseo de 
argv, pero si protegemos el caso en el que se recibe más o menos de un 
argumento, en ese caso imprimimos salto de línea*/

/*Número primo = aquel que solo puede dividirse sin dar resto por el mismo o 
por 1. Los primeros números primos son 2, 3, 5, 7... 
Si un número no es primo, siempre podrá descomponerse en varios números primos, 
y si ya es primo, no puede decomponserse, quedaría como está 
(parece una tontería, pero a mi me hace falta tenerlo en mente)
Ejemplo) La factorización prima de 96 (2 • 2 • 2 • 2 • 2 • 3)
		 La "factorización" de 9539 (que es primo) sería 9539 */

/*Primero protegemos el caso de número de argumentos erroneo y de que el número
sea 1, ambos con un return + printf
Luego, necesitmos dos variables int, una para usarla de iterador y la otra para
guardar el número que le entra al programa (num = itoa(av[1]))
Hacemos un bucle y empezamos con nuestro iterador a partir de 2 (ni 0 ni 1 nos
interesan porque todos los números son divisibles por ambos, no son primos)
Ahora aumentamos i hasta que sea igual que num, comprobando si en algun momento 
nnum puede dividirse por el valor que tiene i sin que de resto (num % i == 0)
Cuando se de el caso, como hemos empezado desde el valor 2 (primo) sabemos
que el valor de i en ese momento es un factor primo de num, entonces imprimimos i
y, si i no es igual a num, también el caracter '*', ya que en el momento que i 
valga lo mismo que num significara que hemos descompuesto al maximo el num
Luego, aplicamos la división a num para seguir descomponiendolo y le damos a i
valor incial de nuevo, así hasta que se complete el bucle
En el último momento de descomponer el número este va a quedar siempre en 1, ya
sea porque hemos encontrado todos sus factores primos, o porque no tenía ninguno
y el valor de i a igualado al de num, se ha dividido por si mismo y ha resultado
en 1, en ese caso no se cumple mas el bucle porque empezamos con ++i = 2*/