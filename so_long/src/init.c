/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/22 23:08:54 by pgomez-r         ###   ########.fr       */
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
	temp = mlx_load_png("./sprites/ast5.png");
	st->wall = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/ast2.png");
	st->wall1 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/ast3.png");
	st->wall2 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/ast4.png");
	st->wall3 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/xwing_u.png");
	st->player_u = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/xwing_d.png");
	st->player_d = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/xwing_l.png");
	st->player_l = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/xwing_r.png");
	st->player_r = mlx_texture_to_image(st->window, temp);
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
			st->way1->instances[st->ways].z = -20;
			st->way2->instances[st->ways].z = -30;
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
				mlx_set_instance_depth(&st->wall->instances[st->walls], 300);
				mlx_set_instance_depth(&st->wall1->instances[st->walls], -400);
				mlx_set_instance_depth(&st->wall2->instances[st->walls], -500);
				mlx_set_instance_depth(&st->wall3->instances[st->walls], -600);
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
				mlx_image_to_window(st->window, st->player_d, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->player_u, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->player_l, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->player_r, x * PIX, y * PIX);
				st->player_d->instances[0].z = 500;
				st->player_u->instances[0].z = -2100;
				st->player_l->instances[0].z = -2200;
				st->player_r->instances[0].z = -2300;
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
