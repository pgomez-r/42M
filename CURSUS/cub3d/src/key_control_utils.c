/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 06:38:10 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mov_validation(t_data *d, int mov_x, int mov_y)
{
	if (d->maps.map[(mov_y - OFFSET) / CELL][(mov_x - OFFSET) / CELL] == '1')
		return (1);
	if (d->maps.map[(mov_y - OFFSET) / CELL][(mov_x + OFFSET) / CELL] == '1')
		return (1);
	if (d->maps.map[(mov_y + OFFSET) / CELL][(mov_x - OFFSET) / CELL] == '1')
		return (1);
	if (d->maps.map[(mov_y + OFFSET) / CELL][(mov_x + OFFSET) / CELL] == '1')
		return (1);
	return (0);
}

float	ft_normalize_angle(float angle)
{
	if (angle >= 2 * M_PI)
		angle -= 2 * M_PI;
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

void	ft_mouse_hook(double x, double y, void *param)
{
	t_data	*d;

	(void)y;
	d = (t_data *)param;
	if (d->cursor_x > x)
	{
		d->ply.ang += (M_PI / 180) * 1.5;
		d->ply.ang = ft_normalize_angle(d->ply.ang);
	}
	else if (d->cursor_x < x)
	{
		d->ply.ang -= (M_PI / 180) * 1.5;
		d->ply.ang = ft_normalize_angle(d->ply.ang);
	}
	d->cursor_x = x;
}

void	ft_movement_animation(t_data *d)
{
	if (d->ply.step_count >= FX_TIMER)
	{
		d->ply.step_count = 0;
		d->imgs.weapon->instances[0].x += d->movement * 2;
		d->imgs.weapon->instances[0].y -= d->movement;
		d->movement *= -1;
	}
}
