/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:58:21 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/13 17:19:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_ray(t_mlx_st *st)
{
	double 	r_x;
	double	r_y;
	float scale_x = (float)st->gfx.minimap->width / (st->d->width * PIX);
	float scale_y = (float)st->gfx.minimap->height / (st->d->height * PIX);

	r_x = st->gfx.player->instances[0].x;
	r_y = st->gfx.player->instances[0].y;
	while (42)
	{
		mlx_put_pixel(st->gfx.minimap, (int)(r_x * scale_x), (int)(r_y * scale_y), 0x00FF00FF);
		if (st->fpp.ang >= 0 && st->fpp.ang < M_PI)
    		r_y -= sin(st->fpp.ang);
		else
    		r_y += sin(st->fpp.ang);
		if (st->fpp.ang > M_PI_2 && st->fpp.ang <= 3 * M_PI_2)
    		r_x -= cos(st->fpp.ang);
		else
   			r_x += cos(st->fpp.ang);
		if (st->d->map[(int)r_y / PIX][(int)r_x / PIX] == '1')
			break ;
	}
}
