/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:45:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/04 18:24:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strdlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_chkarg(char **str)
{
	int	i;
	int	j;

	if (!*str || !**str)
		return (0);
	i = 0;
	while (str[i] != NULL)
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] == '-')
			{
				if (str[i][j - 1] >= '0' && str[i][j - 1] <= '9')
					return (0);
				j++;
			}
			if (str[i][j] < '0' || str[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_chkdup(char **str)
{
	size_t	i;
	size_t	j;
	int		ctr;
	size_t	len;

	if (!*str || !**str)
		return (0);
	len = ft_strdlen(str);
	i = 0;
	while (i < len)
	{
		j = 0;
		ctr = 0;
		while (j < len)
		{	
			if (!ft_strcmp(str[i], str[j]))
				ctr++;
			j++;
		}
		if (ctr > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_chksort(int *array, size_t array_len)
{
	size_t	i;

	if (array_len <= 1)
		return (0);
	i = 0;
	while (i < array_len)
	{
		if (array[i] > array[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_chklimit(char **str)
{
	size_t	i;
	size_t	len;

	if (!*str || !**str)
		return (0);
	len = ft_strdlen(str);
	i = 0;
	while (i < len)
	{
		if (ft_strlen(str[i]) >= 11 && ft_strcmp(str[i], "2147483647") > 0)
			return (0);
		if (ft_strlen(str[i]) >= 12 && ft_strcmp(str[i], "-2147483648") > 0)
			return (0);
		i++;
	}
	return (1);
}
