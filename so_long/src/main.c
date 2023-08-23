/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/08/11 17:06:19 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

int	main(int ac, char **av)
{
	t_struct		st;

	if (ac != 2)
		return (ft_printf_error("Error\nWrong number of arguments!\n"), -1);
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
