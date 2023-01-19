/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:29:35 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/19 14:43:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_index *index)
{
	size_t	aux;

	if (index->size_a <= 1)
		return ;
	aux = index->array_a[0];
	index->array_a[0] = index->array_a[1];
	index->array_a[1] = aux;
	write(1, "sa\n", 3);
}

void	swap_b(t_index *index)
{
	size_t	aux;

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
	int		*ptr;
	size_t	i;

	if (index->size_b == 0)
		return ;
	ptr = index->array_a;
	while (*ptr != 0)
		ptr++;
	while (*ptr != index->array_a[0])
	{
		*ptr = *(ptr - 1);
		ptr--;
	}
	*ptr = index->array_b[0];
	ptr = index->array_b;
	i = 0;
	while (*ptr != 0 && i < (index->arrlen - 1))
	{
		*ptr = *(ptr + 1);
		ptr++;
		i++;
	}
	if (i == (index->arrlen - 1))
		index->array_b[i] = 0;
	write(1, "push_a\n", 7);
}

void	push_b(t_index *index)
{
	int		*ptr;
	size_t	i;

	if (index->size_a == 0)
		return ;
	ptr = index->array_b;
	while (*ptr != 0)
		ptr++;
	while (*ptr != index->array_b[0])
	{
		*ptr = *(ptr - 1);
		ptr--;
	}
	*ptr = index->array_a[0];
	ptr = index->array_a;
	i = 0;
	while (*ptr != 0 && i < (index->arrlen - 1))
	{
		*ptr = *(ptr + 1);
		ptr++;
		i++;
	}
	if (i == (index->arrlen - 1))
		index->array_a[i] = 0;
	write(1, "push_b\n", 7);
}

// 4 8 2 6 0 0 0  A
// 1 5 9 0 0 0 0  B