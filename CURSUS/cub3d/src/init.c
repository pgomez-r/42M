

#include "cub3d.h"

void	ft_set_player_view(char view, t_data *d)
{
	if (view == 'N')
		d->ply.ang = NORTH;
	else if (view == 'S')
		d->ply.ang = SOUTH;
	else if (view == 'E')
		d->ply.ang = EAST;
	else if (view == 'W')
		d->ply.ang = WEST;
}

void	ft_place_player(t_data *d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < d->maps.map_height)
	{
		x = -1;
		while (++x < d->maps.map_width)
		{
			if (d->maps.map[y][x] == 'N'
				|| d->maps.map[y][x] == 'S'
				|| d->maps.map[y][x] == 'E'
				|| d->maps.map[y][x] == 'W')
			{
				d->ply.y = (y * CELL) + (CELL / 2);
				d->ply.x = (x * CELL) + (CELL / 2);
				ft_set_player_view(d->maps.map[y][x], d);
				break ;
			}
		}
	}
}

void	ft_map_parse(t_data *d, t_info_map *info_map)
{
	d->maps.map = info_map->map;
	d->maps.map_height = info_map->map_height;
	d->maps.map_width = info_map->map_width;
	d->maps.pix_height = d->maps.map_height * CELL;
	d->maps.pix_width = d->maps.map_width * CELL;
	d->maps.minimap_w = d->maps.map_width * MINICELL;
	d->maps.minimap_h = d->maps.map_height * MINICELL;
	d->imgs.c_color = BLUE;
	d->imgs.f_color = GREEN;
	ft_place_player(d);
}

void	ft_init(t_data *d)
{
	d->exit_code = 0;
	d->maps.dpt = d;
	d->imgs.dpt = d;
	d->ply.dpt = d;
	d->rc.dpt = d;
	d->tx.dpt = d;
}

t_info_map	ft_init_map(void)
{
	t_info_map	info_map;
	int			i;

	info_map.north_texture_path = NULL;
	info_map.south_texture_path = NULL;
	info_map.east_texture_path = NULL;
	info_map.west_texture_path = NULL;
	i = 0;
	while (i < 3)
	{
		info_map.floor[i] = -1;
		info_map.ceiling[i] = -1;
		i++;
	}
	info_map.map_width = 0;
	info_map.map_height = 0;
	info_map.map = NULL;
	info_map.map_status = 0;
	info_map.player = 0;
	info_map.player_view = '\0';
	return (info_map);
}
