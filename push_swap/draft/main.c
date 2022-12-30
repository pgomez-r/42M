/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/30 13:19:04 by pgomez-r         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	char	**numbers;
	size_t	i;
	int		*array;

	atexit(ft_leaks);
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
	if (!ft_checkargs(numbers))
		return (ft_totalfree(numbers), printf("Error"), -1);
	if (!ft_checkduplicates(numbers))
		return (ft_totalfree(numbers), printf("Error"), -1);
	array = malloc(sizeof(int) * ft_strdlen(numbers));
	i = 0;
	while (numbers[i] != NULL)
	{
		array[i] = ft_atoi(numbers[i]);
		if (array[i] > INT_MAX || array[i] < INT_MIN)
			return (ft_totalfree(numbers), free(array), printf("Error"), -1);
		//aquí compruebo, si atoi se encuentra con max o min int, abortamos
		//problema(creo), que ahora atoi devuelve long, pero array es tamaño int?
		i++;
	}
	if (!ft_checksorted(array, i))
		return (ft_totalfree(numbers), free(array), printf("Error"), -1);
	i = 0;
	while (numbers[i])
		printf ("%s ", numbers[i++]);
	printf ("CHAR STRING\n");
	i = 0;
	while (i < sizeof(array))
		printf ("%i ", array[i++]);
	printf ("INT ARRAY\n");
	ft_totalfree(numbers);
	free(array);
	return (0);
}
