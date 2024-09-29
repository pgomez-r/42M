/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 05:29:34 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_img_color(mlx_image_t *tex, int x, int y)
{
	unsigned int	pos;
	int				r;
	int				g;
	int				b;
	int				a;

	pos = 4 * x + (4 * y * tex->width);
	if (pos <= tex->height * tex->width * 4)
	{
		r = tex->pixels[pos];
		g = tex->pixels[pos + 1];
		b = tex->pixels[pos + 2];
		a = tex->pixels[pos + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0);
}

int	ft_load_textures(t_data *d, t_info_map *t)
{
	d->imgs.no_texture = mlx_load_png(t->north_texture_path);
	if (!d->imgs.no_texture)
		return (ft_printf_error("Error loading textures\n"), -1);
	d->imgs.so_texture = mlx_load_png(t->south_texture_path);
	if (!d->imgs.so_texture)
		return (ft_printf_error("Error loading textures\n"), -1);
	d->imgs.ea_texture = mlx_load_png(t->east_texture_path);
	if (!d->imgs.ea_texture)
		return (ft_printf_error("Error loading textures\n"), -1);
	d->imgs.we_texture = mlx_load_png(t->west_texture_path);
	if (!d->imgs.we_texture)
		return (ft_printf_error("Error loading textures\n"), -1);
	d->imgs.floor_tex = mlx_load_png("./textures/grass.png");
	if (!d->imgs.floor_tex)
		return (ft_printf_error("Error loading textures\n"), -1);
	d->imgs.ceiling_tex = mlx_load_png("./textures/ceiling.png");
	if (!d->imgs.ceiling_tex)
		return (ft_printf_error("Error loading textures\n"), -1);
	return (0);
}

void	ft_set_background(t_data *d)
{
	int	y;
	int	x;

	y = -1;
	while ((unsigned int)++y < d->imgs.game_view->height)
	{
		x = -1;
		while ((unsigned int)++x < d->imgs.game_view->width)
		{
			if ((unsigned int)y < (d->imgs.game_view->height / 2))
				mlx_put_pixel(d->imgs.game_view, x, y, d->imgs.c_color);
			else
				mlx_put_pixel(d->imgs.game_view, x, y, d->imgs.f_color);
		}
	}
}

int	ft_load_images(t_data *d, t_info_map *info_map)
{
	d->exit_code = ft_load_textures(d, info_map);
	if (d->exit_code == 0)
	{
		d->imgs.game_view = mlx_new_image(d->game, WIDTH, HEIGHT);
		ft_background_render(d, &d->tx);
		mlx_image_to_window(d->game, d->imgs.game_view, 0, 0);
		ft_create_minipmap(d);
		ft_weapon(d);
	}
	return (d->exit_code);
}
