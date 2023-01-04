/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/04 17:57:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q test");
}

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

int	main(int ac, char **av)
{
	char	**numbers;
	size_t	i;
	int		*array;
	size_t	arrlen;

	//atexit(ft_leaks);
	if (ac <= 1)
		return (printf("Error"), -1);
	if (ac == 2)
	{
		numbers = malloc(sizeof(char *) * ac);
		numbers = ft_split(av[1], ' ');
	}
	if (ac > 2)
	{
		i = 0;
		numbers = malloc(sizeof(char *) * ac);
		if (!numbers)
			return (-1);
		while (av[i + 1])
		{
			numbers[i] = ft_strcpy(numbers[i], av[i + 1]);
			i++;
		}
		numbers[i] = NULL;
	}
	if (!ft_chkarg(numbers) || !ft_chkdup(numbers) || !ft_chklimit(numbers))
		return (ft_totalfree(numbers), printf("Error"), -1);
	array = malloc(sizeof(int) * ft_strdlen(numbers));
	i = 0;
	while (numbers[i] != NULL)
	{
		array[i] = ft_atoi(numbers[i]);
		i++;
	}
	if (!ft_chksort(array, i))
		return (ft_totalfree(numbers), free(array), printf("Error"), -1);
	i = 0;
	//ahora toca simplificar los números del array
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	arrlen = ft_arrlen(array);
	i = 0;
	while (i < arrlen)
		printf ("%i ", array[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array);
	return (0);
}
