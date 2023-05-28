/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:39:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/28 23:24:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	move_up(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_y(st, 'U');
	if (st->map[((y + 4) - MOV) / PIX][x / PIX] != '1'
		&& st->map[((y + 4) - MOV) / PIX][(x + 60) / PIX] != '1')
		player_move_y(st, -1);
	if (st->map[(y + 22) / PIX][(x + 22) / PIX] == 'C')
		remove_collectable(st, y, x);
	else if (st->map[(y + 22) / PIX][(x + 42) / PIX] == 'C')
		remove_collectable(st, y, x);
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
	if (st->map[(y + 42) / PIX][(x + 22) / PIX] == 'C')
		remove_collectable(st, y, x);
	else if (st->map[(y + 42) / PIX][(x + 42) / PIX] == 'C')
		remove_collectable(st, y, x);
}

void	move_left(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_x(st, 'L');
	if (st->map[(y + 4) / PIX][(x - MOV) / PIX] != '1'
		&& st->map[(y + 60) / PIX][(x - MOV) / PIX] != '1')
		player_move_x(st, -1);
	if (st->map[(y + 22) / PIX][(x + 22) / PIX] == 'C')
		remove_collectable(st, y, x);
	else if (st->map[(y + 42) / PIX][(x + 22) / PIX] == 'C')
		remove_collectable(st, y, x);
}

void	move_right(t_struct *st)
{
	int	y;
	int	x;

	y = st->player_d->instances[0].y;
	x = st->player_d->instances[0].x;
	player_face_x(st, 'R');
	if (st->map[(y + 4) / PIX][((x + 60) + MOV) / PIX] != '1'
		&& st->map[(y + 60) / PIX][((x + 60) + MOV) / PIX] != '1')
		player_move_x(st, 1);
	if (st->map[(y + 22) / PIX][(x + 42) / PIX] == 'C')
		remove_collectable(st, y, x);
	else if (st->map[(y + 42) / PIX][(x + 42) / PIX] == 'C')
		remove_collectable(st, y, x);
}

void	key_control(t_struct *st)
{
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
		mlx_close_window(st->window);
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
