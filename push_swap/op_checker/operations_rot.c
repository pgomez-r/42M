/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:35:44 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/23 15:28:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_a[0];
	i = 0;
	while (i < index->size_a - 1)
	{
		index->array_a[i] = index->array_a[i + 1];
		i++;
	}
	index->array_a[i] = aux;
	write(1, "ra\n", 3);
}

void	rotate_b(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_b[0];
	i = 0;
	while (i < index->size_b - 1)
	{
		index->array_b[i] = index->array_b[i + 1];
		i++;
	}
	index->array_b[i] = aux;
	write(1, "rb\n", 3);
}

void	revrot_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_a[index->size_a - 1];
	i = index->size_a - 1;
	while (i > 0)
	{
		index->array_a[i] = index->array_a[i - 1];
		i--;
	}
	index->array_a[i] = aux;
	write(1, "rra\n", 4);
}

void	revrot_b(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_b[index->size_b - 1];
	i = index->size_b - 1;
	while (i > 0)
	{
		index->array_b[i] = index->array_b[i - 1];
		i--;
	}
	index->array_b[i] = aux;
	write(1, "rrb\n", 4);
}

// 4 8 2 6 0 0 0  A
// 1 5 9 0 0 0 0  B