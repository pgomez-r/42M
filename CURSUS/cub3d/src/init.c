/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 06:36:26 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_set_player_view(char view, t_data *d)
{
	if (view == 'N')
		d->ply.ang = M_PI / 2;
	else if (view == 'S')
		d->ply.ang = (3 * M_PI) / 2;
	else if (view == 'E')
		d->ply.ang = 2 * M_PI;
	else if (view == 'W')
		d->ply.ang = M_PI;
	d->cursor_x = 0;
	d->ply.step_count = 0;
	d->movement = MOV * 2;
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
	ft_check_valid_color(info_map);
	d->maps.map = info_map->map;
	d->maps.map_height = info_map->map_height;
	d->maps.map_width = info_map->map_width;
	d->maps.pix_height = d->maps.map_height * CELL;
	d->maps.pix_width = d->maps.map_width * CELL;
	d->maps.minimap_w = d->maps.map_width * (CELL / 4);
	d->maps.minimap_h = d->maps.map_height * (CELL / 4);
	d->imgs.c_color = info_map->ceiling_hex;
	d->imgs.f_color = info_map->floor_hex;
	ft_place_player(d);
}

void	ft_init(t_data *d)
{
	d->exit_code = 0;
	d->maps.dpt = d;
	d->imgs.dpt = d;
	d->ply.dpt = d;
	d->ply.fov = FOV * (M_PI / 180);
	d->rc.dpt = d;
	d->tx.dpt = d;
	d->imgs.ea_texture = NULL;
	d->imgs.we_texture = NULL;
	d->imgs.no_texture = NULL;
	d->imgs.so_texture = NULL;
	d->imgs.floor_tex = NULL;
	d->imgs.ceiling_tex = NULL;
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
	info_map.ceiling_hex = 0;
	info_map.floor_hex = 0;
	info_map.map_width = 0;
	info_map.map_height = 0;
	info_map.map = NULL;
	info_map.map_status = 0;
	info_map.player = 0;
	info_map.player_view = '\0';
	return (info_map);
}
