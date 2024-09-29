/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/23 06:57:40 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_minimap_limits(int x, int y, mlx_image_t *img)
{
	if (x > (int)img->width || x < 0 || y > (int)img->height || y < 0)
		return (1);
	return (0);
}

void	ft_paint_miniview(t_data *d)
{
	int	init_y;
	int	init_x;
	int	y;
	int	x;
	int	color;

	init_y = (d->ply.y * d->maps.map_scale_y)
		- d->imgs.mini_view->height / 2;
	init_x = (d->ply.x * d->maps.map_scale_x)
		- d->imgs.mini_view->width / 2;
	y = -1;
	while (++y < (int)d->imgs.mini_view->height)
	{
		x = -1;
		while (++x < (int)d->imgs.mini_view->width)
		{
			if (ft_minimap_limits(init_x + x, init_y + y, d->imgs.mini_src))
				color = GREY;
			else
				color = ft_img_color(d->imgs.mini_src, init_x + x, init_y + y);
			mlx_put_pixel(d->imgs.mini_view, x, y, color);
		}
	}
}

void	ft_paint_miniplayer(t_data *d)
{
	float	player_x;
	float	player_y;
	int		i;
	int		j;

	player_x = d->ply.x * d->maps.map_scale_x;
	player_y = d->ply.y * d->maps.map_scale_y;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			mlx_put_pixel(d->imgs.mini_src, (int)player_x + j,
				(int)player_y + i, RED);
			j++;
		}
		i++;
	}
}

void	ft_paint_minimap(t_data *d, size_t w, size_t h)
{
	size_t	y;
	size_t	x;
	int		minigrid;

	minigrid = CELL / 4;
	y = 0;
	while (y < h)
	{
		x = 0;
		while (x < w)
		{
			if (d->maps.map[y / minigrid][x / minigrid] == '1')
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
	d->imgs.mini_view = mlx_new_image(d->game, WIDTH / 4, HEIGHT / 4);
	d->maps.map_scale_x = (float)d->imgs.mini_src->width
		/ (float)d->maps.pix_width;
	d->maps.map_scale_y = (float)d->imgs.mini_src->height
		/ (float)d->maps.pix_height;
	ft_paint_minimap(d, d->maps.minimap_w, d->maps.minimap_h);
	mlx_image_to_window(d->game, d->imgs.mini_src, 0, 0);
	d->imgs.mini_src->enabled = false;
	ft_paint_miniview(d);
	mlx_image_to_window(d->game, d->imgs.mini_view, 0, 0);
}
