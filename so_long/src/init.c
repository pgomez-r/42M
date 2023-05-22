/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/22 16:19:05 by pgruz            ###   ########.fr       */
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

	temp = mlx_load_png("./sprites/bg0.png");
	st->way = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/bg1.png");
	st->way1 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/bg2.png");
	st->way2 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_1.png");
	st->wall = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_2.png");
	st->wall1 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_3.png");
	st->wall2 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_4.png");
	st->wall3 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/X-Wing.png");
	st->player = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/tie_white.png");
	st->collec = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/exit_m.png");
	st->exit_c = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
}

void	load_background(t_struct *st)
{
	size_t	x;
	size_t	y;

	st->ways = 0;
	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			mlx_image_to_window(st->window, st->way, x * PIX, y * PIX);
			mlx_image_to_window(st->window, st->way1, x * PIX, y * PIX);
			mlx_image_to_window(st->window, st->way2, x * PIX, y * PIX);
			st->way->instances[st->ways].z = 10;
			st->way1->instances[st->ways].z = -1000;
			st->way2->instances[st->ways].z = -1000;
			st->ways++;
			x++;
		}
		y++;
	}
}

void	load_walls(t_struct *st)
{
	size_t	x;
	size_t	y;

	st->walls = 0;
	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == '1')
			{
				mlx_image_to_window(st->window, st->wall, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->wall1, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->wall2, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->wall3, x * PIX, y * PIX);
				st->wall->instances[st->walls].z = 30;
				st->wall1->instances[st->walls].z = -1000;
				st->wall2->instances[st->walls].z = -1000;
				st->wall3->instances[st->walls].z = -1000;
				st->walls++;
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
				st->player->instances[0].z = 100;
			}
			else if (st->map[y][x] == 'C')
			{
				mlx_image_to_window(st->window, st->collec, x * PIX, y * PIX);
				st->collec->instances[i].z = 50;
				i++;
			}
			else if (st->map[y][x] == 'E')
			{
				mlx_image_to_window(st->window, st->exit_c, x * PIX, y * PIX);
				st->exit_c->instances[j].z = 50;
				j++;
			}
			x++;
		}
		y++;
	}
}
//por cada E meto las dos exits, primero con menos profundidad la abierta, cuando haya que abrirlas solo hay que cambiar las profundidades
