/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/25 22:35:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	col_animation(void *param)
{
	t_struct	*st;
	size_t		i;

	st = (t_struct *)param;
	i = 0;
	if (st->frame_col == 25 && st->col1->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col2->instances[i], 110);
			mlx_set_instance_depth(&st->col1->instances[i], -110);
			i++;
		}
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col2->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col3->instances[i], 110);
			mlx_set_instance_depth(&st->col2->instances[i], -120);
			i++;
		}
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col3->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col4->instances[i], 110);
			mlx_set_instance_depth(&st->col3->instances[i], -130);
			i++;
		}
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col4->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col5->instances[i], 110);
			mlx_set_instance_depth(&st->col4->instances[i], -140);
			i++;
		}
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col5->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col6->instances[i], 110);
			mlx_set_instance_depth(&st->col5->instances[i], -150);
			i++;
		}
		st->frame_col = -1;
	}
	else if (st->frame_col == 25 && st->col6->instances[i].z > 0)
	{	
		while (i < st->cols)
		{
			mlx_set_instance_depth(&st->col1->instances[i], 110);
			mlx_set_instance_depth(&st->col6->instances[i], -160);
			i++;
		}
		st->frame_col = -1;
	}
	st->frame_col++;
}

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
			mlx_set_instance_depth(&st->way1->instances[i], 10);
			mlx_set_instance_depth(&st->way->instances[i], -10);
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way1->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			mlx_set_instance_depth(&st->way2->instances[i], 10);
			mlx_set_instance_depth(&st->way1->instances[i], -20);
			i++;
		}
		st->frame_bg = -1;
	}
	else if (st->frame_bg == 100 && st->way2->instances[i].z > 0)
	{	
		while (i < st->ways)
		{
			mlx_set_instance_depth(&st->way->instances[i], 10);
			mlx_set_instance_depth(&st->way2->instances[i], -30);
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
			mlx_set_instance_depth(&st->wall1->instances[i], 110);
			mlx_set_instance_depth(&st->wall->instances[i], -110);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall1->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall2->instances[i], 110);
			mlx_set_instance_depth(&st->wall1->instances[i], -120);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall2->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall3->instances[i], 110);
			mlx_set_instance_depth(&st->wall2->instances[i], -130);
			i++;
		}
		st->frame_delay = -1;
	}
	else if (st->frame_delay == 40 && st->wall3->instances[i].z > 0)
	{	
		while (i < st->walls)
		{
			mlx_set_instance_depth(&st->wall->instances[i], 110);
			mlx_set_instance_depth(&st->wall3->instances[i], -140);
			i++;
		}
		st->frame_delay = -1;
	}
	st->frame_delay++;
}

void	enemy_patrol(t_struct *st)
{
	if (mlx_is_key_down(st->window, MLX_KEY_UP))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], 310);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][(int)st->player_d->instances[0].x / PIX] != '1'
			&& st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1')
		{		
			st->player_d->instances[0].y -= MOV;
			st->player_u->instances[0].y -= MOV;
			st->player_l->instances[0].y -= MOV;
			st->player_r->instances[0].y -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], 310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1' 
			&& st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x) / PIX] != '1')
		{		
			st->player_d->instances[0].y += MOV;
			st->player_u->instances[0].y += MOV;
			st->player_l->instances[0].y += MOV;
			st->player_r->instances[0].y += MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], 310);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x -= MOV;
			st->player_u->instances[0].x -= MOV;
			st->player_l->instances[0].x -= MOV;
			st->player_r->instances[0].x -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], 310);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x += MOV;
			st->player_u->instances[0].x += MOV;
			st->player_l->instances[0].x += MOV;
			st->player_r->instances[0].x += MOV;
		}
	}
	background_animation(st);
	wall_animation(st);
	col_animation(st);
}

void	key_control(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	if (mlx_is_key_down(st->window, MLX_KEY_ESCAPE))
		mlx_close_window(st->window);
	if (mlx_is_key_down(st->window, MLX_KEY_UP))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], 310);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][(int)st->player_d->instances[0].x / PIX] != '1'
			&& st->map[((int)(st->player_d->instances[0].y + 4) - MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1')
		{		
			st->player_d->instances[0].y -= MOV;
			st->player_u->instances[0].y -= MOV;
			st->player_l->instances[0].y -= MOV;
			st->player_r->instances[0].y -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_DOWN))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], 310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x + 60) / PIX] != '1' 
			&& st->map[((int)(st->player_d->instances[0].y + 60) + MOV) / PIX][((int)st->player_d->instances[0].x) / PIX] != '1')
		{		
			st->player_d->instances[0].y += MOV;
			st->player_u->instances[0].y += MOV;
			st->player_l->instances[0].y += MOV;
			st->player_r->instances[0].y += MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_LEFT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], 310);
		mlx_set_instance_depth(&st->player_r->instances[0], -340);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][((int)st->player_d->instances[0].x - MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x -= MOV;
			st->player_u->instances[0].x -= MOV;
			st->player_l->instances[0].x -= MOV;
			st->player_r->instances[0].x -= MOV;
		}
	}
	if (mlx_is_key_down(st->window, MLX_KEY_RIGHT))
	{	
		mlx_set_instance_depth(&st->player_d->instances[0], -310);
		mlx_set_instance_depth(&st->player_u->instances[0], -320);
		mlx_set_instance_depth(&st->player_l->instances[0], -330);
		mlx_set_instance_depth(&st->player_r->instances[0], 310);
		if (st->map[((int)st->player_d->instances[0].y + 4) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1'
			&& st->map[((int)st->player_d->instances[0].y + 60) / PIX][(((int)st->player_d->instances[0].x + 60) + MOV) / PIX] != '1')
		{	
			st->player_d->instances[0].x += MOV;
			st->player_u->instances[0].x += MOV;
			st->player_l->instances[0].x += MOV;
			st->player_r->instances[0].x += MOV;
		}
	}
	background_animation(st);
	wall_animation(st);
	col_animation(st);
}

int	main(int ac, char **av)
{
	t_struct		st;

	(void)ac;
	st = set_empty();
	read_map(&st, av[1]);
	st.window = mlx_init(st.width * PIX, st.height * PIX, NAME, false);
	load_images(&st);
	render_images(&st);
	mlx_loop_hook(st.window, key_control, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}

/**
 * @brief Lista tareas TO_DO
 * - Esquema capas -> HECHO
 * - Carga de imagenes -> una función que llame a varias funciones, una por tipo de img -> HECHO
 * - Colocar + profundidad cada tipo de imagen -> una función + funcion por tipo(mlx_depth) -> HECHO
 * - FUNCION AUX QUE CAMBIE LA Z DE CUALQUIER INSTANCIA? (meter las capas de imgen en array?)
 * - Ordenar init struct, cambiar de t_struct a void y pasarle la original, luego partirla en
 * 		funciones por grupos de elementos ->
 */