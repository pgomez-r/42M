/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/15 23:21:50 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	key_control(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
		mlx_close_window(st->window);
	if (mlx_is_key_down(st->window, MLX_KEY_UP))
	{	
		if (st->map[(st->player_y - 5) / PIX][st->player_x / PIX] != '1')
		{	
			st->player->instances[0].y -= 5;
			st->player_y -= 5;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		if (st->map[(st->player_y + 5) / PIX][st->player_x / PIX] != '1')
		{	
			st->player->instances[0].y += 5;
			st->player_y += 5;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		if (st->map[st->player_y / PIX][(st->player_x - 5) / PIX] != '1')
		{	
			st->player->instances[0].x -= 5;
			st->player_x -= 5;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		if (st->map[st->player_y / PIX][(st->player_x + 5) / PIX] != '1')
		{	
			st->player->instances[0].x += 5;
			st->player_y += 5;
		}
	}
}

int	main(int ac, char **av)
{
	t_struct		st;

	(void)ac;
	st = set_empty();
	read_map(&st, av[1]);
	st.window = mlx_init(st.width * PIX, st.height * PIX, "so_long_42", false);
	load_images(&st);
	load_map(&st);
	load_player_collect(&st);
	mlx_loop_hook(st.window, key_control, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}
