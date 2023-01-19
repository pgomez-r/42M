/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:35 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/19 12:33:18 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_totalfree(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{	
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

size_t	ft_strdlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	*ft_simpler(t_index	*index)
{
	size_t	i;
	size_t	j;
	size_t	num;
	int		*aux;

	aux = malloc(sizeof(int) * index->arrlen);
	i = 0;
	while (i < index->arrlen)
	{
		j = 0;
		num = 1;
		while (j < index->arrlen)
		{
			if (index->array_a[i] > index->array_a[j])
				num++;
			j++;
		}
		aux[i] = num;
		i++;
	}
	free(index->array_a);
	return (aux);
}

void	ft_getarrays(char **numbers, t_index *index)
{
	size_t	i;

	index->array_a = malloc(sizeof(int) * ft_strdlen(numbers));
	i = 0;
	while (numbers[i] != NULL)
	{
		index->array_a[i] = ft_atoi(numbers[i]);
		i++;
	}
	index->arrlen = i;
	index->size_a = i;
	index->size_b = i;
	index->array_b = malloc(sizeof(int) * index->arrlen);
	i = 0;
	while (i < index->arrlen)
		index->array_b[i++] = 0;
	index->array_a = ft_simpler(index);
}
