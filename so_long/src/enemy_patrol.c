/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 08:34:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/29 23:13:01 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

/*Vamos a controlar el mov de enemigos, lo enfocamos como en player, con extras
	-Elegir direccion - calcular cual es mejor -> esto lo hacemos en estático,
		antes de game_hook, puede ser al cargar/render img o a parte
		Guardamos en un array la dir, por cada estancia
*/

void get_dirs(t_struct *st)
{
	int	i;

	st->dirs = malloc(sizeof(int) * st->enms);
	i = 0;
	while (i < st->enms)
	{
		st->dirs[i] = calculate_axis(st, i);
		i++;
	}
}

int	calculate_axis(t_struct *st, int e)
{
	int		movs[4];
	int		y;
	int		x;
	int		i;

	y = st->enemy_u->instances[e].y;
	x = st->enemy_u->instances[e].x;
	i = 0;
	while (st->map[(y - ((i++) * PIX)) / PIX][x / PIX] != '1')
		movs[0]++;
	i = 0;
	while (st->map[(y + ((i++) * PIX)) / PIX][x / PIX] != '1')
		movs[1]++;
	i = 0;
	while (st->map[y / PIX][(x - ((i++) * PIX)) / PIX] != '1')
		movs[2]++;
	i = 0;
	while (st->map[y / PIX][(x + ((i++) * PIX)) / PIX] != '1')
		movs[3]++;
	e = ft_maxvalue_pos(movs, 4);
	if (e < 2)
		return (free(movs), 0);
	else
		return (free(movs), 1);
}

void	enemy_patrol(t_struct *st)
{
	int		y;
	int		x;
	int		i;

	y = st->enemy_u->instances[0].y;
	x = st->enemy_u->instances[0].x;
	i = 0;
	while (i < st->enms)
	{
		if (st->dirs[i] == 0)
		{
			patrol_y(st, i);
		}
		else if (st->dirs[i] == 1)
		{
			patrol_x(st, i); //le pasamos i para la instancia correcta, luego hay que conseguir el truco flag de abajo
		}
		i++;
	}
	if (dir == 0)
	{
		if (st->flag == 0 && st->map[(st->enemy_d->instances[0].y - 2) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[0].y - 2) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[0].y -= 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[(st->enemy_d->instances[0].y + 66) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[0].y + 66) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[0].y += 2;
		else
			st->flag = 0;
	}
	else if (dir == 1)
	{
		if (st->flag == 0 && st->map[(st->enemy_d->instances[0].y + 66) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[0].y + 66) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[0].y += 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[(st->enemy_d->instances[0].y - 2) / PIX][x / PIX] != '1'
			&& st->map[(st->enemy_d->instances[0].y - 2) / PIX][x / PIX] != 'X')
			st->enemy_d->instances[0].y -= 2;
		else
			st->flag = 0;
	}
	else if (dir == 2)
	{
		if (st->flag == 0 && st->map[y / PIX][(st->enemy_d->instances[0].x - 2) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[0].x - 2) / PIX] != 'X')
			st->enemy_d->instances[0].x -= 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[y / PIX][(st->enemy_d->instances[0].x + 66) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[0].x + 66) / PIX] != 'X')
			st->enemy_d->instances[0].x += 2;
		else
			st->flag = 0;
	}
	else if (dir == 3)
	{
		if (st->flag == 0 && st->map[y / PIX][(st->enemy_d->instances[0].x + 66) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[0].x + 66) / PIX] != 'X')
			st->enemy_d->instances[0].x += 2;
		else
			st->flag = 1;
		if (st->flag == 1 && st->map[y / PIX][(st->enemy_d->instances[0].x - 2) / PIX] != '1'
			&& st->map[y / PIX][(st->enemy_d->instances[0].x - 2) / PIX] != 'X')
			st->enemy_d->instances[0].x -= 2;
		else
			st->flag = 0;
	}
}
