/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 22:00:52 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/13 02:10:41 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	exp_animation(t_struct *st, size_t timer)
{
	if (st->frame_exp == timer && st->exp1->instances[0].z > 0)
		st->frame_exp = swap_z(st->exp1, st->exp2, 1);
	if (st->frame_exp == timer && st->exp2->instances[0].z > 0)
		st->frame_exp = swap_z(st->exp2, st->exp3, 1);
	if (st->frame_exp == timer && st->exp3->instances[0].z > 0)
		st->frame_exp = swap_z(st->exp3, st->exp4, 1);
	if (st->frame_exp == timer && st->exp4->instances[0].z > 0)
		st->frame_exp = 200;
	st->frame_exp++;
}

void	explosion_imgs(t_struct *st)
{
	st->texture = mlx_load_png("./textures/e1.png");
	st->exp1 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./textures/e2.png");
	st->exp2 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./textures/e3.png");
	st->exp3 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./textures/e4.png");
	st->exp4 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
}

void	place_exp(t_struct *st, size_t x, size_t y)
{
	mlx_image_to_window(st->window, st->exp1, x, y);
	mlx_image_to_window(st->window, st->exp2, x, y);
	mlx_image_to_window(st->window, st->exp3, x, y);
	mlx_image_to_window(st->window, st->exp4, x, y);
	mlx_set_instance_depth(&st->exp1->instances[0], 910);
	mlx_set_instance_depth(&st->exp2->instances[0], -920);
	mlx_set_instance_depth(&st->exp3->instances[0], -930);
	mlx_set_instance_depth(&st->exp4->instances[0], -940);
}
