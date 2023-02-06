/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 22:44:00 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/06 22:18:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	lis_len_index(int *array, int *array_len, int *array_i, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		array_len[i] = 1;
		j = 0;
		while (j < i)
		{
			if (array[j] < array[i] && array_len[j] + 1 >= array_len[i])
			{	
				array_len[i] = array_len[j] + 1;
				array_i[i] = j;
			}
			j++;
		}
		i++;
	}
}

int	*generate_lis(int *array, int *array_len, int *array_i, size_t size)
{
	int	i;
	int	j;
	int	lis_len;
	int	*lis;

	lis_len = ft_max_in_array(array_len, size);
	lis = malloc(sizeof(int) * lis_len);
	i = size - 1;
	while (array_len[i] != lis_len)
		i--;
	j = lis_len - 1;
	while (j >= 0)
	{	
		lis[j] = array[i];
		i = array_i[i];
		j--;
	}
	return (lis);
}

int	*ft_lis(int *array, size_t size)
{
	int		*array_len;
	int		*array_index;
	int		*lis;

	array_len = malloc(sizeof(int) * size);
	array_index = malloc(sizeof(int) * size);
	lis_len_index(array, array_len, array_index, size);
	lis = generate_lis(array, array_len, array_index, size);
	return (free(array_len), free(array_index), free(array), lis);
}
