/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:04:22 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/30 13:40:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	cont;
	int	temp;
	int	cont2;

	cont2 = 0;
	while (cont2 <= size)
	{
		cont = size - 1;
		while (cont > 0)
		{
			while (tab[cont] < tab[cont - 1])
			{
				temp = tab[cont];
				tab[cont] = tab[cont - 1];
				tab[cont - 1] = temp;
			}
			cont--;
		}
		cont2++;
	}
}

int	main(void)
{
	int	tab1[] = {8, 7, 6, 4, 1, 0, 2, 3, 9, 5};
	int	size;

	size = 10;
	printf("%d %d %d %d %d %d %d %d %d %d\n", tab1[0], tab1[1], tab1[2], tab1[3], tab1[4], tab1[5], tab1[6], tab1[7], tab1[8], tab1[9]);
	ft_sort_int_tab(tab1, size);
	printf("%d %d %d %d %d %d %d %d %d %d\n", tab1[0], tab1[1], tab1[2], tab1[3], tab1[4], tab1[5], tab1[6], tab1[7], tab1[8], tab1[9]);
}
