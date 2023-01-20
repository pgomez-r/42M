/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/17 13:13:58 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_duparray(int *array, size_t arrlen)
{
	size_t	i;
	int		*array_aux;

	array_aux = malloc(sizeof(int) * arrlen);
	i = 0;
	while (i < arrlen)
	{
		array_aux[i] = array[i];
		i++;
	}
	return (array_aux);
}

int	get_mid_value(int *array_a, size_t arrlen)
{
	size_t	i;
	size_t	j;
	int		*array_aux;
	int		aux;

	array_aux = ft_duparray(array_a, arrlen);
	i = 1;
	while (i < arrlen)
	{
		j = i - 1;
		while (array_aux[i] < array_aux[j] && j >= 0)
		{
			aux = array_aux[i];
			array_aux[i] = array_aux[j];
			array_aux[j] = aux;
			j--;
		}
		i++;
		j = i -1;
	}
	return (array_aux[arrlen / 2]);
}

void	mid_alg(int *array_a, int *array_b, size_t arrlen)
{
	size_t	i;
	int		mid_value;
	int		max_reps;

	i = 0;
	max_reps = 0;
	while (i < arrlen && max_reps < mid_value)
	{
		mid_value = get_mid_value(array_a, arrlen);
		if (array_a[0] < mid_value)
		{
			push_b(array_a, array_b, arrlen);
			max_reps++;
		}
		else if (array_a[arrlen] < mid_value)
		{
			revrot_a(array_a, arrlen);
			push_b(array_a, array_b, arrlen);
			max_reps++;
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
