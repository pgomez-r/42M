/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:42:48 by pgruz             #+#    #+#             */
/*   Updated: 2023/06/01 13:43:46 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	get_patrol_dirs(t_struct *st)
{
	size_t	i;

	st->dirs = malloc(sizeof(int) * st->enms);
	st->flags = malloc(sizeof(int) * st->enms);
	i = 0;
	while (i < st->enms)
	{
		st->dirs[i] = calculate_axis(st, (int)i);
		st->flags[i] = 0;
		i++;
	}
}

int	calculate_axis(t_struct *st, int e)
{
	int		y;
	int		x;
	int		i;

	i = -1;
	while (++i < 4)
		st->movs[i] = 0;
	y = st->enemy_d->instances[e].y;
	x = st->enemy_d->instances[e].x;
	i = 0;
	while (st->map[(y - ((++i) * PIX)) / PIX][x / PIX] != '1')
		st->movs[0]++;
	i = 0;
	while (st->map[(y + ((++i) * PIX)) / PIX][x / PIX] != '1')
		st->movs[1]++;
	i = 0;
	while (st->map[y / PIX][(x - ((++i) * PIX)) / PIX] != '1')
		st->movs[2]++;
	i = 0;
	while (st->map[y / PIX][(x + ((++i) * PIX)) / PIX] != '1')
		st->movs[3]++;
	e = (int)ft_maxvalue_pos(st->movs, 4);
	if (e < 2)
		return (0);
	return (1);
}

int	check_traffic(t_struct *st, int mov_y, int mov_x, int i)
{
	int		y;
	int		x;
	size_t	j;
	int		yy;
	int		xx;

	y = (st->enemy_d->instances[i].y + mov_y) / PIX;
	x = (st->enemy_d->instances[i].x + mov_x) / PIX;
	j = -1;
	while (++j < st->enms)
	{
		if (j == (size_t)i)
			j++;
		yy = st->enemy_d->instances[j].y / PIX;
		xx = st->enemy_d->instances[j].x / PIX;
		if (yy == y && xx == x)
			return (-1);
	}
	return (0);
}
