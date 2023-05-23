/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/23 23:15:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	background_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_bg == 100 && st->way->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			st->way1->instances[i].z = 10;
			st->way->instances[i].z = -10;
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way1->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			st->way2->instances[i].z = 10;
			st->way1->instances[i].z = -20;
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way2->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			st->way->instances[i].z = 10;
			st->way2->instances[i].z = -30;
			i++;
		}
		st->frame_bg = -1;
	}
	st->frame_bg++;
}

void	wall_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_delay == 40 && st->wall->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall1->instances[i], 300);
			mlx_set_instance_depth(&st->wall->instances[i], -300);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall1->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall2->instances[i], 300);
			mlx_set_instance_depth(&st->wall1->instances[i], -400);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall2->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
				mlx_set_instance_depth(&st->wall3->instances[i], 300);
				mlx_set_instance_depth(&st->wall2->instances[i], -500);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall3->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall->instances[i], 300);
			mlx_set_instance_depth(&st->wall3->instances[i], -600);
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
		// st->player_d->instances[0].z = -1000;
		// st->player_u->instances[0].z = 500;
		// st->player_l->instances[0].z = -2200;
		// st->player_r->instances[0].z = -2300;
		if (st->map[((int)(st->player_d->instances[0].y) - MOV) / PIX][(int)st->player_d->instances[0].x / PIX] != '1'
			&& st->map[((int)(st->player_d->instances[0].y) - MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1')
			st->player_d->instances[0].y -= MOV;
			st->player_u->instances[0].y -= MOV;
			st->player_l->instances[0].y -= MOV;
			st->player_r->instances[0].y -= MOV;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		// st->player_d->instances[0].z = 500;
		// st->player_u->instances[0].z = -2100;
		// st->player_l->instances[0].z = -2200;
		// st->player_r->instances[0].z = -2300;
		if (st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1' 
			&& st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x) / PIX] != '1')
			st->player_d->instances[0].y += MOV;
			st->player_u->instances[0].y += MOV;
			st->player_l->instances[0].y += MOV;
			st->player_r->instances[0].y += MOV;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		// st->player_d->instances[0].z = -1000;
		// st->player_u->instances[0].z = -2100;
		// st->player_l->instances[0].z = 500;
		// st->player_r->instances[0].z = -2300;
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1')
			st->player_d->instances[0].x -= MOV;
			st->player_u->instances[0].x -= MOV;
			st->player_l->instances[0].x -= MOV;
			st->player_r->instances[0].x -= MOV;
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		// st->player_d->instances[0].z = -1000;
		// st->player_u->instances[0].z = -2100;
		// st->player_l->instances[0].z = -2200;
		// st->player_r->instances[0].z = 500;
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1')
			st->player_d->instances[0].x += MOV;
			st->player_u->instances[0].x += MOV;
			st->player_l->instances[0].x += MOV;
			st->player_r->instances[0].x += MOV;
	}
	background_animation(st);
	wall_animation(st);
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
	// mlx_loop_hook(st.window, background_animation, &st);
	// mlx_loop_hook(st.window, wall_animation, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}

/**
 * @brief Lista tareas TO_DO
 * - Esquema capas -> HECHO
 * - 1 función por elemento para cargar todas sus imagenes + mlx_depth
 * - 1 función por animación de elemento sin mov (wall, back, coin)
 */