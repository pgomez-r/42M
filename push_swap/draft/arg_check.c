/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:45:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/23 17:12:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargs(char **numbers)
{
	int	i;
	int	j;

	if (!*numbers || !**numbers)
		return (0);
	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		while (numbers[i][j] != '\0')
		{
			if (numbers[i][j] == '-')
				j++;
			if (numbers[i][j] < '0' || numbers[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_strdlen(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	ft_checkduplicates(char **str)
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
