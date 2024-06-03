/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:28 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	calc_moves_in_a(t_index *index, int n)
{
	size_t	last;
	size_t	i;

	last = index->size_a - 1;
	i = 0;
	if (n > index->array_a[last] && n < index->array_a[0])
		return (i);
	while (i < index->size_a)
	{
		if (n > index->array_a[i] && n < index->array_a[i + 1])
			return ((int)i + 1);
		else if (n > index->array_a[last - 1] && n < index->array_a[last])
			return (-((int)index->size_a - last));
		i++;
		last--;
	}
	i = ft_maxvalue_pos(index->array_a, index->size_a) + 1;
	if (i == index->size_a)
		return (0);
	if (i > (index->size_a - i))
		return (-(index->size_a - i));
	return (i);
}

void	best_pos_pusha(t_index *index)
{
	size_t	i;
	int		aux[2];

	index->coords[0] = (int)index->size_a;
	index->coords[1] = (int)index->size_b;
	i = 0;
	while (i < index->size_b)
	{
		if (i <= index->size_b / 2)
			aux[1] = i;
		if (i > index->size_b / 2)
			aux[1] = (index->size_b - i) * (-1);
		aux[0] = calc_moves_in_a(index, index->array_b[i]);
		if (ft_abs_sum(index->coords[0], index->coords[1])
			> ft_abs_sum(aux[0], aux[1]))
		{
			index->coords[0] = aux[0];
			index->coords[1] = aux[1];
		}
		i++;
	}
}

void	sort_complex(t_index *index)
{
	size_t	min_value_pos;

	ft_lis_stack(index);
	lis_comparepush(index);
	while (index->size_b > 0)
	{
		best_pos_pusha(index);
		operation_maker(index);
		push_a(index);
	}
	min_value_pos = ft_minvalue_pos(index->array_a, index->size_a);
	if (min_value_pos <= index->size_a / 2)
	{
		while (min_value_pos-- > 0)
			rotate_a(index);
	}
	if (min_value_pos > index->size_a / 2)
	{
		while (min_value_pos++ < index->size_a)
			revrot_a(index);
	}
}
