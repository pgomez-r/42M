/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/11 16:08:56 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis_stack(t_index *index)
{
	size_t	min_pos;
	int		target;

	index->array_tmp = ft_duparray(index->array_a, index->size_a);
	min_pos = ft_minvalue_pos(index->array_tmp, index->size_a);
	target = index->array_tmp[min_pos];
	if (min_pos <= index->size_a / 2)
	{
		while (index->array_tmp[0] != target)
			muted_rotate_a(index);
	}
	if (min_pos > index->size_a / 2)
	{
		while (index->array_tmp[0] != target)
			muted_revrot_a(index);
	}
	index->lis = (ft_lis(index->array_tmp, index->size_a, &index->size_lis));
	free(index->array_tmp);
}

void	lis_comparepush(t_index *index)
{
	int	i;
	int	j;

	while (index->size_a != index->size_lis)
	{
		i = index->array_a[0];
		j = index->array_a[index->size_a - 1];
		if (!ft_isinarray(i, index->lis, index->size_a))
			push_b(index);
		else if (!ft_isinarray(j, index->lis, index->size_a))
		{
			revrot_a(index);
			push_b(index);
		}
		else
			rotate_a(index);
	}
}

int	calc_moves_in_a(t_index *index, int n)
{
	size_t	last;
	size_t	i;
	int		a_coord;

	last = index->size_a - 1;
	a_coord = 0;
	if (n > index->array_a[last] && n < index->array_a[0])
		return (a_coord);
	i = 0;
	while (i < index->size_a)
	{
		if (n > index->array_a[i] && n < index->array_a[i + 1])
			return ((int)i + 1);
		else if (n > index->array_a[last] && n < index->array_a[last - 1])
		{	
			return (-((int)index->size_a - last + 2));
		}
		i++;
		last--;
	}
	i = ft_maxvalue_pos(index->array_a, index->size_a);
	if (i == (int)index->size_a)
}

/* return size - last + 2 wWhy?
	
max_val_pos = max_val(a->t, a->size) + 1;
	if (max_val_pos == a->size)
		max_val_pos = 0;
	if (max_val_pos > a->size - max_val_pos)
		return (-(a->size - max_val_pos));
	return (max_val_pos);*/

size_t	best_pos_pusha(t_index *index)
{
	size_t	i;
	size_t	b_index;
	int		aux[2];

	b_index = 0;
	i = 0;
	while (i < index->size_b)
	{
		if (i < index->size_b / 2)
			aux[1] = i;
		if (i > index->size_b / 2)
			aux[1] = -(index->size_b - i);
		aux[0] = calc_moves_in_a(index, index->array_b[i]);
		if ((unsigned int)index->coords[0] + (unsigned int)index->coords[1]
			> (unsigned int)aux[0] + (unsigned int)aux[1])
		{
			index->coords[0] = aux[0];
			index->coords[1] = aux[1];
			b_index = i;
		}
		i++;
	}
	return (b_index);
}

/*best_pos_pusha me devuelve la pos de array_b a mover; luego hay que mover 
el número que estés en esa posicion (array_b[b_index]) a array_b[0], 
dejar en array_a[0] justo el nero que debe estár por debajo del que vamos 
a mandar, y entonces hacer el push_a
solo devuelve un número para ubicar la posicion en array_b...luego voy a 
necesitar tambien el array con las "coordenadas"...tendría que meter ese array
en index*/

void	sort_complex(t_index *index)
{
	size_t	pa_index;

	ft_lis_stack(index);
	lis_comparepush(index);
	index->coords[0] = 0;
	index->coords[1] = 0;
	while (index->size_b > 0)
	{
		pa_index = best_pos_pusha(index);
	}
}

// int	get_mid_value(int *array, size_t len)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		*array_aux;
// 	int		aux;

// 	array_aux = ft_duparray(array, len);
// 	i = 1;
// 	while (i < len)
// 	{
// 		j = i - 1;
// 		while (array_aux[i] < array_aux[j] && j >= 0)
// 		{
// 			aux = array_aux[i];
// 			array_aux[i] = array_aux[j];
// 			array_aux[j] = aux;
// 			j--;
// 		}
// 		i++;
// 	}
// 	aux = array_aux[len / 2];
// 	free(array_aux);
// 	return (aux);
// }

// void	mid_alg(int *array_a, int *array_b, size_t arrlen)
// {
// 	size_t	i;
// 	int		mid_value;
// 	int		max_reps;

// 	i = 0;
// 	max_reps = 0;
// 	while (i < arrlen && max_reps < mid_value)
// 	{
// 		mid_value = get_mid_value(array_a, arrlen);
// 		if (array_a[0] < mid_value)
// 		{
// 			push_b(array_a, array_b, arrlen);
// 			max_reps++;
// 		}
// 		else if (array_a[arrlen] < mid_value)
// 		{
// 			revrot_a(array_a, arrlen);
// 			push_b(array_a, array_b, arrlen);
// 			max_reps++;
// 		}
// 		else
// 			rotate_a(array_a, arrlen);
// 		i++;
// 	}
// }

/*ESTA FUNCION SE PUEDE ADAPTAR PARA LIS_CHECK*/
