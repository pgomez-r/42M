/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:21:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/02/06 23:35:15 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*TAREAS PENDIENTES:
-(PASAR CONTADORES i, j, k a struct??)
-necesito que LIS devuelva también el size_LIS, a la estructura
-crear función que compare cada índice en orden del array_a con la LIS y usarla 
en un bucle donde si no coicinde = PB, si coincide comprobar el ultimo índice, 
en ese caso = RRA + PB, si tampoco coincide = RA y vuelta a comprobar... 
TANTAS VECES COMO SIZE ORIGINAL (no size_a? no estoy seguro)*/

void	muted_rotate_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_a[0];
	i = 0;
	while (i < index->size_a - 1)
	{
		index->array_a[i] = index->array_a[i + 1];
		i++;
	}
	index->array_a[i] = aux;
}

void	muted_revrot_a(t_index *index)
{
	int		aux;
	size_t	i;

	aux = index->array_a[index->size_a - 1];
	i = index->size_a - 1;
	while (i > 0)
	{
		index->array_a[i] = index->array_a[i - 1];
		i--;
	}
	index->array_a[i] = aux;
}

void	ft_lis_stack(t_index *index)
{
	size_t	min_pos;
	int		target;

	index->array_lis = ft_duparray(index->array_a, index->size_a);
	min_pos = ft_minvalue_pos(index->array_lis, index->size_a);
	target = index->array_lis[min_pos];
	if (min_pos <= index->size_a / 2)
	{
		while (index->array_lis[0] != target)
			muted_rotate_a(index);
	}
	if (min_pos > index->size_a / 2)
	{
		while (index->array_lis[0] != target)
			muted_revrot_a(index);
	}
	index->array_lis = (ft_lis(index->array_lis, index->size_a));
}

void	lis_compare(t_index *index)
{
	size_t	i;
	size_t	j;
	int		flag;
	//esto se puede reformular, creo que sin flags, ordenando los if y whiles
	i = 0;
	flag = 0;
	while (i < index->size_a)
	{
		j = 0;
		while (j < index->size_lis)
		{
			if (index->array_a[0] == index->array_lis[j])
				flag++;
			j++;
		}
		if (flag == 0) //[0] no esta en lis -> pb y vuelta a empzar con el nuevo [0]
			push_b(index);
		if (flag > 0) //[0] está en lis, queremos conservarlo, vamos a comprobar el ultimo [index]
		{
			j = 0;
			flag = 0;
			while (j < index->size_lis)
			{
				if (index->array_a[index->size_a] == index->array_lis[j])
					flag++;
				j++;
			}
			if (flag == 0) //[last] no esta en lis -> rra, pb
			{
				revrot_a(index);
				push_b(index);
			}
			if (flag > 0) //[last] está en lis, hay que conservarlo, así que ra y vuelta al primer bucle
				rotate_a(index);
		}
		i++;
	}
}

int	get_mid_value(int *array, size_t len)
{
	size_t	i;
	size_t	j;
	int		*array_aux;
	int		aux;

	array_aux = ft_duparray(array, len);
	i = 1;
	while (i < len)
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
	aux = array_aux[len / 2];
	free(array_aux);
	return (aux);
}

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
