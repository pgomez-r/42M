/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_log.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:30:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/23 00:14:20 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printarray(t_index *index)
{
	size_t	i;

	i = 0;
	while (i < index->size_a)
		printf ("%i ", index->array_a[i++]);
	printf ("\n^-ARRAY_A-^\n");
	i = 0;
	while (i < index->size_b)
		printf ("%i ", index->array_b[i++]);
	printf ("\n^-ARRAY_B-^\n");
}

int	main(int ac, char **av)
{
	t_index	index;
	char	**numbers;
	size_t	i;
	int		operation;

	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (write(2, "Error\n", 6), -1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (ft_totalfree(numbers), free(index.array_a), write(2, "SORTED\n", 5), -1);
	i = 0;
	while (i < index.arrlen)
		printf ("%i ", index.array_a[i++]);
	printf("\n^-ARRAY_SIMPLIFICADO-^\n");
	operation = -1;
	while (operation != 0)
	{
		printf("Introduce operación:\n");
		printf("sa = 1, sb = 2, ss = 3, pa = 4, pb = 5, ra = 6,\n");
		printf("rb = 7, rr = 8, rra = 9, rrb = 10, rrr = 11, exit = 0\n");
		scanf ("%i", &operation);
		if (operation == 0)
		{	
			ft_totalfree(numbers);
			free(index.array_a);
			free(index.array_b);
			return (printf("Taluego!"), 0);
		}
		//swap_a//
		if (operation == 1)
		{
			swap_a(&index);
			ft_printarray(&index);
		}
		//swap_b//
		if (operation == 2)
		{
			swap_b(&index);
			ft_printarray(&index);
		}
		//sswap_ab//
		if (operation == 3)
		{
			swap_ab(&index);
			ft_printarray(&index);
		}
		//push_a//
		if (operation == 4)
		{
			push_a(&index);
			ft_printarray(&index);
		}
		//push_b//
		if (operation == 5)
		{
			push_b(&index);
			ft_printarray(&index);
		}
		//rot_a//
		if (operation == 6)
		{
			rotate_a(&index);
			ft_printarray(&index);
		}
		//rot_b//
		if (operation == 7)
		{
			rotate_b(&index);
			ft_printarray(&index);
		}
		//rrot_ab//
		if (operation == 8)
		{
			rotate_ab(&index);
			ft_printarray(&index);
		}
		//revrot_a//
		if (operation == 9)
		{
			revrot_a(&index);
			ft_printarray(&index);
		}
		//revrot_b//
		if (operation == 10)
		{
			revrot_b(&index);
			ft_printarray(&index);
		}
		//rrevrot_ab//
		if (operation == 11)
		{
			revrot_ab(&index);
			ft_printarray(&index);
		}
	}
	ft_totalfree(numbers);
	free(index.array_a);
	free(index.array_b);
	return (printf("Taluego!"), 0);
}
