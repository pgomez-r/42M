/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_and_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/24 20:42:12 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_get_texture(char **texture, t_info_map *info_map)
{
	if (!ft_strncmp(texture[0], "NO", 3))
		info_map->north_texture_path = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "SO", 3))
		info_map->south_texture_path = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "EA", 3))
		info_map->east_texture_path = ft_strdup(texture[1]);
	else if (!ft_strncmp(texture[0], "WE", 3))
		info_map->west_texture_path = ft_strdup(texture[1]);
}

void	ft_get_color(char **rgb_color, t_info_map *info_map)
{
	char	**color;

	ft_check_rgb_color(rgb_color[1]);
	color = ft_split(rgb_color[1], ',');
	if (!color || color[3])
	{
		write (2, "Error: Invalid map\n", 19);
		ft_free_split(color);
		exit (1);
		return ;
	}
	if (!ft_strncmp(rgb_color[0], "F", 2))
	{
		info_map->floor[0] = ft_atoi(color[0]);
		info_map->floor[1] = ft_atoi(color[1]);
		info_map->floor[2] = ft_atoi(color[2]);
	}
	else if (!strncmp(rgb_color[0], "C", 2))
	{
		info_map->ceiling[0] = ft_atoi(color[0]);
		info_map->ceiling[1] = ft_atoi(color[1]);
		info_map->ceiling[2] = ft_atoi(color[2]);
	}
	ft_free_split(color);
}

void	ft_remove_nl(char **texture)
{
	char	*aux;

	aux = ft_strtrim(texture[1], "\n");
	free (texture[1]);
	texture[1] = aux;
}

void	ft_get_textures_and_colors(char *line, t_info_map *info_map, int *n)
{
	char	**texture;

	texture = ft_split(line, ' ');
	ft_remove_nl(texture);
	if (!texture || texture[2])
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		ft_free_split(texture);
		exit (1);
		return ;
	}
	if (!ft_strncmp(texture[0], "NO", 3) || !ft_strncmp(texture[0], "SO", 3)
		|| !ft_strncmp(texture[0], "EA", 3) || !ft_strncmp(texture[0], "WE", 3))
	{
		ft_get_texture(texture, info_map);
		*n += 1;
	}
	else if (!ft_strncmp(texture[0], "F", 2) || !ft_strncmp(texture[0], "C", 2))
	{
		ft_get_color(texture, info_map);
		*n += 1;
	}
	ft_free_split(texture);
}

void	ft_rgb_to_hex(t_info_map *info_map)
{
	info_map->floor_hex = (info_map->floor[0] << 24)
		| (info_map->floor[1] << 16) | info_map->floor[2] << 8 | 0xFF;
	info_map->ceiling_hex = (info_map->ceiling[0] << 24)
		| (info_map->ceiling[1] << 16) | info_map->ceiling[2] << 8 | 0xFF;
	return ;
}
