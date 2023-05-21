/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/21 23:20:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	wall_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_delay == 20 && st->wall->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			st->wall->instances[i].z = -100;
			st->wall1->instances[i].z = 30;
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 20 && st->wall1->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			st->wall1->instances[i].z = -100;
			st->wall2->instances[i].z = 30;
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 20 && st->wall2->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			st->wall2->instances[i].z = -100;
			st->wall3->instances[i].z = 30;
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 20 && st->wall3->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			st->wall3->instances[i].z = -100;
			st->wall->instances[i].z = 30;
			i++;
		}
		st->frame_delay = -1;
	}
	st->frame_delay++;
}

void	key_control(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
		mlx_close_window(st->window);
	if (mlx_is_key_down(st->window, MLX_KEY_UP))
	{	
		if (st->map[((int)(st->player->instances[0].y + 40) - 5) / PIX][(int)st->player->instances[0].x / PIX] != '1'
			&& st->map[((int)(st->player->instances[0].y + 40) - 5) / PIX][((int)st->player->instances[0].x + 64) / PIX] != '1')
			st->player->instances[0].y -= 5;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		if (st->map[((int)(st->player->instances[0].y + 90) + 5) / PIX][((int)st->player->instances[0].x + 64) / PIX] != '1' 
			&& st->map[((int)(st->player->instances[0].y + 90) + 5) / PIX][((int)st->player->instances[0].x) / PIX] != '1')
			st->player->instances[0].y += 5;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		if (st->map[((int)st->player->instances[0].y + 40) / PIX][((int)st->player->instances[0].x - 5) / PIX] != '1'
			&& st->map[((int)st->player->instances[0].y + 90) / PIX][((int)st->player->instances[0].x - 5) / PIX] != '1')
			st->player->instances[0].x -= 5;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		if (st->map[((int)st->player->instances[0].y + 40) / PIX][(((int)st->player->instances[0].x + 64) + 5) / PIX] != '1'
			&& st->map[((int)st->player->instances[0].y + 90) / PIX][(((int)st->player->instances[0].x + 64) + 5) / PIX] != '1')
			st->player->instances[0].x += 5;
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
	load_background(&st);
	load_walls(&st);
	load_player_collect(&st);
	mlx_loop_hook(st.window, key_control, &st);
	mlx_loop_hook(st.window, wall_animation, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}
