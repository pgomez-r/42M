/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:02:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	swap_ab(t_index *index)
{
	int	aux;

	if (index->size_a <= 1 || index->size_b <= 1)
		return ;
	aux = index->array_a[0];
	index->array_a[0] = index->array_a[1];
	index->array_a[1] = aux;
	aux = index->array_b[0];
	index->array_b[0] = index->array_b[1];
	index->array_b[1] = aux;
	write(1, "ss\n", 3);
}

void	rotate_ab(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_a == 0 || index->size_b == 0)
		return ;
	aux = index->array_a[0];
	i = 0;
	while (i < index->size_a - 1)
	{
		index->array_a[i] = index->array_a[i + 1];
		i++;
	}
	index->array_a[i] = aux;
	aux = index->array_b[0];
	i = 0;
	while (i < index->size_b - 1)
	{
		index->array_b[i] = index->array_b[i + 1];
		i++;
	}
	index->array_b[i] = aux;
	write(1, "rr\n", 3);
}

void	revrot_ab(t_index *index)
{
	int		aux;
	size_t	i;

	if (index->size_a == 0 || index->size_b == 0)
		return ;
	aux = index->array_a[index->size_a - 1];
	i = index->size_a - 1;
	while (i > 0)
	{
		index->array_a[i] = index->array_a[i - 1];
		i--;
	}
	index->array_a[i] = aux;
	aux = index->array_b[index->size_b - 1];
	i = index->size_b - 1;
	while (i > 0)
	{
		index->array_b[i] = index->array_b[i - 1];
		i--;
	}
	index->array_b[i] = aux;
	write(1, "rrr\n", 4);
}
