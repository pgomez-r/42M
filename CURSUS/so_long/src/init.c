/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:28:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/23 19:26:52 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	init_params(t_struct *st)
{
	st->map = NULL;
	st->cmap = NULL;
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
	st->player_x = 0;
	st->player_y = 0;
}

void	init_imgs_bg(t_struct *st)
{
	st->map_str = NULL;
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
	st->stat_col = NULL;
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

void	init_collect_stat(t_struct *st)
{	
	size_t	y;

	y = -1;
	st->stat_col = malloc(sizeof(int) * st->cols);
	while (++y < st->cols)
		st->stat_col[y] = 0;
	if (st->width > 4)
	{	
		y = st->height * PIX;
		st->moves_str = mlx_put_string(st->window, st->moves, 6, y - 42);
		st->moves_num = mlx_put_string(st->window, st->moves_cnt, 70, y - 42);
		mlx_image_to_window(st->window, st->col4, 132, y - 64);
		st->col_aux = st->collec_cnt;
		st->orbs_left = ft_itoa(st->collec_cnt);
		st->cols_left = mlx_put_string(st->window, st->orbs_left, 196, y - 42);
	}
	ft_printf("MOVES: %d\r", (int)st->step_cnt);
}

void	init_struct(t_struct *st)
{
	init_params(st);
	init_imgs_bg(st);
	init_imgs_env(st);
}
