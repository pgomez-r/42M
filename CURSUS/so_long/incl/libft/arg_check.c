/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:45:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:16:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_argtochar(int ac, char **av)
{
	char	**numbers;
	size_t	i;

	if (ac <= 1)
		return (NULL);
	if (ac == 2)
		numbers = ft_split(av[1], ' ');
	if (ac > 2)
	{
		i = 0;
		numbers = malloc(sizeof(char *) * ac);
		if (!numbers)
			return (ft_totalfree(numbers), NULL);
		while (av[i + 1])
		{
			numbers[i] = ft_strcpy(numbers[i], av[i + 1]);
			i++;
		}
		numbers[i] = NULL;
	}
	if (!ft_chkdigit(numbers))
		return (ft_totalfree(numbers), write(2, "Error\n", 6), NULL);
	return (numbers);
}

int	ft_chkdigit(char **str)
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
			if (str[i][j] == '-' || str[i][j] == '+')
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

int	ft_chkdup(t_index *index)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = 0;
	while (i < index->size_a)
	{
		j = 0;
		flag = 0;
		while (j < index->size_a)
		{
			if (index->array_a[i] == index->array_a[j])
				flag++;
			j++;
		}
		if (flag > 1)
			return (0);
		i++;
	}
	return (1);
}

int	ft_chksort(t_index *index)
{
	size_t	i;

	if (index->arrlen <= 1)
		return (0);
	i = 0;
	while (i < (index->arrlen - 1))
	{
		if (index->array_a[i] > index->array_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
