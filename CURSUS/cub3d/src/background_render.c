/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 20:06:56 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 13:48:20 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_background_render(t_data *d, t_render *tx)
{
	int				y;
	int				x;

	ft_set_dir_and_plane(&d->ply);
	y = 0;
	while (y < HEIGHT)
	{
		ft_texture_mapping(tx, y);
		x = 0;
		while (x < WIDTH)
		{
			ft_texture_scaling(d, tx);
			tx->tex_color = ft_get_pix_color(tx->tex_ptr,
					(int)tx->tex_x, (int)tx->tex_y);
			mlx_put_pixel(d->imgs.game_view, x, y, tx->tex_color);
			x++;
		}
		y++;
	}
}

void	ft_set_dir_and_plane(t_player *player)
{
	double	plane_length;

	plane_length = tan(player->fov / 2) * (WIDTH / HEIGHT);
	player->dir_x = cos(player->ang);
	player->dir_y = sin(player->ang);
	player->plane_x = -player->dir_y * plane_length;
	player->plane_y = player->dir_x * plane_length;
}

void	ft_texture_mapping(t_render *tx, int y)
{
	if (y < HEIGHT / 2)
	{
		tx->tex_ptr = tx->dpt->imgs.ceiling_tex;
		tx->row_dist = (double)(HEIGHT / 2) / (HEIGHT / 2 - y);
	}
	else
	{
		tx->tex_ptr = tx->dpt->imgs.floor_tex;
		tx->row_dist = (double)(HEIGHT / 2) / (y - HEIGHT / 2);
	}
	tx->dir_x0 = tx->dpt->ply.dir_x + tx->dpt->ply.plane_x;
	tx->dir_y0 = tx->dpt->ply.dir_y + tx->dpt->ply.plane_y;
	tx->dir_x1 = tx->dpt->ply.dir_x - tx->dpt->ply.plane_x;
	tx->dir_y1 = tx->dpt->ply.dir_y - tx->dpt->ply.plane_y;
	tx->bg_step_x = tx->row_dist * (tx->dir_x1 - tx->dir_x0) / (double)WIDTH;
	tx->bg_step_y = tx->row_dist * (tx->dir_y1 - tx->dir_y0) / (double)WIDTH;
	tx->bg_x = (tx->row_dist * tx->dir_x0) + (tx->dpt->ply.x / CELL);
	tx->bg_y = (tx->row_dist * tx->dir_y0) - (tx->dpt->ply.y / CELL);
}

void	ft_texture_scaling(t_data *d, t_render *tx)
{
	tx->tex_x = tx->tex_ptr->width * (tx->bg_x - floor(tx->bg_x));
	if (d->tx.tex_x < 0)
		d->tx.tex_x += tx->tex_ptr->width;
	else if (d->tx.tex_x >= tx->tex_ptr->width)
		d->tx.tex_x -= tx->tex_ptr->width;
	tx->tex_y = tx->tex_ptr->height * (tx->bg_y - floor(tx->bg_y));
	if (d->tx.tex_y < 0)
		d->tx.tex_y += tx->tex_ptr->height;
	else if (d->tx.tex_y >= tx->tex_ptr->height)
		d->tx.tex_y -= tx->tex_ptr->height;
	tx->bg_x += tx->bg_step_x;
	tx->bg_y += tx->bg_step_y;
}
