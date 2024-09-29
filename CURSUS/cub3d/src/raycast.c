/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 04:16:22 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_init_ray_step(t_data *d, t_rays *rc)
{
	if (cos(rc->curr_ang) > 0)
	{
		rc->init_x = (floor(d->ply.x / CELL) * CELL + CELL - d->ply.x)
			/ cos(rc->curr_ang);
		rc->dir_x = 1;
	}
	else
	{
		rc->init_x = (d->ply.x - floor(d->ply.x / CELL) * CELL)
			/ fabs(cos(rc->curr_ang));
		rc->dir_x = -1;
	}
	if (sin(rc->curr_ang) > 0)
	{
		rc->init_y = (floor(d->ply.y / CELL) * CELL + CELL - d->ply.y)
			/ sin(rc->curr_ang);
		rc->dir_y = -1;
	}
	else
	{
		rc->init_y = (d->ply.y - floor(d->ply.y / CELL) * CELL)
			/ fabs(sin(rc->curr_ang));
		rc->dir_y = 1;
	}
}

void	ft_init_delta_step(t_rays *rc)
{
	rc->delta_x = CELL / fabs(cos(rc->curr_ang));
	rc->delta_y = CELL / fabs(sin(rc->curr_ang));
}

int	ft_push_ray(t_rays *rc)
{
	if (rc->init_x < rc->init_y)
	{
		rc->init_x += rc->delta_x;
		rc->ray_x += (float)rc->dir_x;
		return (0);
	}
	else
	{
		rc->init_y += rc->delta_y;
		rc->ray_y += (float)rc->dir_y;
		return (1);
	}
}

void	ft_raycast(t_data *d, t_rays *rc, float scale_x, float scale_y)
{
	int		i;

	rc->incr_ang = d->ply.fov / (WIDTH - 1);
	rc->curr_ang = d->ply.ang - (d->ply.fov / 2);
	rc->curr_ang = ft_normalize_angle(rc->curr_ang);
	ft_background_render(d, &d->tx);
	i = WIDTH;
	while (--i >= 0)
	{
		rc->ray_x = d->ply.x;
		rc->ray_y = d->ply.y;
		ft_init_ray_step(d, rc);
		ft_init_delta_step(rc);
		while (d->maps.map[(int)rc->ray_y / CELL][(int)rc->ray_x / CELL] != '1')
		{
			mlx_put_pixel(d->imgs.mini_src, (int)(rc->ray_x * scale_x),
				(int)(rc->ray_y * scale_y), PINK);
			rc->wall_dir = ft_push_ray(rc);
		}
		ft_wall_render(d, rc, i);
		rc->curr_ang += rc->incr_ang;
		rc->curr_ang = ft_normalize_angle(rc->curr_ang);
	}
}
