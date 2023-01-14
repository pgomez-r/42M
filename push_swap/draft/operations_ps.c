/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:29:35 by pgruz             #+#    #+#             */
/*   Updated: 2023/01/10 13:35:44 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *array_a, size_t arrlen)
{
	size_t	aux;

	if (arrlen <= 1)
		return ;
	aux = array_a[0];
	array_a[0] = array_a[1];
	array_a[1] = aux;
	write(1, "sa\n", 3);
}

void	swap_b(int *array_b, size_t arrlen)
{
	size_t	aux;

	if (arrlen <= 1)
		return ;
	aux = array_b[0];
	array_b[0] = array_b[1];
	array_b[1] = aux;
	write(1, "sb\n", 3);
}

void	swap_ab(int *array_a, int*array_b, size_t arrlen)
{
	swap_a(array_a, arrlen);
	swap_b(array_b, arrlen);
	write(1, "ss\n", 3);
}

void	push_a(int *array_a, int *array_b, size_t arrlen)
{
	int		*ptr;
	size_t	i;

	if (array_b[0] == 0)
		return ;
	ptr = array_a;
	while (*ptr != 0)
		ptr++;
	while (*ptr != array_a[0])
	{
		*ptr = *(ptr - 1);
		ptr--;
	}
	*ptr = array_b[0];
	ptr = array_b;
	i = 0;
	while (*ptr != 0 && i < (arrlen - 1))
	{
		*ptr = *(ptr + 1);
		ptr++;
		i++;
	}
	if (i == (arrlen - 1))
		array_b[i] = 0;
	write(1, "push_a\n", 7);
}

void	push_b(int *array_a, int *array_b, size_t arrlen)
{
	int		*ptr;
	size_t	i;

	if (array_a[0] == 0)
		return ;
	ptr = array_b;
	while (*ptr != 0)
		ptr++;
	while (*ptr != array_b[0])
	{
		*ptr = *(ptr - 1);
		ptr--;
	}
	*ptr = array_a[0];
	ptr = array_a;
	i = 0;
	while (*ptr != 0 && i < (arrlen - 1))
	{
		*ptr = *(ptr + 1);
		ptr++;
		i++;
	}
	if (i == (arrlen - 1))
		array_a[i] = 0;
	write(1, "push_b\n", 7);
}

// 4 8 2 6 0 0 0  A
// 1 5 9 0 0 0 0  B