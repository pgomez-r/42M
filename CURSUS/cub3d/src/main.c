/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 06:35:22 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_game_hook(void *param)
{
	t_data	*d;

	d = (t_data *)param;
	if (d->exit_code == 0)
	{
		ft_key_control(d);
		ft_movement_animation(d);
		ft_paint_minimap(d, d->maps.minimap_w, d->maps.minimap_h);
		ft_paint_miniplayer(d);
		ft_raycast(d, &d->rc, d->maps.map_scale_x, d->maps.map_scale_y);
		ft_paint_miniview(d);
	}
}

int	main(int argc, char **argv)
{
	t_data		d;
	t_info_map	info_map;

	ft_init(&d);
	ft_check_args(argc, argv);
	info_map = ft_init_map();
	ft_get_map_info(argv[1], &info_map);
	ft_map_parse(&d, &info_map);
	if (d.exit_code == 0)
	{
		d.game = mlx_init(WIDTH, HEIGHT, NAME, false);
		d.exit_code = ft_load_images(&d, &info_map);
		if (d.exit_code == 0)
		{
			mlx_loop_hook(d.game, ft_game_hook, &d);
			mlx_cursor_hook(d.game, ft_mouse_hook, &d);
			mlx_loop(d.game);
			mlx_terminate(d.game);
		}
		ft_free_textures(&d);
	}
	ft_free_map(&info_map);
	return (d.exit_code);
}
