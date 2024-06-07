/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:53:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/06/07 14:16:57 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	render_background(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			mlx_image_to_window(st->window, st->way, x * PIX, y * PIX);
			mlx_image_to_window(st->window, st->way1, x * PIX, y * PIX);
			mlx_image_to_window(st->window, st->way2, x * PIX, y * PIX);
			mlx_image_to_window(st->window, st->way3, x * PIX, y * PIX);
			mlx_set_instance_depth(&st->way->instances[st->ways], 10);
			mlx_set_instance_depth(&st->way1->instances[st->ways], -15);
			mlx_set_instance_depth(&st->way2->instances[st->ways], -20);
			mlx_set_instance_depth(&st->way3->instances[st->ways], -25);
			st->ways++;
			x++;
		}
		y++;
	}
}

void	render_walls(t_struct *st)
{
	size_t	x;
	size_t	y;

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
				mlx_image_to_window(st->window, st->wall4, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->wall5, x * PIX, y * PIX);
				walls_depth(st);
				st->walls++;
			}
			x++;
		}
		y++;
	}
}

void	render_player(t_struct *st)
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
				mlx_set_instance_depth(&st->player_d->instances[0], 80);
				mlx_set_instance_depth(&st->player_u->instances[0], -85);
				mlx_set_instance_depth(&st->player_l->instances[0], -90);
				mlx_set_instance_depth(&st->player_r->instances[0], -95);
			}
			x++;
		}
		y++;
	}
}

void	render_enemies(t_struct *st)
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
				mlx_set_instance_depth(&st->enemy_d->instances[st->enms], 210);
				mlx_set_instance_depth(&st->enemy_u->instances[st->enms], -220);
				mlx_set_instance_depth(&st->enemy_l->instances[st->enms], -230);
				mlx_set_instance_depth(&st->enemy_r->instances[st->enms], -240);
				st->enms++;
			}
			x++;
		}
		y++;
	}
}

void	render_images(t_struct *st)
{
	render_background(st);
	render_walls(st);
	render_player(st);
	render_enemies(st);
	render_collectables(st);
	render_exits(st);
	get_patrol_dirs(st);
}
