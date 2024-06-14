/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_easy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:58:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_minvalue_pos(int *array, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	flag;

	i = 0;
	while (i < len)
	{
		j = 0;
		flag = 0;
		while (j < len)
		{
			if (array[i] > array[j])
				flag++;
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (-1);
}

void	sort_three(t_index *index)
{
	int	a;
	int	b;
	int	c;

	a = index->array_a[0];
	b = index->array_a[1];
	c = index->array_a[2];
	if (a < b && b > c && c > a)
		return (swap_a(index), rotate_a(index));
	if (a < b && b > c && c < a)
		return (revrot_a(index));
	if (a > b && b < c && c < a)
		return (rotate_a(index));
	if (a > b && b < c && c > a)
		return (swap_a(index));
	if (a > b && b > c && c < a)
		return (rotate_a(index), swap_a(index));
}

void	sort_easy(t_index *index)
{
	size_t	min_pos;
	int		target;

	while (index->size_a > 3)
	{
		min_pos = ft_minvalue_pos(index->array_a, index->size_a);
		target = index->array_a[min_pos];
		if (min_pos <= index->size_a / 2)
		{
			while (index->array_a[0] != target)
				rotate_a(index);
			push_b(index);
		}
		else if (min_pos > index->size_a / 2)
		{
			while (index->array_a[0] != target)
				revrot_a(index);
			push_b(index);
		}
	}
	sort_three(index);
	return (push_a(index), push_a(index));
}
