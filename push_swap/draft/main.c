/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/19 12:13:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks -q push_swap");
}

void	ft_printarray(t_index *index)
{
	size_t	i;

	i = 0;
	while (i < index->size_a)
		printf ("%i ", index->array_a[i++]);
	printf ("\n^-ARRAY_A-^\n");
	i = 0;
	while (i < index->size_b)
		printf ("%i ", index->array_b[i++]);
	printf ("\n^-ARRAY_B-^\n");
}

void	complex_free(t_index *index, char **numbers)
{
	ft_totalfree(numbers);
	free (index->array_a);
	free (index->array_b);
	free (index->lis);
	free (index->array_tmp);
}

void	easy_free(t_index *index, char **numbers)
{
	ft_totalfree(numbers);
	free (index->array_a);
	free (index->array_b);
}

int	main(int ac, char **av)
{
	char	**numbers;
	t_index	index;

	atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (-1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (easy_free(&index, numbers), -1);
	if (index.size_a == 2)
	{
		if (index.array_a[0] > index.array_a[1])
			swap_a(&index);
		return (easy_free(&index, numbers), 0);
	}
	else if (index.size_a <= 5)
	{	
		sort_easy(&index);
		return (easy_free(&index, numbers), 0);
	}
	else
		return (sort_complex(&index), complex_free(&index, numbers), 0);
}
