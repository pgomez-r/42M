/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:12:36 by codespace         #+#    #+#             */
/*   Updated: 2024/06/18 02:51:36 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	paint_miniplayer(mlx_image_t *mini, size_t *x, size_t *y)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			mlx_put_pixel(mini, *x + j, *y + i, 0xFF0000FF);
			j++;
		}
		i++;
	}
	*(x) += 4;
	//*(y) += 4;
	return (4);
}

void	update_minimap(t_mlx_st *st)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < st->d->mini_h)
	{
		x = 0;
		while (x < st->d->mini_w)
		{
			if (st->d->map[y / (PIX / 4)][x / (PIX / 4)] == '1')
				mlx_put_pixel(st->gfx.minimap, x, y, 0x000000FF);
			else
				mlx_put_pixel(st->gfx.minimap, x, y, 0xFFFFFFFF);
			x++;
		}
		y++;
	}
	x = st->gfx.player->instances[0].x / 4;
	y = st->gfx.player->instances[0].y / 4;
	paint_miniplayer(st->gfx.minimap, &x, &y);
	//basic_ray(st);
	cast_rays_range(st, &st->rc);
}

void	game_hook(void *param)
{
	t_mlx_st	*st;

	st = (t_mlx_st *)param;
	if (st->d->exit_code == 0)
	{
		key_control(st);
		update_minimap(st);
	}
}


void	init_data(t_struct *d, t_mlx_st *st)
{
	st->fpp.ang = M_PI / 2;
	st->fpp.fov = 60 * (M_PI / 180);
	st->fpp.proj_plane = ((d->width * PIX) / 2) / tan(st->fpp.fov / 2);
	st->fpp.n_rays = 120;
	d->map[0] = "11111111";
	d->map[1] = "10100001";
	d->map[2] = "10110001";
	d->map[3] = "10010001";
	d->map[4] = "10000001";
	d->map[5] = "10P00101";
	d->map[6] = "10000001";
	d->map[7] = "11111111";
	d->height = 8;
	d->width = 8;
	d->exit_code = 0;
	st->d = d;
	st->gfx.st_ptr = st;
	d->wall_color = 0xFFFFFFFF;
}

void	place_player(t_mlx_st *st)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)st->d->height)
	{
		x = -1;
		while (++x < (int)st->d->width)
		{
			if (st->d->map[y][x] == 'P')
			{
				mlx_image_to_window(st->game, st->gfx.player, (x * PIX) + 24, (y * PIX) + 24);
				//mlx_set_instance_depth(&st->gfx.player->instances[0], 10);
				st->gfx.player->enabled = false;
			}
		}
	}
}

int	main(void)
{
	t_struct	d;
	t_mlx_st	st;

	init_data(&d, &st);
	if (d.exit_code == 0)
	{
		st.game = mlx_init(d.width * PIX, d.height * PIX, "test", false);
		load_images(&st);
		place_player(&st);
		//render_map(&st);
		//create_minipmap(&st);
		mlx_image_to_window(st.game, st.game_view, 0, 0);
		mlx_loop_hook(st.game, game_hook, &st);
		mlx_loop(st.game);
		mlx_terminate(st.game);
	}
	return (0);
}
