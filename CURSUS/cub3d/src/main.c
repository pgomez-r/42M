/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:12:36 by codespace         #+#    #+#             */
/*   Updated: 2024/06/06 16:18:57 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game_hook(void *param)
{
	t_mlx_st	*st;

	st = (t_mlx_st *)param;
	if (st->d->exit_code == 0)
	{
		key_control(st);
	}
}

void	init_data(t_struct *d, t_mlx_st *st)
{
	d->map[0] = "11111111";
	d->map[1] = "10100001";
	d->map[2] = "10110001";
	d->map[3] = "10010001";
	d->map[4] = "10000001";
	d->map[5] = "10P00101";
	d->map[6] = "10000001";
	d->map[7] = "11111111";
	d->height = 8;
	d->width = 8;
	d->exit_code = 0;
	st->d = d;
	st->gfx.st_ptr = st;
}

int	main(void)
{
	t_struct	d;
	t_mlx_st	st;

	init_data(&d, &st);
	if (d.exit_code == 0)
	{
		st.game = mlx_init(d.height * PIX, d.width * PIX, "test", false);
		load_images(&st);
		render_map(&st);
		mlx_loop_hook(st.game, game_hook, &st);
		mlx_loop(st.game);
		mlx_terminate(st.game);
	}
	return (0);
}
