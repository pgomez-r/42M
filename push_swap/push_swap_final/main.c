/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/21 22:35:21 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	numbers = ft_argtochar(ac, av);
	if (!numbers)
		return (-1);
	ft_getarrays(numbers, &index);
	if (!ft_chksort(&index))
		return (easy_free(&index, numbers), 1);
	if (index.size_a == 2)
		return (swap_a(&index), easy_free(&index, numbers), 0);
	else if (index.size_a <= 5)
		return (sort_easy(&index), easy_free(&index, numbers), 0);
	else
		return (sort_complex(&index), complex_free(&index, numbers), 0);
}
