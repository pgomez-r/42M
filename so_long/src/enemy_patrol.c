/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:34:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/31 22:32:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	enemy_patrol(t_struct *st)
{
	size_t	i;

	i = 0;
	while (i < st->enms)
	{
		if (st->dirs[i] == 0)
			patrol_y(st, i);
		else
			patrol_x(st, i);
		i++;
	}
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
	return (1);
}

void	patrol_y(t_struct *st, size_t i)
{
	int	y;
	int	x;

	y = st->enemy_d->instances[i].y;
	x = st->enemy_d->instances[i].x;
	if (st->flags[i] == 0 && st->map[(y - 2) / PIX][x / PIX] != '1'
		&& check_traffic(st, -2, 0, i))
		st->enemy_d->instances[i].y -= 2;
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[(y + 66) / PIX][x / PIX] != '1'
		&& check_traffic(st, 66, 0, i))
		st->enemy_d->instances[i].y += 2;
	else
		st->flags[i] = 0;
}

void	patrol_x(t_struct *st, size_t i)
{
	int	y;
	int	x;

	y = st->enemy_d->instances[i].y;
	x = st->enemy_d->instances[i].x;
	if (st->flags[i] == 0 && st->map[y / PIX][(x - 2) / PIX] != '1'
		&& check_traffic(st, 0, -2, i))
		st->enemy_d->instances[i].x -= 2;
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[y / PIX][(x + 66) / PIX] != '1'
		&& check_traffic(st, 0, 666, i))
		st->enemy_d->instances[i].x += 2;
	else
		st->flags[i] = 0;
}
