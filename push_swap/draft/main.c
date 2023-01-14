/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/14 14:38:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

int	main(int ac, char **av)
{
	char	**numbers;
	size_t	i;
	size_t	arrlen;
	int		*array_a;
	int		*array_b;

	//atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (printf("Error"), -1);
	array_a = ft_getarray(numbers, &arrlen);
	if (!ft_chksort(array_a, arrlen))
		return (ft_totalfree(numbers), free(array_a), printf("SORTED"), -1);
	array_b = ft_arraycalloc(arrlen);
	//COMPROBACIÓN PARSEO EN PANTALLA
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < arrlen)
		printf ("%i ", array_a[i++]);
	printf ("INT ARRAY\n");
	//COMPROBACIÓN OPERACIONES EN PANTALLA
	revrot_a(array_a, arrlen);
	i = 0;
	while (i < arrlen)
		printf ("%i ", array_a[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array_a);
	return (0);
}
