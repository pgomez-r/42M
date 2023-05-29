/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:34:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/29 12:38:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	enemy_patrol(t_struct *st)
{
	int		movs[4];
	int		y;
	int		x;
	int		i;
	int		dir;

	y = st->enemy_u->instances[0].y;
	x = st->enemy_u->instances[0].x;
	movs[0] = 0;
	movs[1] = 0;
	movs[2] = 0;
	movs[3] = 0;
	i = 1;
	while (st->map[(y - (i * PIX)) / PIX][x / PIX] != '1'
		&& st->map[(y - (i * PIX)) / PIX][x / PIX] != 'X')
	{	
		movs[0]++;
		i++;
	}
	i = 1;
	while (st->map[(y + (i * PIX)) / PIX][x / PIX] != '1'
		&& st->map[(y + (i * PIX)) / PIX][x / PIX] != 'X')
	{	
		movs[1]++;
		i++;
	}
	i = 1;
	while (st->map[y / PIX][(x - (i * PIX)) / PIX] != '1'
		&& st->map[y / PIX][(x - (i * PIX)) / PIX] != 'X')
	{	
		movs[2]++;
		i++;
	}
	i = 1;
	while (st->map[y / PIX][(x + (i * PIX)) / PIX] != '1'
		&& st->map[y / PIX][(x + (i * PIX)) / PIX] != 'X')
	{	
		movs[3]++;
		i++;
	}
	dir = ft_maxvalue_pos(movs, 4);
	if (dir == 0)
	{
		if (st->flag == 0 && st->map[(st->enemy_d->instances[4].y - 2) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[4].y - 2) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[4].y -= 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[(st->enemy_d->instances[4].y + 66) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[4].y + 66) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[4].y += 2;
		else
			st->flag = 0;
	}
	else if (dir == 1)
	{
		if (st->flag == 0 && st->map[(st->enemy_d->instances[4].y + 66) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[4].y + 66) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[4].y += 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[(st->enemy_d->instances[4].y - 2) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[4].y - 2) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[4].y -= 2;
		else
			st->flag = 0;
	}
	else if (dir == 2)
	{
		if (st->flag == 0 && st->map[y / PIX][(st->enemy_d->instances[4].x - 2) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[4].x - 2) / PIX] != 'X')
			st->enemy_d->instances[4].x -= 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[y / PIX][(st->enemy_d->instances[4].x + 66) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[4].x + 66) / PIX] != 'X')
			st->enemy_d->instances[4].x += 2;
		else
			st->flag = 0;
	}
	else if (dir == 3)
	{
		if (st->flag == 0 && st->map[y / PIX][(st->enemy_d->instances[4].x + 66) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[4].x + 66) / PIX] != 'X')
			st->enemy_d->instances[4].x += 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[y / PIX][(st->enemy_d->instances[4].x - 2) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[4].x - 2) / PIX] != 'X')
			st->enemy_d->instances[4].x -= 2;
		else
			st->flag = 0;
	}
}
