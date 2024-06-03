/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_maker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 09:27:01 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/25 22:18:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_abs_sum(int x, int y)
{
	if (x < 0)
		x = x * (-1);
	if (y < 0)
		y = y * (-1);
	return (x + y);
}

void	best_rotate_top(t_index *index, int x, int y)
{
	if (x == y)
	{
		while (x-- > 0)
			rotate_ab(index);
	}
	else if (x > y)
	{
		x = x - y;
		while (x-- > 0)
			rotate_a(index);
		while (y-- > 0)
			rotate_ab(index);
	}
	else if (y > x)
	{	
		y = y - x;
		while (y-- > 0)
			rotate_b(index);
		while (x-- > 0)
			rotate_ab(index);
	}
}

void	best_rotate_bot(t_index *index, int x, int y)
{
	if (x == y)
	{
		while (x-- > 0)
			revrot_ab(index);
	}
	else if (x > y)
	{
		x = x - y;
		while (x-- > 0)
			revrot_a(index);
		while (y-- > 0)
			revrot_ab(index);
	}
	else if (y > x)
	{	
		y = y - x;
		while (y-- > 0)
			revrot_b(index);
		while (x-- > 0)
			revrot_ab(index);
	}
}

void	operation_maker(t_index *index)
{
	int	x;
	int	y;

	x = index->coords[0];
	y = index->coords[1];
	if (x == 0 && y == 0)
		return ;
	else if (x >= 0 && y >= 0)
		best_rotate_top(index, x, y);
	else if (x < 0 && y < 0)
		best_rotate_bot(index, -x, -y);
	else if (x >= 0 && y < 0)
	{
		while (x-- > 0)
			rotate_a(index);
		while (y++ < 0)
			revrot_b(index);
	}
	else if (x < 0 && y >= 0)
	{
		while (x++ < 0)
			revrot_a(index);
		while (y-- > 0)
			rotate_b(index);
	}
}
