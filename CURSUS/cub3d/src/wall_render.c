/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/24 04:37:23 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_wall_render(t_data *d, t_rays *rc, int ray_num)
{
	float	plane;

	plane = (WIDTH / 2) / tan(d->ply.fov / 2);
	rc->wall_dist = ft_wall_distance(d, rc);
	rc->wall_height = ft_wall_height(rc->wall_dist, plane);
	ft_wall_hitpoint(rc);
	ft_draw_wall(d, rc, ray_num);
}

void	ft_draw_wall(t_data *d, t_rays *rc, int ray_num)
{
	int	start;
	int	end;
	int	y;

	d->tx.mid_win = HEIGHT / 2;
	start = d->tx.mid_win - (int)(rc->wall_height / 2);
	if (start < 0)
		start = 0;
	end = start + (int)rc->wall_height;
	if (end >= HEIGHT)
		end = HEIGHT - 1;
	ft_wall_tex_init(d, rc);
	y = start;
	while (y < end)
	{
		ft_wall_paint(d, &d->tx, ray_num, y);
		y++;
	}
}

void	ft_wall_tex_init(t_data *d, t_rays *rc)
{
	ft_texture_select(d);
	d->tx.tex_step = (float)d->tx.tex_ptr->height / d->rc.wall_height;
	d->tx.tex_x = rc->wall_hp * (float)d->tx.tex_ptr->width;
	if (d->tx.tex_x < 0)
		d->tx.tex_x += d->tx.tex_ptr->width;
	else if (d->tx.tex_x >= d->tx.tex_ptr->width)
		d->tx.tex_x -= d->tx.tex_ptr->width;
	if ((rc->wall_dir == 0 && rc->ray_x > 0)
		|| (rc->wall_dir == 1 && rc->ray_y < 0))
		d->tx.tex_x = d->tx.tex_ptr->width - d->tx.tex_x - 1;
	d->tx.tex_y = 0;
	if (rc->wall_height > HEIGHT)
		d->tx.tex_y += (rc->wall_height - (float)HEIGHT) / 2 * d->tx.tex_step;
}

void	ft_wall_paint(t_data *d, t_render *tx, int x, int y)
{
	tx->tex_color = ft_get_pix_color(tx->tex_ptr,
			(int)tx->tex_x, (int)tx->tex_y);
	mlx_put_pixel(d->imgs.game_view, x, y, tx->tex_color);
	tx->tex_y += tx->tex_step;
}
