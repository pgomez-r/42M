/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/31 22:11:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	read_map(t_struct *st, char *path)
{
	char	*line;
	char	*map_str;
	int		fd;

	map_str = malloc(1 * 1);
	line = malloc (1 * 1);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		map_str = ft_strjoin(map_str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	close(fd);
	st->map = ft_split(map_str, '\n');
	st->width = ft_strlen(st->map[0]);
	st->height = ft_strdlen(st->map);
}

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
