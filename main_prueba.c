/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:43:23 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/10/07 13:05:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	main(void)
{
	int	n;

	n = 35542;
	ft_itoa(n);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)malloc(count * size);
	if (str == 0)
		return (0);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

int	count_char(int n)
{
	if (n == -2147483648)
		return (11);
	else if (n < 0)
		return (count_char(n * (-1)) + 1);
	else if (n < 10)
		return (1);
	else
		return (count_char(n / 10) + 1);
}

void	convert_to_char(char *sol, int size, long int num)
{
	sol[size] = '\0';
	if (num < 0)
	{
		sol[0] = '-';
		num *= -1;
		while (size > 1)
		{
			sol[size - 1] = num % 10 + '0';
			num = num / 10;
			size--;
		}
	}
	else
	{
		while (size > 0)
		{
			sol[size - 1] = num % 10 + '0';
			num = num / 10;
			size--;
		}
	}
}

char	*ft_itoa(int n)
{
	int			size;
	char		*result;
	long int	num;

	size = count_char(n);
	result = (char *)ft_calloc(size + 1, sizeof(char));
	if (!result)
		return (NULL);
	num = (long int)n;
	convert_to_char(result, size, num);
	return (result);
}
