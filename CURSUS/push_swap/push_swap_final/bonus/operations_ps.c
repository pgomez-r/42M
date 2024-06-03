/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_ps.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:29:35 by pgruz             #+#    #+#             */
/*   Updated: 2023/02/19 12:24:23 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	swap_a(t_index *index)
{
	int	aux;

	if (index->size_a <= 1)
		return ;
	aux = index->array_a[0];
	index->array_a[0] = index->array_a[1];
	index->array_a[1] = aux;
}

void	swap_b(t_index *index)
{
	int	aux;

	if (index->size_b <= 1)
		return ;
	aux = index->array_b[0];
	index->array_b[0] = index->array_b[1];
	index->array_b[1] = aux;
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
}
