/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:58:21 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/14 14:08:46 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Cast one single ray, just to test and try to learn the basics*/

void	basic_ray(t_mlx_st *st)
{
	double 	r_x;
	double	r_y;
	
	r_x = st->gfx.player->instances[0].x;
	r_y = st->gfx.player->instances[0].y;
	while (42)
	{
		mlx_put_pixel(st->gfx.minimap, (int)(r_x * st->d->scale_x),
			(int)(r_y * st->d->scale_y), 0x00FF00FF);
		r_y -= sin(st->fpp.ang);
		r_x += cos(st->fpp.ang);
		// if (st->fpp.ang >= 0 && st->fpp.ang < M_PI)
    	// 	r_y -= sin(st->fpp.ang);
		// else
    	// 	r_y += sin(st->fpp.ang);
		// if (st->fpp.ang > M_PI_2 && st->fpp.ang <= 3 * M_PI_2)
    	// 	r_x -= cos(st->fpp.ang);
		// else
   		// 	r_x += cos(st->fpp.ang);
		if (st->d->map[(int)r_y / PIX][(int)r_x / PIX] == '1')
			break ;
	}
}

/*Another test, this time multiple rays covering the whole player's FOV*/

void	cast_rays_range(t_mlx_st *st)
{
	float	ang_incr;
	float	ang_curr;
	double 	r_x;
	double	r_y;
	int		i;

	ang_incr = st->fpp.fov / (st->fpp.n_rays - 1);
	ang_curr = st->fpp.ang - (st->fpp.fov / 2);
	i = -1;
	while (++i < st->fpp.n_rays)
	{
		r_x = st->gfx.player->instances[0].x;
		r_y = st->gfx.player->instances[0].y;
		while (42)
		{
			mlx_put_pixel(st->gfx.minimap, (int)(r_x * st->d->scale_x),
				(int)(r_y * st->d->scale_y), 0x00FF00FF);
			r_y -= sin(ang_curr);
			r_x += cos(ang_curr);
			if (st->d->map[(int)r_y / PIX][(int)r_x / PIX] == '1')
				break ;
		}
		ang_curr += ang_incr;
	}
}
