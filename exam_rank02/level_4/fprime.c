/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:11:04 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/07/11 20:06:01 by pgruz            ###   ########.fr       */
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
	// if (num == 1)
	// 	return (printf("1\n"), 0);
	flag = 0;
	i = 1;
	while (++i <= num)
	{
		if (num % i == 0 && ft_isprime(num) == 0 && flag == 0)
		{	
			printf("%d", i);
			num = num / i;
			flag++;
		}
		else if (num % i == 0 && ft_isprime(num) == 0)
		{	
			printf("*%d", i);
			num = num / i;
		}
	}
	return (printf("\n"), 0);
}

/*Según el subject, el input (los argumentos que recibe el programa) es
siempre válido, así que no tenemos que contemplar la validación o parseo de 
argv, pero si protegemos el caso en el que se recibe más o menos de un 
argumento, en ese caso imprimimos salto de línea*/

/*Ejemplo) La factorización prima de 96 (2 • 2 • 2 • 2 • 2 • 3)*/