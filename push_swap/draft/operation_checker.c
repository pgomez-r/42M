/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:30:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/01/21 12:46:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(void)
{
	int		array_a;
	int		array_b;
	t_index	index;
	char	**arg_numbers;
	size_t	i;

	arg_numbers[0] = "4";
	arg_numbers[0] = "2";
	arg_numbers[0] = "6";
	arg_numbers[0] = "8";
	ft_getarrays(arg_numbers, &index);
	i = 0;
	while (i < index.arrlen)
		printf ("%i ", index.array_a[i++]);
	printf ("ARRAY\n");
	//SWAPS//
	//swap_a//
	swap_a(&index);
	i = 0;
	while (i < index.size_a)
		printf ("%i ", index.array_a[i++]);
	printf ("^^^--SWAP_A--^^^\n");
	//swap_b//
	swap_b(&index);
	i = 0;
	while (i < index.size_b)
		printf ("%i ", index.array_b[i++]);
	printf ("^^^--SWAP_B--^^^\n");
	//ROTATES//
	//rotate_a//
	rotate_a(&index);
	i = 0;
	while (i < index.size_a)
		printf ("%i ", index.array_a[i++]);
	printf ("^^^--ROTATE_A--^^^\n");
	//rotate_b//
	rotate_b(&index);
	i = 0;
	while (i < index.size_b)
		printf ("%i ", index.array_b[i++]);
	printf ("^^^--ROTATE_B--^^^\n");
	//revrot_a//
	revrot_a(&index);
	i = 0;
	while (i < index.size_a)
		printf ("%i ", index.array_a[i++]);
	printf ("^^^--REVROT_A--^^^\n");
	//revrot_b//
	revrot_b(&index);
	i = 0;
	while (i < index.size_b)
		printf ("%i ", index.array_b[i++]);
	printf ("^^^--REVROT_B--^^^\n");
	return (0);
	//PUSHS//
	//push_a//
	push_a(&index);
	i = 0;
	while (i < index.size_a)
		printf ("%i ", index.array_a[i++]);
	i = 0;
	while (i < index.size_b)
		printf ("%i ", index.array_b[i++]);
	printf ("^^^--PUSH_A--^^^\n");
	//push_b//
	push_b(&index);
	i = 0;
	while (i < index.size_a)
		printf ("%i ", index.array_a[i++]);
	i = 0;
	while (i < index.size_b)
		printf ("%i ", index.array_b[i++]);
	printf ("^^^--PUSH_A--^^^\n");
}
