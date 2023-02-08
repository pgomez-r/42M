/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/08 23:25:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis_stack(t_index *index)
{
	size_t	min_pos;
	int		target;

	index->array_tmp = ft_duparray(index->array_a, index->size_a);
	min_pos = ft_minvalue_pos(index->array_tmp, index->size_a);
	target = index->array_tmp[min_pos];
	if (min_pos <= index->size_a / 2)
	{
		while (index->array_tmp[0] != target)
			muted_rotate_a(index);
	}
	if (min_pos > index->size_a / 2)
	{
		while (index->array_tmp[0] != target)
			muted_revrot_a(index);
	}
	index->lis = (ft_lis(index->array_tmp, index->size_a, &index->size_lis));
	free(index->array_tmp);
}

void	lis_comparepush(t_index *index)
{
	int	i;
	int	j;

	while (index->size_a != index->size_lis)
	{
		i = index->array_a[0];
		j = index->array_a[index->size_a - 1];
		if (!ft_isinarray(i, index->lis, index->size_a))
			push_b(index);
		else if (!ft_isinarray(j, index->lis, index->size_a))
		{
			revrot_a(index);
			push_b(index);
		}
		else
			rotate_a(index);
	}
}

void	sort_complex(t_index *index)
{
	ft_lis_stack(index);
	lis_comparepush(index);
}

// int	get_mid_value(int *array, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		*array_aux;
// 	int		aux;

// 	array_aux = ft_duparray(array, len);
// 	i = 1;
// 	while (i < len)
// 	{
// 		j = i - 1;
// 		while (array_aux[i] < array_aux[j] && j >= 0)
// 		{
// 			aux = array_aux[i];
// 			array_aux[i] = array_aux[j];
// 			array_aux[j] = aux;
// 			j--;
// 		}
// 		i++;
// 	}
// 	aux = array_aux[len / 2];
// 	free(array_aux);
// 	return (aux);
// }

// void	mid_alg(int *array_a, int *array_b, size_t arrlen)
// {
// 	size_t	i;
// 	int		mid_value;
// 	int		max_reps;

// 	i = 0;
// 	max_reps = 0;
// 	while (i < arrlen && max_reps < mid_value)
// 	{
// 		mid_value = get_mid_value(array_a, arrlen);
// 		if (array_a[0] < mid_value)
// 		{
// 			push_b(array_a, array_b, arrlen);
// 			max_reps++;
// 		}
// 		else if (array_a[arrlen] < mid_value)
// 		{
// 			revrot_a(array_a, arrlen);
// 			push_b(array_a, array_b, arrlen);
// 			max_reps++;
// 		}
// 		else
// 			rotate_a(array_a, arrlen);
// 		i++;
// 	}
// }

/*ESTA FUNCION SE PUEDE ADAPTAR PARA LIS_CHECK*/
