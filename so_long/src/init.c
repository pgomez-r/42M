/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/24 22:44:41 by pgomez-r         ###   ########.fr       */
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
	temp = mlx_load_png("./sprites/frame_1.png");
	st->col1 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_2.png");
	st->col2 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_3.png");
	st->col3 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_4.png");
	st->col4 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_5.png");
	st->col5 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/frame_6.png");
	st->col6 = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/exit_m.png");
	st->exit_c = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/tie_u.png");
	st->enemy_u = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/tie_d.png");
	st->enemy_d = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/tie_l.png");
	st->enemy_l = mlx_texture_to_image(st->window, temp);
	mlx_delete_texture(temp);
	temp = mlx_load_png("./sprites/tie_r.png");
	st->enemy_r = mlx_texture_to_image(st->window, temp);
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
			mlx_set_instance_depth(&st->way->instances[st->ways], 10);
			mlx_set_instance_depth(&st->way1->instances[st->ways], -20);
			mlx_set_instance_depth(&st->way2->instances[st->ways], -30);
			st->ways++;
			x++;
		}
		y++;
	}
}

void	load_enemies(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'X')
			{
				mlx_image_to_window(st->window, st->enemy_d, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->enemy_u, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->enemy_l, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->enemy_r, x * PIX, y * PIX);
				mlx_set_instance_depth(&st->enemy_d->instances[st->enemies], 210);
				mlx_set_instance_depth(&st->enemy_u->instances[st->enemies], -220);
				mlx_set_instance_depth(&st->enemy_l->instances[st->enemies], -230);
				mlx_set_instance_depth(&st->enemy_r->instances[st->enemies], -240);
				st->enemies++;
			}
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

	y = 0;
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
				mlx_set_instance_depth(&st->player_d->instances[0], 310);
				mlx_set_instance_depth(&st->player_u->instances[0], -320);
				mlx_set_instance_depth(&st->player_l->instances[0], -330);
				mlx_set_instance_depth(&st->player_r->instances[0], -340);
			}
			else if (st->map[y][x] == 'C')
			{
				mlx_image_to_window(st->window, st->col1, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col2, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col3, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col4, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col5, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col6, x * PIX, y * PIX);
				mlx_set_instance_depth(&st->col1->instances[st->cols], 110);
				mlx_set_instance_depth(&st->col2->instances[st->cols], -120);
				mlx_set_instance_depth(&st->col3->instances[st->cols], -130);
				mlx_set_instance_depth(&st->col4->instances[st->cols], -140);
				mlx_set_instance_depth(&st->col5->instances[st->cols], -150);
				mlx_set_instance_depth(&st->col6->instances[st->cols], -160);
				st->cols++;
			}
			else if (st->map[y][x] == 'E')
			{
				mlx_image_to_window(st->window, st->exit_c, x * PIX, y * PIX);
				mlx_set_instance_depth(&st->exit_c->instances[st->exits], 110);
				st->exits++;
			}
			x++;
		}
		y++;
	}
}
