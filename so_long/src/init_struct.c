/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:28:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/12 19:18:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	init_params(t_struct *st)
{
	st->map = NULL;
	st->window = NULL;
	st->width = 0;
	st->height = 0;
	st->collec_cnt = 0;
	st->col_aux = 0;
	st->step_cnt = 0;
	st->step_pix = 0;
	st->walls = 0;
	st->ways = 0;
	st->exits = 0;
	st->cols = 0;
	st->enms = 0;
	st->frame_enemy = 0;
	st->frame_wall = 0;
	st->frame_bg = 0;
	st->frame_col = 0;
	st->frame_exit = 0;
	st->frame_exp = 0;
	st->exit_stat = 0;
	st->dirs = NULL;
	st->flags = NULL;
}

void	init_imgs_bg(t_struct *st)
{
	st->moves = "MOVES";
	st->moves_cnt = (ft_itoa(st->step_cnt));
	st->orbs_left = NULL;
	st->wall = NULL;
	st->wall1 = NULL;
	st->wall2 = NULL;
	st->wall3 = NULL;
	st->wall4 = NULL;
	st->wall5 = NULL;
	st->way = NULL;
	st->way1 = NULL;
	st->way2 = NULL;
	st->way3 = NULL;
	st->exit_o = NULL;
	st->exit_1 = NULL;
	st->exit_2 = NULL;
	st->exit_c = NULL;
}

void	init_imgs_env(t_struct *st)
{
	st->player_u = NULL;
	st->player_d = NULL;
	st->player_l = NULL;
	st->player_r = NULL;
	st->enemy_u = NULL;
	st->enemy_d = NULL;
	st->enemy_l = NULL;
	st->enemy_r = NULL;
	st->col1 = NULL;
	st->col2 = NULL;
	st->col3 = NULL;
	st->col4 = NULL;
	st->col5 = NULL;
	st->col6 = NULL;
	st->exp1 = NULL;
	st->exp2 = NULL;
	st->exp3 = NULL;
	st->exp4 = NULL;
	st->moves_str = NULL;
	st->moves_num = NULL;
	st->cols_left = NULL;
}

void	init_struct(t_struct *st)
{
	init_params(st);
	init_imgs_bg(st);
	init_imgs_env(st);
}
