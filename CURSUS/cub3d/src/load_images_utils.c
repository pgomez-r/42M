/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 05:28:58 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 05:29:54 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_weapon(t_data *d)
{
	mlx_texture_t	*aux;

	aux = mlx_load_png("./textures/m4.png");
	if (!d->imgs.no_texture)
	{
		ft_printf_error("Error loading textures\n");
		return ;
	}
	d->imgs.weapon = ft_resize_img(d, aux, WIDTH * 0.33, HEIGHT * 0.33);
	mlx_delete_texture(aux);
	mlx_image_to_window(d->game, d->imgs.weapon,
		(WIDTH / 2) - (d->imgs.weapon->width / 2),
		HEIGHT - (d->imgs.weapon->height * 0.90));
}

mlx_image_t	*ft_resize_img(t_data *d, mlx_texture_t *src, int width, int height)
{
	mlx_image_t	*new;
	int			x;
	int			y;
	double		scale_x;
	double		scale_y;

	new = mlx_new_image(d->game, width, height);
	scale_x = (double)src->width / width;
	scale_y = (double)src->height / height;
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			d->tx.tex_color = ft_get_pix_color(src, (int)(x * scale_x),
					(int)(y * scale_y));
			mlx_put_pixel(new, x, y, d->tx.tex_color);
			x++;
		}
		y++;
	}
	return (new);
}
