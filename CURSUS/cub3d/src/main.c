

#include "cub3d.h"

void	print_map_info(t_info_map *info_map)
{
	int	y;

	y = 0;
	printf("North texture: %s\n", info_map->north_texture_path);
	printf("South texture: %s\n", info_map->south_texture_path);
	printf("East texture: %s\n", info_map->east_texture_path);
	printf("West texture: %s\n", info_map->west_texture_path);
	printf("Floor: %d, %d, %d\n", info_map->floor[0],
		info_map->floor[1], info_map->floor[2]);
	printf("Ceiling: %d, %d, %d\n", info_map->ceiling[0],
		info_map->ceiling[1], info_map->ceiling[2]);
	printf("Map_width: %d\n", info_map->map_width);
	printf("Map_HEIGHT: %d\n", info_map->map_height);
	printf("Map_status: %d\n", info_map->map_status);
	printf("Player_view: %c\n", info_map->player_view);
	printf("Map:\n");
	while (info_map->map[y])
	{
		printf("%s\n", info_map->map[y]);
		y++;
	}
	printf("\n");
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
			mlx_loop(d.game);
			mlx_terminate(d.game);
		}
	}
	ft_free_map(&info_map);
	return (d.exit_code);
}
