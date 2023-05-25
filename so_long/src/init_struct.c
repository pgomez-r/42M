/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:28:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/25 22:13:15 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

t_struct	set_empty(void)
{
	t_struct	empty_st;

	empty_st.texture = NULL;
	empty_st.map = NULL;
	empty_st.width = 0;
	empty_st.height = 0;
	empty_st.collec_cnt = 0;
	empty_st.step_cnt = 0;
	empty_st.player_y = 0;
	empty_st.player_x = 0;
	empty_st.walls = 0;
	empty_st.ways = 0;
	empty_st.exits = 0;
	empty_st.cols = 0;
	empty_st.enms = 0;
	empty_st.frame_enemy = 0;
	empty_st.frame_delay = 0;
	empty_st.frame_bg = 0;
	empty_st.frame_col = 0;
	empty_st.window = NULL;
	empty_st.wall = NULL;
	empty_st.wall1 = NULL;
	empty_st.wall2 = NULL;
	empty_st.wall3 = NULL;
	empty_st.way = NULL;
	empty_st.way1 = NULL;
	empty_st.way2 = NULL;
	empty_st.exit_o = NULL;
	empty_st.exit_c = NULL;
	empty_st.player_u = NULL;
	empty_st.player_d = NULL;
	empty_st.player_l = NULL;
	empty_st.player_r = NULL;
	empty_st.enemy_u = NULL;
	empty_st.enemy_d = NULL;
	empty_st.enemy_l = NULL;
	empty_st.enemy_r = NULL;
	empty_st.col1 = NULL;
	empty_st.col2 = NULL;
	empty_st.col3 = NULL;
	empty_st.col4 = NULL;
	empty_st.col5 = NULL;
	empty_st.col6 = NULL;
	return (empty_st);
}

