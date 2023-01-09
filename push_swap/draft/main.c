/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/09 19:23:21 by pgomez-r         ###   ########.fr       */
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
	int		*array_a;
	int		*array_b;

	atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (printf("NO_ARGS"), -1);
	array_a = ft_getarray(numbers);
	if (!ft_chksort(array_a, ft_arrlen(array_a)))
		return (ft_totalfree(numbers), free(array_a), printf("SORTED"), -1);
	array_b = malloc(sizeof(int) * ft_arrlen(array_a));
	i = 0;
	while (i < ft_arrlen(array_a))
		array_b[i++] = 0;
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < ft_arrlen(array_a))
		printf ("%i ", array_a[i++]);
	printf ("INT ARRAY\n");
	i = 0;
	while (i < ft_arrlen(array_b))
		printf ("%i ", array_b[i++]);
	printf ("INT ARRAY_B\n");
	ft_totalfree(numbers);
	free(array_a);
	return (0);
}
