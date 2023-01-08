/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:29:35 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/08 22:33:03 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *array_a)
{
	size_t	aux;
	if (ft_arrlen(array_a) <= 1)
		return;
	aux = array_a[0];
	array_a[0] = array_a[1];
	array_a[1] = aux;
	printf("sa\n");
}

void	swap_b(int *array_b)
{
	size_t	aux;
	if (ft_arrlen(array_b) <= 1)
		return;
	aux = array_b[0];
	array_b[0] = array_b[1];
	array_b[1] = aux;
	printf("sb\n");
}

void	swap_ab(int *array_a, int*array_b)
{
	swap_a(array_a);
	swap_b(array_b);
	printf("ss");
}

void	push_a(int *array_a, int *array_b)
{
	
}

void	push_b(int *array_a, int *array_b)
{
	
}
