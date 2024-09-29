/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/08/14 04:22:43 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	if (split)
		free(split);
}

void	ft_free_map(t_info_map *info_map)
{
	if (info_map->north_texture_path)
		free(info_map->north_texture_path);
	if (info_map->south_texture_path)
		free(info_map->south_texture_path);
	if (info_map->east_texture_path)
		free(info_map->east_texture_path);
	if (info_map->west_texture_path)
		free(info_map->west_texture_path);
	ft_free_split(info_map->map);
}

void	ft_free_textures(t_data *d)
{
	if (d->imgs.ea_texture)
		mlx_delete_texture(d->imgs.ea_texture);
	if (d->imgs.we_texture)
		mlx_delete_texture(d->imgs.we_texture);
	if (d->imgs.no_texture)
		mlx_delete_texture(d->imgs.no_texture);
	if (d->imgs.so_texture)
		mlx_delete_texture(d->imgs.so_texture);
	if (d->imgs.ceiling_tex)
		mlx_delete_texture(d->imgs.ceiling_tex);
	if (d->imgs.floor_tex)
		mlx_delete_texture(d->imgs.floor_tex);
}
