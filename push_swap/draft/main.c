/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/05 16:25:30 by pgomez-r         ###   ########.fr       */
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
	int		*array;

	atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (printf("Error"), -1);
	array = ft_getarray(numbers);
	if (!ft_chksort(array, ft_arrlen(array)))
		return (ft_totalfree(numbers), free(array), printf("Error"), -1);
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < ft_arrlen(array))
		printf ("%i ", array[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array);
	return (0);
}
