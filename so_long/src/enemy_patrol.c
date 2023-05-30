/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:34:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/30 11:27:23 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

/*Vamos a controlar el mov de enemigos, lo enfocamos como en player, con extras
	-Elegir direccion - calcular cual es mejor -> esto lo hacemos en estático,
		antes de game_hook, puede ser al cargar/render img o a parte
		Guardamos en un array la dir, por cada estancia
*/

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
	int		movs[4];
	int		y;
	int		x;
	int		i;

	y = st->enemy_d->instances[e].y;
	x = st->enemy_d->instances[e].x;
	i = -1;
	while (++i < 4)
		movs[i] = 0;
	i = 1;
	while (st->map[(y - (i * PIX)) / PIX][x / PIX] != '1')
	{
		movs[0]++;
		i++;
	}
	i = 1;
	while (st->map[(y + (i * PIX)) / PIX][x / PIX] != '1')
	{
		movs[1]++;
		i++;
	}
	i = 1;
	while (st->map[y / PIX][(x - (i * PIX)) / PIX] != '1')
	{
		movs[2]++;
		i++;
	}
	i = 1;
	while (st->map[y / PIX][(x + (i * PIX)) / PIX] != '1')
	{
		movs[3]++;
		i++;
	}
	e = (int)ft_maxvalue_pos(movs, 4);
	printf("Valor e: %d\n", movs[0]);
	if (e < 2)
		return (0);
	else
		return (1);
}

void	patrol_y(t_struct *st, size_t i)
{
	int	y;
	int	x;

	y = st->enemy_d->instances[i].y;
	x = st->enemy_d->instances[i].x;
	if (st->flags[i] == 0 && st->map[(y - 2) / PIX][x / PIX] != '1')
		st->enemy_d->instances[i].y -= 2;
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[(y + 66) / PIX][x / PIX] != '1')
		st->enemy_d->instances[i].y += 2;
	else
		st->flags[i] = 0;
}

void	patrol_x(t_struct *st, size_t i)
{
	int	y;
	int	x;

	y = st->enemy_d->instances[i].y;
	x = st->enemy_d->instances[i].x;
	if (st->flags[i] == 0 && st->map[y / PIX][(x - 2) / PIX] != '1')
		st->enemy_d->instances[i].x -= 2;
	else
		st->flags[i] = 1;
	if (st->flags[i] == 1 && st->map[y / PIX][(x + 66) / PIX] != '1')
		st->enemy_d->instances[i].x += 2;
	else
		st->flags[i] = 0;
}

void	enemy_patrol(t_struct *st)
{
	size_t	i;

	i = 0;
	while (i < st->enms)
	{
		if (st->dirs[i] == 0)
			patrol_y(st, i);
		else
			patrol_x(st, i);
		i++;
	}
}
