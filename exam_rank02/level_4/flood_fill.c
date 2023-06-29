/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 21:15:18 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/29 18:40:35 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "flood_fill.h"

void	fill(char **tab, t_point size, t_point begin, char c)
{
	int	x;
	int	y;

	x = begin->x;
	y = begin->y;
	if ()
}
void  flood_fill(char **tab, t_point size, t_point begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

int	main(void)
{
	t_point		size = {8, 5};
	t_point		begin = {1, 1};
	char		*zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
	int			i = -1;

	while (zone[++i] != NULL)
		printf("%s\n");
	printf("\n");
	flood_fill(zone, size, begin);
}
