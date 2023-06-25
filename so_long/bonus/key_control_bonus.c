/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:39:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/25 16:39:42 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	move_up(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_y(st, 'U');
	if (st->map[((y) - MOV) / PIX][x / PIX] != '1'
		&& st->map[((y) - MOV) / PIX][(x + 60) / PIX] != '1')
		player_move_y(st, -1);
	if (st->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
		remove_collectable(st, (y + 32), (x + 32));
}

void	move_down(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_y(st, 'D');
	if (st->map[((y + 60) + MOV) / PIX][(x + 60) / PIX] != '1'
		&& st->map[((y + 60) + MOV) / PIX][x / PIX] != '1')
		player_move_y(st, 1);
	if (st->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
		remove_collectable(st, (y + 32), (x + 32));
}

void	move_left(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_x(st, 'L');
	if (st->map[(y) / PIX][(x - MOV) / PIX] != '1'
		&& st->map[(y + 60) / PIX][(x - MOV) / PIX] != '1')
		player_move_x(st, -1);
	if (st->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
		remove_collectable(st, (y + 32), (x + 32));
}

void	move_right(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_x(st, 'R');
	if (st->map[y / PIX][((x + 60) + MOV) / PIX] != '1'
		&& st->map[(y + 60) / PIX][((x + 60) + MOV) / PIX] != '1')
		player_move_x(st, 1);
	if (st->map[(y + 32) / PIX][(x + 32) / PIX] == 'C')
		remove_collectable(st, (y + 32), (x + 32));
	if (st->map[(y + 32) / PIX][(x + 32) / PIX] == 'E' && st->collec_cnt == 0)
		mlx_close_window(st->window);
}

void	key_control(t_struct *st)
{
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
	{	
		st->exit_stat = -1;
		mlx_close_window(st->window);
	}
	if (mlx_is_key_down(st->window, MLX_KEY_UP)
		|| mlx_is_key_down(st->window, MLX_KEY_W))
		move_up(st);
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN)
		|| mlx_is_key_down(st->window, MLX_KEY_S))
		move_down(st);
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT)
		|| mlx_is_key_down(st->window, MLX_KEY_A))
		move_left(st);
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT)
		|| mlx_is_key_down(st->window, MLX_KEY_D))
		move_right(st);
}
