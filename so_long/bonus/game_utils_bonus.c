/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:37:02 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/25 20:52:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

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
	clean_exit(st);
}

void	clean_exit(t_struct *st)
{
	if (st->map_str != NULL)
		free(st->map_str);
	if (st->map != NULL)
		ft_totalfree(st->map);
	if (st->cmap != NULL)
		ft_totalfree(st->cmap);
	if (st->stat_col != NULL)
		free(st->stat_col);
	if (st->dirs != NULL)
		free(st->dirs);
	if (st->flags != NULL)
		free(st->flags);
	if (st->moves_cnt != NULL)
		free(st->moves_cnt);
	if (st->orbs_left != NULL)
		free(st->orbs_left);
}

int	chk_pec(char *map)
{
	int		i;
	int		nplayer;
	int		nexit;
	int		ncollect;

	nplayer = 0;
	nexit = 0;
	ncollect = 0;
	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == 'P')
			nplayer++;
		if (map[i] == 'E')
			nexit++;
		if (map[i] == 'C')
			ncollect++;
	}
	if (nplayer != 1)
		return (ft_printf_error("Error\nInvalid number of players\n"), -1);
	if (nexit != 1)
		return (ft_printf_error("Error\nInvalid number of exits\n"), -1);
	if (ncollect == 0)
		return (ft_printf_error("Error\nThere is no collectibles!\n"), -1);
	return (0);
}
