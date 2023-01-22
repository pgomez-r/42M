/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:29:35 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/23 00:10:03 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_index *index)
{
	int	aux;

	if (index->size_a <= 1)
		return ;
	aux = index->array_a[0];
	index->array_a[0] = index->array_a[1];
	index->array_a[1] = aux;
	write(1, "sa\n", 3);
}

void	swap_b(t_index *index)
{
	int	aux;

	if (index->size_b <= 1)
		return ;
	aux = index->array_b[0];
	index->array_b[0] = index->array_b[1];
	index->array_b[1] = aux;
	write(1, "sb\n", 3);
}

void	swap_ab(t_index *index)
{
	swap_a(index);
	swap_b(index);
	write(1, "ss\n", 3);
}

void	push_a(t_index *index)
{
	size_t	i;

	if (index->size_b == 0)
		return ;
	i = index->size_a;
	while (i > 0)
	{
		index->array_a[i] = index->array_a[i - 1];
		i--;
	}
	index->array_a[i] = index->array_b[0];
	while (i < index->size_b)
	{
		index->array_b[i] = index->array_b[i + 1];
		i++;
	}
	index->size_a++;
	index->size_b--;
	write(1, "pa\n", 3);
}

void	push_b(t_index *index)
{
	size_t	i;

	if (index->size_a == 0)
		return ;
	i = index->size_b;
	while (i > 0)
	{
		index->array_b[i] = index->array_b[i - 1];
		i--;
	}
	index->array_b[i] = index->array_a[0];
	while (i < index->size_a)
	{
		index->array_a[i] = index->array_a[i + 1];
		i++;
	}
	index->size_a--;
	index->size_b++;
	write(1, "pb\n", 3);
}

// 4 8 2 6 0 0 0  A
// 1 5 9 0 0 0 0  B