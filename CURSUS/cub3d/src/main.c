/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:12:36 by codespace         #+#    #+#             */
/*   Updated: 2024/07/02 22:12:53 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_game_hook(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (d->exit_code == 0)
	{
		ft_key_control(d);
		ft_paint_minimap(d, d->maps.minimap_w, d->maps.minimap_h);
		ft_paint_miniplayer(d);
		ft_raycast(d, &d->rc, d->maps.map_scale_x, d->maps.map_scale_y);
	}
}

int	main(void)
{
	t_data	d;

	ft_init(&d);
	if (d.exit_code == 0)
	{
		d.game = mlx_init(WIDTH, HEIGTH, "CVB3D", false);
		ft_load_images(&d);
		mlx_loop_hook(d.game, ft_game_hook, &d);
		mlx_loop(d.game);
		mlx_terminate(d.game);
	}
	return (0);
}
