/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/12 18:20:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

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
		ft_printf("Taluego!\n");
	else if (st->exit_stat == 0)
		ft_printf("YOU WIN!!\n");
	else if (st->exit_stat == 1)
		ft_printf("GAME OVER\nTry again...\n");
}

int	main(int ac, char **av)
{
	t_struct		st;

	if (ac != 2)
		return (-1);
	init_struct(&st);
	read_map(&st, av[1]);
	st.window = mlx_init(st.width * PIX, st.height * PIX, NAME, false);
	load_images(&st);
	render_images(&st);
	init_collect_stat(&st);
	mlx_loop_hook(st.window, game_hook, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	end_game(&st);
	return (0);
}
