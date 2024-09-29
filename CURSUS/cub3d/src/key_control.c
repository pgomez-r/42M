/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 06:27:49 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_up(t_data *d)
{
	double	y;
	double	x;
	double	x_mov;
	double	y_mov;

	x_mov = cos(d->ply.ang) * MOV;
	y_mov = -sin(d->ply.ang) * MOV;
	x = d->ply.x + x_mov;
	y = d->ply.y + y_mov;
	if (!ft_mov_validation(d, x, y))
	{
		d->ply.x = x;
		d->ply.y = y;
		d->ply.step_count++;
	}
}

void	ft_move_down(t_data *d)
{
	double	y;
	double	x;
	double	x_mov;
	double	y_mov;

	x_mov = cos(d->ply.ang + M_PI) * MOV;
	y_mov = -sin(d->ply.ang + M_PI) * MOV;
	x = d->ply.x + x_mov;
	y = d->ply.y + y_mov;
	if (!ft_mov_validation(d, x, y))
	{
		d->ply.x = x;
		d->ply.y = y;
		d->ply.step_count++;
	}
}

void	ft_move_left(t_data *d)
{
	double	y;
	double	x;
	double	x_mov;
	double	y_mov;

	x_mov = cos(d->ply.ang + M_PI_2) * MOV;
	y_mov = -sin(d->ply.ang + M_PI_2) * MOV;
	x = d->ply.x + x_mov;
	y = d->ply.y + y_mov;
	if (!ft_mov_validation(d, x, y))
	{
		d->ply.x = x;
		d->ply.y = y;
		d->ply.step_count++;
	}
}

void	ft_move_right(t_data *d)
{
	double	y;
	double	x;
	double	x_mov;
	double	y_mov;

	x_mov = +cos(d->ply.ang - M_PI_2) * MOV;
	y_mov = -sin(d->ply.ang - M_PI_2) * MOV;
	x = d->ply.x + x_mov;
	y = d->ply.y + y_mov;
	if (!ft_mov_validation(d, x, y))
	{
		d->ply.x = x;
		d->ply.y = y;
		d->ply.step_count++;
	}
}

void	ft_key_control(t_data *d)
{
	if (mlx_is_key_down(d->game, MLX_KEY_ESCAPE))
	{
		d->exit_code = -1;
		mlx_close_window(d->game);
	}
	if (mlx_is_key_down(d->game, MLX_KEY_W)
		|| mlx_is_key_down(d->game, MLX_KEY_UP))
		ft_move_up(d);
	if (mlx_is_key_down(d->game, MLX_KEY_S)
		|| mlx_is_key_down(d->game, MLX_KEY_DOWN))
		ft_move_down(d);
	if (mlx_is_key_down(d->game, MLX_KEY_A))
		ft_move_left(d);
	if (mlx_is_key_down(d->game, MLX_KEY_D))
		ft_move_right(d);
	if (mlx_is_key_down(d->game, MLX_KEY_LEFT))
	{
		d->ply.ang += (M_PI / 180);
		d->ply.ang = ft_normalize_angle(d->ply.ang);
	}
	if (mlx_is_key_down(d->game, MLX_KEY_RIGHT))
	{
		d->ply.ang -= (M_PI / 180);
		d->ply.ang = ft_normalize_angle(d->ply.ang);
	}
}
