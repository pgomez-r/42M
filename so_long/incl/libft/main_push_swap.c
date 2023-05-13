/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 17:23:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/26 22:01:28 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
		return (1);
	if (ft_getarrays(numbers, &index))
		return (ft_totalfree(numbers), write(2, "Error\n", 6), 1);
	if (!ft_chkdup(&index))
		return (easy_free(&index, numbers), write(2, "Error\n", 6), 1);
	if (!ft_chksort(&index))
		return (easy_free(&index, numbers), 1);
	if (index.size_a == 2)
		return (swap_a(&index), easy_free(&index, numbers), 0);
	else if (index.size_a <= 5)
		return (sort_easy(&index), easy_free(&index, numbers), 0);
	else
		return (sort_complex(&index), complex_free(&index, numbers), 0);
}
