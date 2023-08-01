/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:11:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/07/21 18:12:07 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*PROGRAMA(incluye main) -> se permite uso de printf y atoi */

#include <stdio.h>
#include <stdlib.h>

int	ft_isprime(int num)
{
	int	i;

	i = 1;
	if (num == 2)
		return (0);
	while (++i < num)
	{
		if (num % i == 0)
			return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	num;
	int	i;
	int	flag;

	if (ac != 2)
		return (printf("\n"), 0);
	num = atoi(av[1]);
	if (num == 1)
		return (printf("%d\n", num));
	flag = 0;
	i = 1;
	while (++i <= num)
	{
		while (num % i == 0 && !ft_isprime(i))
		{	
			if (!flag)
				printf("%d", i);
			else
				printf("*%d", i);
			num = num / i;
			flag++;
		}
	}
	return (printf("\n"), 0);
}

/*Según el subject, el input (los argumentos que recibe el programa) es
siempre válido, así que no tenemos que contemplar la validación o parseo de 
argv, pero si protegemos el caso en el que se recibe más o menos de un 
argumento, en ese caso imprimimos salto de línea*/

/*Ejemplo) La factorización prima de 96 (2 • 2 • 2 • 2 • 2 • 3)*/

/*Primero hacemos una función auxiliar que devuelva si un número es primo
o no, luego empezamos un contador i en 2 (no queremos tener en cuenta el 1
porque no es ni primo ni par, y lo vamos aumentando de uno en uno hasta que
sea igual que el número que le entra al programa
Cada vez que lo aumentamos comprobamos si el número dividido por el contador
da resto 0, si es así significa que el número actual del contador es factor
de num, si además de eso resulta que ese número es primo, lo imprimimos*/