/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_images_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 22:19:27 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:09 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	render_exits(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'E')
			{
				mlx_image_to_window(st->window, st->exit_c, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->exit_1, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->exit_2, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->exit_o, x * PIX, y * PIX);
				mlx_set_instance_depth(&st->exit_c->instances[st->exits], 50);
				mlx_set_instance_depth(&st->exit_1->instances[st->exits], -55);
				mlx_set_instance_depth(&st->exit_2->instances[st->exits], -60);
				mlx_set_instance_depth(&st->exit_o->instances[st->exits], -65);
				st->exits++;
			}
			x++;
		}
		y++;
	}
}

void	render_collectables(t_struct *st)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < st->height)
	{
		x = 0;
		while (x < st->width)
		{
			if (st->map[y][x] == 'C')
			{
				mlx_image_to_window(st->window, st->col1, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col2, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col3, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col4, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col5, x * PIX, y * PIX);
				mlx_image_to_window(st->window, st->col6, x * PIX, y * PIX);
				collectables_depth(st);
				st->cols++;
				st->collec_cnt++;
			}
			x++;
		}
		y++;
	}
}

void	collectables_depth(t_struct	*st)
{
	mlx_set_instance_depth(&st->col1->instances[st->cols], 50);
	mlx_set_instance_depth(&st->col2->instances[st->cols], -55);
	mlx_set_instance_depth(&st->col3->instances[st->cols], -60);
	mlx_set_instance_depth(&st->col4->instances[st->cols], -65);
	mlx_set_instance_depth(&st->col5->instances[st->cols], -70);
	mlx_set_instance_depth(&st->col6->instances[st->cols], -75);
}

void	remove_collectable(t_struct *st, int y, int x)
{
	size_t			i;

	i = 0;
	while (i < st->cols)
	{
		if (st->stat_col[i] == 0 && (st->col1->instances[i].y / PIX) == y / PIX
			&& (st->col1->instances[i].x / PIX) == x / PIX)
		{
			st->stat_col[i] = 1;
			st->col1->instances[i].enabled = false;
			st->col2->instances[i].enabled = false;
			st->col3->instances[i].enabled = false;
			st->col4->instances[i].enabled = false;
			st->col5->instances[i].enabled = false;
			st->col6->instances[i].enabled = false;
			st->collec_cnt--;
			return ;
		}	
		i++;
	}
}

void	walls_depth(t_struct *st)
{
	mlx_set_instance_depth(&st->wall->instances[st->walls], 50);
	mlx_set_instance_depth(&st->wall1->instances[st->walls], -55);
	mlx_set_instance_depth(&st->wall2->instances[st->walls], -60);
	mlx_set_instance_depth(&st->wall3->instances[st->walls], -65);
	mlx_set_instance_depth(&st->wall4->instances[st->walls], -70);
	mlx_set_instance_depth(&st->wall5->instances[st->walls], -75);
}
