/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/26 20:39:06 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*PoA = encontrar valor mínimo (tenemos la funcion), rotarlo al primer puesto,
una vez allí, encontrar el LIS*/
void	min_to_top(t_index *index)
{
	size_t	min_pos;
	int		target;

	index->temp = ft_duparray(index->array_a, index->size_a);
	min_pos = ft_minvalue_pos(index->temp, index->size_a);
	target = index->temp[min_pos];
	if (min_pos <= index->size_a / 2)
	{
		while (index->temp[0] != target)
			rotate_a(index);
	}
	if (min_pos > index->size_a / 2)
	{
		while (index->temp[0] != target)
			revrot_a(index);
	}
	//calcular LIS de cadena temp
	free(index->temp);
}

int	get_mid_value(int *array, size_t len)
{
	size_t	i;
	size_t	j;
	int		*array_aux;
	int		aux;

	array_aux = ft_duparray(array, len);
	i = 1;
	while (i < len)
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
	}
	aux = array_aux[len / 2];
	free(array_aux);
	return (aux);
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
