/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/21 12:31:24 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*PENDIENTE: 
	reformular rotates con el struct
	meter pruebas a fuego y cruzar dedos(operations_checker.c)*/
void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int ac, char **av)
{
	char	**numbers;
	size_t	i;
	t_index	index;

	//atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (write(2, "Error\n", 6), -1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (ft_totalfree(numbers), free(index.array_a), write(2, "SORT\n", 5), -1);
	//COMPROBACIÓN PARSEO EN PANTALLA
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < index.arrlen)
		printf ("%i ", index.array_a[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(index.array_a);
	free(index.array_b);
	return (0);
}
