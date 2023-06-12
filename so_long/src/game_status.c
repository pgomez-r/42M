/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:49:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/12 20:00:44 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	game_status(t_struct *st)
{
	check_kill(st);
	string_check(st);
}

void	string_check(t_struct *st)
{
	int	y;

	y = st->height * PIX;
	if (st->step_pix >= 64)
	{	
		st->step_cnt++;
		st->step_pix = 0;
		mlx_delete_image(st->window, st->moves_num);
		st->moves_cnt = (ft_itoa(st->step_cnt));
		st->moves_num = mlx_put_string(st->window, st->moves_cnt, 70, y - 42);
		ft_printf("MOVES: %d\r", (int)st->step_cnt);
	}
	if (st->collec_cnt < st->col_aux)
	{
		st->col_aux = st->collec_cnt;
		st->orbs_left = ft_itoa(st->collec_cnt);
		mlx_delete_image(st->window, st->cols_left);
		st->cols_left = mlx_put_string(st->window, st->orbs_left, 196, y - 42);
	}
}
