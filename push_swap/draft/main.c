/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/23 12:31:07 by pgomez-r         ###   ########.fr       */
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
	t_index	index;

	atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (write(2, "Error\n", 6), -1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (ft_totalfree(numbers), free(index.array_a), -1);
	free(index.array_a);
	free(index.array_b);
	return (0);
}
