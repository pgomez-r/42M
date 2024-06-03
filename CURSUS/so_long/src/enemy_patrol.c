/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:34:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/01 13:59:11 by pgruz            ###   ########.fr       */
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

void	patrol_y(t_struct *st, size_t i)
{
	int	y;
	int	x;

	y = st->enemy_d->instances[i].y;
	x = st->enemy_d->instances[i].x;
	if (st->flags[i] == 0 && st->map[(y - 2) / PIX][x / PIX] != '1'
		&& (check_traffic(st, -34, 0, i) == 0))
		enemy_move_y(st, i, -2);
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[(y + 66) / PIX][x / PIX] != '1'
		&& (check_traffic(st, 34, 0, i) == 0))
		enemy_move_y(st, i, 2);
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
		&& (check_traffic(st, 0, -34, i) == 0))
		enemy_move_x(st, i, -2);
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[y / PIX][(x + 66) / PIX] != '1'
		&& (check_traffic(st, 0, 34, i) == 0))
		enemy_move_x(st, i, 2);
	else
		st->flags[i] = 0;
}

void	enemy_move_y(t_struct *st, int i, int mov)
{
	if (st->flags[i] == 0)
	{
		mlx_set_instance_depth(&st->enemy_d->instances[i], -210);
		mlx_set_instance_depth(&st->enemy_u->instances[i], 220);
		mlx_set_instance_depth(&st->enemy_l->instances[i], -230);
		mlx_set_instance_depth(&st->enemy_r->instances[i], -240);
	}
	else
	{
		mlx_set_instance_depth(&st->enemy_d->instances[i], 210);
		mlx_set_instance_depth(&st->enemy_u->instances[i], -220);
		mlx_set_instance_depth(&st->enemy_l->instances[i], -230);
		mlx_set_instance_depth(&st->enemy_r->instances[i], -240);
	}
	st->enemy_d->instances[i].y += mov;
	st->enemy_u->instances[i].y += mov;
	st->enemy_l->instances[i].y += mov;
	st->enemy_r->instances[i].y += mov;
}

void	enemy_move_x(t_struct *st, int i, int mov)
{
	if (st->flags[i] == 0)
	{
		mlx_set_instance_depth(&st->enemy_d->instances[i], -210);
		mlx_set_instance_depth(&st->enemy_u->instances[i], -220);
		mlx_set_instance_depth(&st->enemy_l->instances[i], 230);
		mlx_set_instance_depth(&st->enemy_r->instances[i], -240);
	}
	else
	{
		mlx_set_instance_depth(&st->enemy_d->instances[i], -210);
		mlx_set_instance_depth(&st->enemy_u->instances[i], -220);
		mlx_set_instance_depth(&st->enemy_l->instances[i], -230);
		mlx_set_instance_depth(&st->enemy_r->instances[i], 240);
	}
	st->enemy_d->instances[i].x += mov;
	st->enemy_u->instances[i].x += mov;
	st->enemy_l->instances[i].x += mov;
	st->enemy_r->instances[i].x += mov;
}
