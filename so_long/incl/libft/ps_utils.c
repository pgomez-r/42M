/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:35 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int	ft_getarrays(char **numbers, t_index *index)
{
	size_t		i;
	long int	aux;

	index->array_a = malloc(sizeof(int) * ft_strdlen(numbers));
	i = 0;
	while (numbers[i] != NULL)
	{
		aux = ft_atoi(numbers[i]);
		if (aux > INT_MAX || aux < INT_MIN)
			return (free(index->array_a), 1);
		index->array_a[i] = aux;
		i++;
	}
	index->arrlen = i;
	index->size_a = i;
	index->size_b = 0;
	index->array_b = malloc(sizeof(int) * index->arrlen);
	i = 0;
	while (i < index->arrlen)
		index->array_b[i++] = 0;
	index->array_a = ft_simpler(index);
	return (0);
}

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
