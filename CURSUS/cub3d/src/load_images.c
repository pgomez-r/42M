/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 20:31:49 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/01 08:57:21 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_paint_minimap(t_data *d, size_t w, size_t h)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (d->maps.map[y / MINICELL][x / MINICELL] == '1')
				mlx_put_pixel(d->imgs.mini_src, x, y, BLACK);
			else
				mlx_put_pixel(d->imgs.mini_src, x, y, WHITE);
			x++;
		}
		y++;
	}
}

void	ft_create_minipmap(t_data *d)
{
	d->imgs.mini_src = mlx_new_image(d->game, d->maps.minimap_w,
		d->maps.minimap_h);
	d->imgs.mini_view = mlx_new_image(d->game, MINI_W, MINI_H);
	d->maps.map_scale_x = (float)d->imgs.mini_src->width
		/ (float)d->maps.pix_width;
	d->maps.map_scale_y = (float)d->imgs.mini_src->height
		/ (float)d->maps.pix_height;
	ft_paint_minimap(d, d->maps.minimap_w, d->maps.minimap_h);
	mlx_image_to_window(d->game, d->imgs.mini_src, 0, 0);
}

void	ft_set_background(mlx_image_t *img)
{
	int y;
	int	x;

	y = -1;
	while ((unsigned int)++y < img->height)
	{
		x = -1;
		while ((unsigned int)++x < img->width)
		{
			if ((unsigned int)y < (img->height / 2))
				mlx_put_pixel(img, x, y, BLUE);
			else
				mlx_put_pixel(img, x, y, GREEN);
		}
	}
}

void	ft_load_images(t_data *d)
{
	d->imgs.game_view = mlx_new_image(d->game, WIDTH, HEIGTH);
	ft_set_background(d->imgs.game_view);
	mlx_image_to_window(d->game, d->imgs.game_view, 0, 0);
	ft_create_minipmap(d);
}

