/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 13:42:48 by pgruz             #+#    #+#             */
/*   Updated: 2023/06/06 22:57:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	get_patrol_dirs(t_struct *st)
{
	size_t	i;

	st->dirs = malloc(sizeof(int) * st->enms);
	st->flags = malloc(sizeof(int) * st->enms);
	i = 0;
	while (i < st->enms)
	{
		st->dirs[i] = calculate_axis(st, (int)i);
		st->flags[i] = 0;
		i++;
	}
}

int	calculate_axis(t_struct *st, int e)
{
	int		y;
	int		x;
	int		i;

	i = -1;
	while (++i < 4)
		st->movs[i] = 0;
	y = st->enemy_d->instances[e].y;
	x = st->enemy_d->instances[e].x;
	i = 0;
	while (st->map[(y - ((++i) * PIX)) / PIX][x / PIX] != '1')
		st->movs[0]++;
	i = 0;
	while (st->map[(y + ((++i) * PIX)) / PIX][x / PIX] != '1')
		st->movs[1]++;
	i = 0;
	while (st->map[y / PIX][(x - ((++i) * PIX)) / PIX] != '1')
		st->movs[2]++;
	i = 0;
	while (st->map[y / PIX][(x + ((++i) * PIX)) / PIX] != '1')
		st->movs[3]++;
	e = (int)ft_maxvalue_pos(st->movs, 4);
	if (e < 2)
		return (0);
	return (1);
}

int	check_traffic(t_struct *st, int mov_y, int mov_x, int i)
{
	int		y;
	int		x;
	size_t	j;
	int		yy;
	int		xx;

	y = (st->enemy_d->instances[i].y + mov_y) / PIX;
	x = (st->enemy_d->instances[i].x + mov_x) / PIX;
	j = -1;
	while (++j < st->enms)
	{
		if (j == (size_t)i)
			j++;
		yy = st->enemy_d->instances[j].y / PIX;
		xx = st->enemy_d->instances[j].x / PIX;
		if (yy == y && xx == x)
			return (-1);
	}
	return (0);
}

void	check_kill(t_struct	*st)
{
	size_t	i;
	int		p_y;
	int		p_x;
	int		e_y;
	int		e_x;

	p_y = st->player_d->instances[0].y + 32;
	p_x = st->player_d->instances[0].x + 32;
	i = 0;
	while (i < st->enms && st->exit_stat == 0)
	{
		e_y = st->enemy_d->instances[i].y + 32;
		e_x = st->enemy_d->instances[i].x + 32;
		if (ft_distance(p_y, e_y) < 54 && ft_distance(p_x, e_x) < 54)
		{
			st->exit_stat = 1;
			place_exp(st, (p_x - 32), (p_y - 32));
			return ;
		}
		i++;
	}
	if (st->exit_stat == 1 && st->frame_exp < 150)
		exp_animation(st, 20);
	else if (st->exit_stat == 1 && st->frame_exp > 150)
		mlx_close_window(st->window);
}

int	ft_distance(int point_a, int point_b)
{
	int	distance;

	distance = point_a - point_b;
	if (distance < 0)
		return (-(distance));
	return (distance);
}
