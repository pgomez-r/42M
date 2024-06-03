/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 17:04:22 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/03/30 16:29:36 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	count;
	int	temp;

	count = 0;
	while (tab[count] <= (size / 2))
	{
		temp = tab[count];
		tab[count] = tab[4];
		tab[size - count - 1] = temp;
		count++;
	}
}

int	main(void)
{
	int	size;
	int	tab[] = {1, 2, 3, 4, 5};

	size = 5;
	printf("%d %d %d %d %d\n", tab[0], tab[1], tab[2], tab[3], tab[4]);
	ft_rev_int_tab(tab, size);
	printf("%d %d %d %d %d", tab[0], tab[1], tab[2], tab[3], tab[4]);
}
