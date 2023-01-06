/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/06 13:24:50 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q test");
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
		return (printf("Error"), -1);
	array_a = ft_getarray(numbers);
	if (!ft_chksort(array_a, ft_arrlen(array_a)))
		return (ft_totalfree(numbers), free(array_a), printf("Error"), -1);
	array_b = malloc(sizeof(int) * ft_arrlen(array_a));
	i = 0;
	while (i < ft_arrlen(array_a))
	{
		array_b[i] = 0;
		i++;
	}
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < ft_arrlen(array_a))
		printf ("%i ", array_a[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array_a);
	return (0);
}
