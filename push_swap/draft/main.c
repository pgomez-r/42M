/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/18 13:44:05 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_leaks(void)
{
	system("leaks push_swap");
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

void	structs_free(t_index *index)
{
	free (index->array_a);
	free (index->array_b);
	free (index->array_tmp);
	free (index->lis);
	free (index->coords);
}

int	main(int ac, char **av)
{
	char	**numbers;
	t_index	index;

	//atexit(ft_leaks);
	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (write(2, "Error\n", 6), -1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (ft_totalfree(numbers), free(index.array_a), -1);
	if (index.size_a == 2)
	{
		if (index.array_a[0] > index.array_a[1])
			swap_a(&index);
		return (0);
	}
	if (index.size_a <= 5)
		sort_easy(&index);
	else
		sort_complex(&index);
	ft_printarray(&index);
	if (!ft_chksort(&index))
		printf("\nORDENADOS =)\n");
	ft_totalfree(numbers);
	structs_free(&index);
	return (0);
}
