/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/16 14:51:45 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mid_alg(int *array_a, int *array_b, size_t arrlen)
{
	size_t	i;
	int		mid_value;

	mid_value = array_a[arrlen / 2];
	i = 0;
	while (i < arrlen)
	{
		if (array_a[0] < mid_value)
			push_b(array_a, array_b, arrlen);
		else if (array_a[arrlen] < mid_value)
		{
			revrot_a(array_a, arrlen);
			push_b(array_a, array_b, arrlen);
		}
		else
			rotate_a(array_a, arrlen);
		i++;
	}
}

void	ft_calculator(int *array_a, int *array_b, size_t arrlen)
{
	size_t	current_len;
	int		flag;

	flag = 1;
	current_len = 0;
	while (flag)
	{
		while (array_a[current_len] != 0)
			current_len++;
		if (current_len > 2)
			mid_alg(array_a, array_b, arrlen);
			//aqui controlar los chunks
		else if (current_len == 2 && array_a[0] > array_a[1])
		{
			swap_a(array_a, arrlen);
			flag = 0;
		}
		else
			flag = 0;
	}
	//llevar controlados los chunks de B ->
}

void	sort_few(int *array_a, int *array_b, size_t arrlen)
{

}

void	sort_all(int *array_a, int *array_b, size_t arrlen)
{
	
}
