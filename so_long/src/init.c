/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 22:32:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/12 20:00:41 by pgomez-r         ###   ########.fr       */
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

void	init_collect_stat(t_struct *st)
{	
	size_t	y;

	y = -1;
	st->stat_col = malloc(sizeof(int) * st->cols);
	while (++y < st->cols)
		st->stat_col[y] = 0;
	if (st->width > 4)
	{	
		y = st->height * PIX;
		st->moves_str = mlx_put_string(st->window, st->moves, 6, y - 42);
		st->moves_num = mlx_put_string(st->window, st->moves_cnt, 70, y - 42);
		mlx_image_to_window(st->window, st->col4, 132, y - 64);
		st->col_aux = st->collec_cnt;
		st->orbs_left = ft_itoa(st->collec_cnt);
		st->cols_left = mlx_put_string(st->window, st->orbs_left, 196, y - 42);
	}
	ft_printf("MOVES: %d\r", (int)st->step_cnt);
}
	