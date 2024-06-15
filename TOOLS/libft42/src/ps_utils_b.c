/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:12:52 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:22 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	muted_rotate_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_tmp[0];
	i = 0;
	while (i < index->size_a - 1)
	{
		index->array_tmp[i] = index->array_tmp[i + 1];
		i++;
	}
	index->array_tmp[i] = aux;
}

void	muted_revrot_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_tmp[index->size_a - 1];
	i = index->size_a - 1;
	while (i > 0)
	{
		index->array_tmp[i] = index->array_tmp[i - 1];
		i--;
	}
	index->array_tmp[i] = aux;
}

int	ft_isinarray(int num, int *array, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (num == array[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_max_in_array(int *array, size_t size)
{
	size_t	i;
	int		max;

	max = array[0];
	i = 1;
	while (i < size)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}

size_t	ft_maxvalue_pos(int *array, size_t len)
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
			if (array[i] < array[j])
				flag++;
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (-1);
}
