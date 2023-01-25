/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:58:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/25 14:55:40 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_findmin(t_index *index)
{
	size_t	i;
	size_t	j;
	int		*array_aux;
	int		aux;

	array_aux = ft_duparray(index->array_a, index->size_a);
	i = 1;
	while (i < index->size_a)
	{
		j = i - 1;
		while (array_aux[i] < array_aux[j] && j >= 0)
		{
			aux = array_aux[i];
			array_aux[i] = array_aux[j];
			array_aux[j] = aux;
			j--;
		}
		i++;
	}
	aux = array_aux[0];
	free (array_aux);
	return (aux);
}
/*función para calcular donde está el mínimo, si es por encima o 
por debajo de la mitad del array, para elegir si moverlo por rot 
o revtor*/
void	sort_three(t_index *index)
{
	int	a;
	int	b;
	int	c;

	a = index->array_a[0];
	b = index->array_a[1];
	c = index->array_a[2];
	if (a < b && b > c && c > a)
		return (swap_a(index), rotate_a(index));
	if (a < b && b > c && c < a)
		return (revrot_a(index));
	if (a > b && b < c && c < a)
		return (rotate_a(index));
	if (a > b && b < c && c > a)
		return (swap_a(index));
	if (a > b && b > c && c < a)
		return (rotate_a(index), swap_a(index));
}

// void	sort_five(t_index *index)
// {
// 	if (index->size_a == 4)
// 		push_b(index);
// 	if (index->size_a == 5)
// 	{
// 		push_b(index);
// 		push_b(index);
// 	}
// 	sort_three(index);
// 	if (index->array_b[0] < index->array_b[1])
// 		swap_b(index);
// 	while (index->size_b > 0)
// 	{
// 		if (index->array_b[0] < index->array_a[0])
// 			push_a(index);
// 		if (index->array_b[0] > index->array_a[0])
// 		{
// 			push_a(index);
			
// 		}
// 	}
//ENCONTRAR EL NUMERO MINIMO EN A, CALCULAR SI COMPENSA MAS ROTARLO A TOP
//POR ROT O POR REVROT, ORDENAR TRES
//}
