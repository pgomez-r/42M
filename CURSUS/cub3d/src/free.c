

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
	free(split);
}

void	ft_free_map(t_info_map *info_map)
{
	free(info_map->north_texture_path);
	free(info_map->south_texture_path);
	free(info_map->east_texture_path);
	free(info_map->west_texture_path);
	ft_free_split(info_map->map);
}
