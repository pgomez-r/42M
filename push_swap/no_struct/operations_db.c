/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_db.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:02:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/14 14:07:12 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_ab(int *array_a, int *array_b, size_t arrlen)
{
	rotate_a(array_a, arrlen);
	rotate_b(array_b, arrlen);
	write(1, "rr\n", 3);
}

void	revrot_ab(int *array_a, int *array_b, size_t arrlen)
{
	revrot_a(array_a, arrlen);
	revrot_b(array_b, arrlen);
	write(1, "rrr\n", 4);
}
