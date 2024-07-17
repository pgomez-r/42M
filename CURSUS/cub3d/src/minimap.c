

#include "cub3d.h"

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
