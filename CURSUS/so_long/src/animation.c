/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:44:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/06 21:20:47 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	swap_z(mlx_image_t *img1, mlx_image_t *img2, size_t total)
{
	size_t	i;
	int		depth1;
	int		depth2;

	i = 0;
	depth1 = (img1->instances[i].z) * -1;
	depth2 = (img2->instances[i].z) * -1;
	while (i < total)
	{
		mlx_set_instance_depth(&img1->instances[i], depth1);
		mlx_set_instance_depth(&img2->instances[i], depth2);
		i++;
	}
	return (-1);
}

void	col_animation(t_struct *st, size_t timer)
{
	if (st->frame_col == timer && st->col1->instances[0].z > 0)
		st->frame_col = swap_z(st->col1, st->col2, st->cols);
	else if (st->frame_col == timer && st->col2->instances[0].z > 0)
		st->frame_col = swap_z(st->col2, st->col3, st->cols);
	else if (st->frame_col == timer && st->col3->instances[0].z > 0)
		st->frame_col = swap_z(st->col3, st->col4, st->cols);
	else if (st->frame_col == timer && st->col4->instances[0].z > 0)
		st->frame_col = swap_z(st->col4, st->col5, st->cols);
	else if (st->frame_col == timer && st->col5->instances[0].z > 0)
		st->frame_col = swap_z(st->col5, st->col6, st->cols);
	else if (st->frame_col == timer && st->col6->instances[0].z > 0)
		st->frame_col = swap_z(st->col6, st->col1, st->cols);
	st->frame_col++;
}

void	background_animation(t_struct *st, size_t timer)
{
	if (st->frame_bg == timer && st->way->instances[0].z > 0)
		st->frame_bg = swap_z(st->way, st->way1, st->ways);
	else if (st->frame_bg == timer && st->way1->instances[0].z > 0)
		st->frame_bg = swap_z(st->way1, st->way2, st->ways);
	else if (st->frame_bg == timer && st->way2->instances[0].z > 0)
		st->frame_bg = swap_z(st->way2, st->way3, st->ways);
	else if (st->frame_bg == timer && st->way3->instances[0].z > 0)
		st->frame_bg = swap_z(st->way3, st->way, st->ways);
	st->frame_bg++;
}

void	wall_animation(t_struct	*st, size_t timer)
{
	if (st->frame_wall == timer && st->wall->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall, st->wall1, st->walls);
	else if (st->frame_wall == timer && st->wall1->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall1, st->wall2, st->walls);
	else if (st->frame_wall == timer && st->wall2->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall2, st->wall3, st->walls);
	else if (st->frame_wall == timer && st->wall3->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall3, st->wall4, st->walls);
	else if (st->frame_wall == timer && st->wall4->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall4, st->wall5, st->walls);
	else if (st->frame_wall == timer && st->wall5->instances[0].z > 0)
		st->frame_wall = swap_z(st->wall5, st->wall, st->walls);
	st->frame_wall++;
}

void	open_exit(t_struct *st, size_t timer)
{
	if (st->frame_exit == timer && st->exit_c->instances[0].z > 0)
		st->frame_exit = swap_z(st->exit_c, st->exit_1, st->exits);
	if (st->frame_exit == timer && st->exit_1->instances[0].z > 0)
		st->frame_exit = swap_z(st->exit_1, st->exit_2, st->exits);
	if (st->frame_exit == timer && st->exit_2->instances[0].z > 0)
	{	
		st->frame_exit = swap_z(st->exit_2, st->exit_o, st->exits);
		st->frame_exit = 200;
	}
	st->frame_exit++;
}
