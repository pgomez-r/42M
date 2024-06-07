/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 16:07:49 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/06 16:29:41 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_up(t_mlx_st *st)
{
	int	y;
	int	x;

	y = st->gfx.player->instances[0].y;
	x = st->gfx.player->instances[0].x;
	if (st->d->map[((y) - MOV) / PIX][x / PIX] != '1'
		&& st->d->map[((y) - MOV) / PIX][(x + 12) / PIX] != '1')
		st->gfx.player->instances[0].y -= MOV;
}

void	move_down(t_mlx_st *st)
{
	int	y;
	int	x;

	y = st->gfx.player->instances[0].y;
	x = st->gfx.player->instances[0].x;
	if (st->d->map[((y + 12) + MOV) / PIX][(x + 12) / PIX] != '1'
		&& st->d->map[((y + 12) + MOV) / PIX][x / PIX] != '1')
		st->gfx.player->instances[0].y += MOV;
}

void	move_left(t_mlx_st *st)
{
	int	y;
	int	x;

	y = st->gfx.player->instances[0].y;
	x = st->gfx.player->instances[0].x;
	if (st->d->map[(y) / PIX][(x - MOV) / PIX] != '1'
		&& st->d->map[(y + 12) / PIX][(x - MOV) / PIX] != '1')
		st->gfx.player->instances[0].x -= MOV;
}

void	move_right(t_mlx_st *st)
{
	int	y;
	int	x;

	y = st->gfx.player->instances[0].y;
	x = st->gfx.player->instances[0].x;
	if (st->d->map[y / PIX][((x + 12) + MOV) / PIX] != '1'
		&& st->d->map[(y + 12) / PIX][((x + 12) + MOV) / PIX] != '1')
		st->gfx.player->instances[0].x += MOV;
}

void	key_control(t_mlx_st *st)
{
	if (mlx_is_key_down(st->game, MLX_KEY_ESCAPE))
	{
		st->d->exit_code = -1;
		mlx_close_window(st->game);
	}
	if (mlx_is_key_down(st->game, MLX_KEY_UP)
		|| mlx_is_key_down(st->game, MLX_KEY_W))
		move_up(st);
	if (mlx_is_key_down(st->game, MLX_KEY_DOWN)
		|| mlx_is_key_down(st->game, MLX_KEY_S))
		move_down(st);
	if (mlx_is_key_down(st->game, MLX_KEY_LEFT)
		|| mlx_is_key_down(st->game, MLX_KEY_A))
		move_left(st);
	if (mlx_is_key_down(st->game, MLX_KEY_RIGHT)
		|| mlx_is_key_down(st->game, MLX_KEY_D))
		move_right(st);
}
