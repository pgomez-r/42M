/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/24 20:57:51 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_check_line_map(char *line, int mode)
{
	int	i;
	int	map;

	i = 0;
	map = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0'
			|| line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W' || line[i] == '\n' || line[i] == '\t')
		{
			if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n')
				map++;
			i++;
		}
		else
		{
			ft_invalid_map(mode);
			return (0);
		}
	}
	if (map > 0)
		return (1);
	else
		return (0);
}

void	ft_check_all_ones(char *line, t_info_map *info_map)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == ' ' || line[x] == '\t' || line [x] == '1')
			x++;
		else
		{
			ft_free_map(info_map);
			write (2, "Error: Invalid map\n", 19);
			exit (1);
			return ;
		}
	}
	return ;
}

int	ft_check_valid_neighbor(t_info_map *info_map, int y, int x)
{
	if (info_map->map[y][x] != '1' && info_map->map[y][x] != '0'
		&& info_map->map[y][x] != 'N' && info_map->map[y][x] != 'S'
		&& info_map->map[y][x] != 'E' && info_map->map[y][x] != 'W')
		return (1);
	else
		return (0);
}

void	ft_check_map_limits(t_info_map *info_map, int y)
{
	int	x;

	x = 0;
	while (info_map->map[y][x])
	{
		if (info_map->map[y][x] == ' ' || info_map->map[y][x] == '\t'
			|| info_map->map[y][x] == '1')
			x++;
		else if (info_map->map[y][x] == '0' || info_map->map[y][x] == 'N'
			|| info_map->map[y][x] == 'S' || info_map->map[y][x] == 'E'
			|| info_map->map[y][x] == 'W')
		{
			if (x == 0 || x == info_map->map_width - 1
				|| ft_check_valid_neighbor(info_map, y, x - 1)
				|| ft_check_valid_neighbor(info_map, y, x + 1)
				|| ft_check_valid_neighbor(info_map, y - 1, x)
				|| ft_check_valid_neighbor(info_map, y + 1, x))
			{
				ft_invalid_map(1);
				return ;
			}
			x++;
		}
	}
}

void	ft_check_closed_map(t_info_map *info_map)
{
	int	y;

	y = 0;
	while (y < info_map->map_height)
	{
		if (y == 0 || y == info_map->map_height - 1)
			ft_check_all_ones(info_map->map[y], info_map);
		else
			ft_check_map_limits(info_map, y);
		y++;
	}
	ft_rgb_to_hex(info_map);
}
