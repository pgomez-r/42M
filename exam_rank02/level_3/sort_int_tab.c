/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 16:24:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/28 16:48:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	sort_int_tab(int *tab, unsigned int size)
{
	int	j = -1;
	int	i;
	int	aux;

	while (++j < (int)size)
	{	
		i = -1;
		while (++i < ((int)size - 1))
		{
			if (tab[i] > tab[i + 1])
			{	
				aux = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = aux;
			}
		}
	}
}

int	main(void)
{
	int	i = -1;
	int	array[] = {9, 6, 1, 6, -1, 6};

	sort_int_tab(array, 6);
	while (++i < 6)
		printf("%d, ", array[i]);
	printf("\n");
	return (0);
}
