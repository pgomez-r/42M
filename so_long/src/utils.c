/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:28:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/15 23:12:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

t_struct	set_empty(void)
{
	t_struct	empty_st;

	empty_st.map = NULL;
	empty_st.width = 0;
	empty_st.height = 0;
	empty_st.collec_cnt = 0;
	empty_st.step_cnt = 0;
	empty_st.player_y = 0;
	empty_st.player_x = 0;
	empty_st.window = NULL;
	empty_st.wall = NULL;
	empty_st.way = NULL;
	empty_st.exit_o = NULL;
	empty_st.exit_c = NULL;
	empty_st.player = NULL;
	empty_st.enemy = NULL;
	empty_st.collec = NULL;
	return (empty_st);
}

void	error_exit(char *error)
{
	ft_printf_error("%s\n", error);
	exit (EXIT_FAILURE);
}
