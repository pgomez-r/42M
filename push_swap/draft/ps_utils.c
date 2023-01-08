/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:29:35 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/06 12:06:58 by pgruz            ###   ########.fr       */
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

size_t	ft_arrlen(int *array)
{
	size_t	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
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
	
	aux = malloc(sizeof(int) * ft_arrlen(array));
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
	array = ft_simpler(array, ft_arrlen(array));
	return (array);
}