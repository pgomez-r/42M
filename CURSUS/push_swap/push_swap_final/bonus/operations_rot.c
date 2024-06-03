/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:35:44 by pgruz             #+#    #+#             */
/*   Updated: 2023/02/23 23:06:18 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_checker.h"

void	rotate_a(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_a == 0)
		return ;
	aux = index->array_a[0];
	i = 0;
	while (i < index->size_a - 1)
	{
		index->array_a[i] = index->array_a[i + 1];
		i++;
	}
	index->array_a[i] = aux;
}

void	rotate_b(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_b == 0)
		return ;
	aux = index->array_b[0];
	i = 0;
	while (i < index->size_b - 1)
	{
		index->array_b[i] = index->array_b[i + 1];
		i++;
	}
	index->array_b[i] = aux;
}

void	revrot_a(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_a == 0)
		return ;
	aux = index->array_a[index->size_a - 1];
	i = index->size_a - 1;
	while (i > 0)
	{
		index->array_a[i] = index->array_a[i - 1];
		i--;
	}
	index->array_a[i] = aux;
}

void	revrot_b(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_b == 0)
		return ;
	aux = index->array_b[index->size_b - 1];
	i = index->size_b - 1;
	while (i > 0)
	{
		index->array_b[i] = index->array_b[i - 1];
		i--;
	}
	index->array_b[i] = aux;
}
