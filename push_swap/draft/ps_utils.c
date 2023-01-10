/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:35 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/10 13:52:51 by pgomez-r         ###   ########.fr       */
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

int	*ft_simpler(int	*array, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	num;
	int		*aux;

	aux = malloc(sizeof(int) * len);
	i = 0;
	while (i < len)
	{
		j = 0;
		num = 1;
		while (j < len)
		{
			if (array[i] > array[j])
				num++;
			j++;
		}
		aux[i] = num;
		i++;
	}
	free(array);
	return (aux);
}

int	*ft_getarray(char **numbers)
{
	int		*array;
	size_t	i;

	array = malloc(sizeof(int) * ft_strdlen(numbers));
	i = 0;
	while (numbers[i] != NULL)
	{
		array[i] = ft_atoi(numbers[i]);
		i++;
	}
	array = ft_simpler(array, i);
	return (array);
}

int	*ft_arraycalloc(size_t arrlen)
{
	size_t	i;
	int		*array_b;

	array_b = malloc(sizeof(int) * arrlen);
	i = 0;
	while (i < arrlen)
		array_b[i++] = 0;
	return (array_b);
}
