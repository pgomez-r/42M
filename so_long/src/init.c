/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/19 14:50:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	read_map(t_struct *st, char *path)
{
	char	*line;
	char	*map_str;
	int		fd;

	map_str = malloc(1 * 1);
	line = malloc (1 * 1);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_str = ft_strjoin(map_str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	close(fd);
	st->map = ft_split(map_str, '\n');
	st->width = ft_strlen(st->map[0]);
	st->height = ft_strdlen(st->map);
}

void	load_images(t_struct *st)
{
	mlx_texture_t	*temp;

	temp = mlx_load_png("./Sprites/way.png");
	st->way = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./Sprites/wall.png");
	st->wall = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./Sprites/player.png");
	st->player = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./Sprites/collec.png");
	st->collec = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./Sprites/exit_c.png");
	st->exit_c = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
}

void	load_map(t_struct *st)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;

	j = 0;
	i = 0;
	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == '1')
			{
				mlx_image_to_window(st->window, st->wall, x * PIX, y * PIX);
				st->wall->instances[i].z = 1;
				i++;
			}
			else
			{
				mlx_image_to_window(st->window, st->way, x * PIX, y * PIX);
				st->way->instances[j].z = 1;
				j++;
			}
			x++;
		}
		y++;
	}
}

void	load_player_collect(t_struct *st)
{
	size_t	x;
	size_t	y;
	int		i;
	int		j;

	j = 0;
	y = 0;
	i = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'P')
			{	
				mlx_image_to_window(st->window, st->player, x * PIX, y * PIX);
				st->player->instances[0].z = 10;
			}
			else if (st->map[y][x] == 'C')
			{
				mlx_image_to_window(st->window, st->collec, x * PIX, y * PIX);
				st->collec->instances[i].z = 5;
				i++;
			}
			else if (st->map[y][x] == 'E')
			{
				mlx_image_to_window(st->window, st->exit_c, x * PIX, y * PIX);
				st->exit_c->instances[j].z = 8;
				j++;
			}
			x++;
		}
		y++;
	}
}
