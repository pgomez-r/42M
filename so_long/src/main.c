/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/23 18:39:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	ft_leaks(void)
{
	system("leaks -q so_long");
}

int	main(int ac, char **av)
{
	t_struct		st;

	atexit(ft_leaks);
	if (ac != 2)
		return (ft_printf("Error\nSo_long only works with two arguments!\n"), -1);
	if (check_format(av[1]))
		return (-1);
	init_struct(&st);
	read_map(&st, av[1]);
	if (st.exit_stat == 0)
	{
		st.window = mlx_init(st.width * PIX, st.height * PIX, NAME, false);
		load_images(&st);
		render_images(&st);
		init_collect_stat(&st);
		mlx_loop_hook(st.window, game_hook, &st);
		mlx_loop(st.window);
		mlx_terminate(st.window);
	}
	end_game(&st);
	return (0);
}
