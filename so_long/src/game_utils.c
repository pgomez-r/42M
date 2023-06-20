/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:37:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/20 10:26:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	game_status(t_struct *st)
{
	check_kill(st);
	string_check(st);
}

void	game_hook(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	if (st->collec_cnt == 0 && st->frame_exit < 100)
		open_exit(st, 8);
	game_status(st);
	if (st->exit_stat == 0)
	{	
		key_control(st);
		background_animation(st, 100);
		wall_animation(st, 40);
		col_animation(st, 6);
		enemy_patrol(st);
	}
}

void	end_game(t_struct *st)
{
	if (st->exit_stat == -1)
	{	
		ft_printf("MOVES: %d\n", (int)st->step_cnt);
		print_screen("./textures/escape.txt");
	}
	else if (st->exit_stat == 0)
	{	
		ft_printf("MOVES: %d\n", (int)st->step_cnt);
		print_screen("./textures/win.txt");
	}
	else if (st->exit_stat == 1)
	{	
		ft_printf("MOVES: %d\n", (int)st->step_cnt);
		print_screen("./textures/gameover.txt");
	}
}

/*Falta función para liberar memoria, que se ejecute siempre en end_game, sea
cual sea la exit_stat, y compruebe si cada variable que necesite liberarse
!= NULL -> free (importante comprobar que esa variable viene de un malloc)
Hay que mirar también que variables mlx necesitan liberarse y cuales basta con
funciones del tipo delete_img...*/