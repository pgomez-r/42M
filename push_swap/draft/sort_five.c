/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:58:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/23 13:15:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_index *index)
{
	if (index->size_a == 2 && index->array_a[0] > index->array_a[1])
		swap_a(index);
	if (index->size_a == 3)
	{
		
	}
	return ;
}

void	sort_five(t_index *index)
{

}
