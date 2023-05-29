/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:41:10 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/29 09:22:39 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	player_face_y(t_struct *st, char c)
{
	if (c == 'U')
	{
		mlx_set_instance_depth(&st->player_d->instances[0], -810);
		mlx_set_instance_depth(&st->player_u->instances[0], 810);
		mlx_set_instance_depth(&st->player_l->instances[0], -830);
		mlx_set_instance_depth(&st->player_r->instances[0], -840);
	}
	if (c == 'D')
	{
		mlx_set_instance_depth(&st->player_d->instances[0], 810);
		mlx_set_instance_depth(&st->player_u->instances[0], -820);
		mlx_set_instance_depth(&st->player_l->instances[0], -830);
		mlx_set_instance_depth(&st->player_r->instances[0], -840);
	}
}

void	player_face_x(t_struct *st, char c)
{
	if (c == 'L')
	{
		mlx_set_instance_depth(&st->player_d->instances[0], -810);
		mlx_set_instance_depth(&st->player_u->instances[0], -820);
		mlx_set_instance_depth(&st->player_l->instances[0], 810);
		mlx_set_instance_depth(&st->player_r->instances[0], -840);
	}
	if (c == 'R')
	{
		mlx_set_instance_depth(&st->player_d->instances[0], -810);
		mlx_set_instance_depth(&st->player_u->instances[0], -820);
		mlx_set_instance_depth(&st->player_l->instances[0], -830);
		mlx_set_instance_depth(&st->player_r->instances[0], 810);
	}
}

void	player_move_y(t_struct *st, int direction)
{
	if (direction < 0)
	{
		st->player_d->instances[0].y -= MOV;
		st->player_u->instances[0].y -= MOV;
		st->player_l->instances[0].y -= MOV;
		st->player_r->instances[0].y -= MOV;
	}
	if (direction > 0)
	{
		st->player_d->instances[0].y += MOV;
		st->player_u->instances[0].y += MOV;
		st->player_l->instances[0].y += MOV;
		st->player_r->instances[0].y += MOV;
	}
}

void	player_move_x(t_struct *st, int direction)
{
	if (direction < 0)
	{
		st->player_d->instances[0].x -= MOV;
		st->player_u->instances[0].x -= MOV;
		st->player_l->instances[0].x -= MOV;
		st->player_r->instances[0].x -= MOV;
	}
	if (direction > 0)
	{
		st->player_d->instances[0].x += MOV;
		st->player_u->instances[0].x += MOV;
		st->player_l->instances[0].x += MOV;
		st->player_r->instances[0].x += MOV;
	}
}
