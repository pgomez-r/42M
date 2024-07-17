

#include "cub3d.h"

static void	ft_get_line_map(char *line, t_info_map *info_map, int y)
{
	int	x;

	x = 0;
	info_map->map[y] = (char *)malloc(info_map->map_width + 1);
	if (!info_map->map[y])
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		exit (1);
		return ;
	}
	while (x < info_map->map_width)
	{
		while (line[x] && line[x] != '\n')
		{
			info_map->map[y][x] = line[x];
			x++;
		}
		while (x < info_map->map_width)
		{
			info_map->map[y][x] = ' ';
			x++;
		}
		info_map->map[y][x] = '\0';
	}
}

static void	ft_get_map(char *line, t_info_map *info_map, int *n)
{
	int	y;

	y = *n - 6;
	if (!ft_strncmp(line, "\n", 2) && info_map->map_status == 1)
		info_map->map_status = 2;
	if (ft_check_line_map(line, 1) && (info_map->map_status == 0
			|| info_map->map_status == 1))
	{
		if (info_map->map_status == 0)
			info_map->map_status = 1;
		if (info_map->map_status == 1)
		{
			ft_get_line_map(line, info_map, y);
			*n += 1;
		}
	}
	else if (ft_strncmp(line, "\n", 2) && info_map->map_status == 2)
	{
		write (2, "Error: Invalid map\n", 19);
		free (line);
		exit (1);
		return ;
	}
}

static void	ft_get_line_info(char *line, int fd, t_info_map *info_map, int *n)
{
	while (*n < 7 && !ft_strncmp(line, "\n", 2))
	{
		free(line);
		line = get_next_line(fd);
	}
	if (line && line[0] && *n < 6)
		ft_get_textures_and_colors(line, info_map, n);
	else if (line && line[0] && *n >= 6)
		ft_get_map(line, info_map, n);
	free(line);
}

void	ft_get_map_info(char *file, t_info_map *info_map)
{
	char	*line;
	int		n;
	int		fd;

	n = 0;
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error: Cannot open file\n", 24);
		exit(1);
		return ;
	}
	ft_get_map_size(fd, info_map);
	close(fd);
	fd = open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_get_line_info(line, fd, info_map, &n);
	}
	ft_check_closed_map(info_map);
	close (fd);
}
