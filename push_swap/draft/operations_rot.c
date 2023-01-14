/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:35:44 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/14 14:49:36 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(int *array_a, size_t arrlen)
{
	int		aux;
	size_t	i;

	aux = array_a[0];
	i = 0;
	while (array_a[i] != 0)
	{	
		if (i == (arrlen - 1))
		{	
			array_a[i] = aux;
			write(1, "ra\n", 3);
			return ;
		}
		array_a[i] = array_a[i + 1];
		i++;
	}
	array_a[i - 1] = aux;
	write(1, "ra\n", 3);
}

void	rotate_b(int *array_b, size_t arrlen)
{
	int		aux;
	size_t	i;

	aux = array_b[0];
	i = 0;
	while (array_b[i] != 0)
	{	
		if (i == (arrlen - 1))
		{	
			array_b[i] = aux;
			write(1, "ra\n", 3);
			return ;
		}
		array_b[i] = array_b[i + 1];
		i++;
	}
	array_b[i - 1] = aux;
	write(1, "rb\n", 3);
}

void	revrot_a(int *array_a, size_t arrlen)
{
	int		aux;
	size_t	i;

	i = arrlen - 1;
	while (i == 0)
		i--;
	aux = array_a[i];
	while (i != 0)
	{
		array_a[i] = array_a[i - 1];
		i--;
	}
	array_a[i] = aux;
	write(1, "rra\n", 4);
}

void	revrot_b(int *array_b, size_t arrlen)
{
	int		aux;
	size_t	i;

	i = arrlen - 1;
	while (array_b[i] == 0)
		i--;
	aux = array_b[i];
	while (i != 0)
	{
		array_b[i] = array_b[i - 1];
		i--;
	}
	array_b[i] = aux;
	write(1, "rrb\n", 4);
}

// 4 8 2 6 0 0 0  A
// 1 5 9 0 0 0 0  B