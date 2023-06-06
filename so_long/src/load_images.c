/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:33:42 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/06 22:16:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	bg_player_imgs(t_struct *st)
{
	st->texture = mlx_load_png("./sprites/bg1.png");
	st->way = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/bg2.png");
	st->way1 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/bg3.png");
	st->way2 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/bg4.png");
	st->way3 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/xwing_u.png");
	st->player_u = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/xwing_d.png");
	st->player_d = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/xwing_l.png");
	st->player_l = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/xwing_r.png");
	st->player_r = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
}

void	walls_imgs(t_struct *st)
{
	st->texture = mlx_load_png("./sprites/ast1.png");
	st->wall = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/ast2.png");
	st->wall1 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/ast3.png");
	st->wall2 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/ast4.png");
	st->wall3 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/ast5.png");
	st->wall4 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/ast6.png");
	st->wall5 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
}

void	cols_imgs(t_struct *st)
{
	st->texture = mlx_load_png("./sprites/frame_1.png");
	st->col1 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/frame_2.png");
	st->col2 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/frame_3.png");
	st->col3 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/frame_4.png");
	st->col4 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/frame_5.png");
	st->col5 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/frame_6.png");
	st->col6 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
}

void	enemy_exit_imgs(t_struct *st)
{
	st->texture = mlx_load_png("./sprites/tie_u.png");
	st->enemy_u = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/tie_d.png");
	st->enemy_d = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/tie_l.png");
	st->enemy_l = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/tie_r.png");
	st->enemy_r = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/exit_c.png");
	st->exit_c = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/exit_m1.png");
	st->exit_1 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/exit_m2.png");
	st->exit_2 = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
	st->texture = mlx_load_png("./sprites/exit_o.png");
	st->exit_o = mlx_texture_to_image(st->window, st->texture);
	mlx_delete_texture(st->texture);
}

void	load_images(t_struct *st)
{
	bg_player_imgs(st);
	walls_imgs(st);
	cols_imgs(st);
	enemy_exit_imgs(st);
	explosion_imgs(st);
}
