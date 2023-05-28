/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/28 11:52:42 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	game_hook(void *param)
{
	t_struct	*st;

	st = (t_struct *)param;
	key_control(st);
	background_animation(st, 100);
	wall_animation(st, 40);
	col_animation(st, 25);
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
	mlx_loop_hook(st.window, game_hook, &st);
	mlx_loop(st.window);
	mlx_terminate(st.window);
	ft_printf("Taluego! Ya te queda menos...=)");
	return (0);
}

/**
 * @brief Lista tareas TO_DO
 * - Esquema capas -> HECHO
 * - Carga de imagenes -> una función por cada tipo de img -> HECHO
 * - Colocar + profundidad cada tipo de imagen -> una función por tipo -> HECHO
 * - Ordenar init_struct, cambiar de t_struct a void y pasarle la original;
 * 		luego partirla en funciones por grupos de elementos -> HECHO
 * - Quitar formato hook a las funciones de animación -> HECHO
 * - Funcion para cambiar depth de dos imagenes del mismo elemento -> HECHO
 * - Desgranar key_control en muchas funciones -> HECHO
 */