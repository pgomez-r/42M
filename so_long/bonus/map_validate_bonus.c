/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:23:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/25 16:40:05 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

/**
 * @brief Lista de comproboaciones según subject.pdf
 * - Extensión .brew
 * - Char permitido: 0, 1, C, E, P, X
 * - Exit y Player una unidad cada
 * - Medidas rectangulares (x > y)
 * - Mapa rodeado de '1'
 * - Camino válido (floodfill)
 */

/*Check .brew en path*/
int	check_format(char *path)
{
	int	len;
	int	i;

	i = -1;
	len = ft_strlen(path);
	while (++i < (len - 4))
		path++;
	if (ft_strcmp(path, ".ber") != 0)
		return (ft_printf("Error\nWrong map file format (not .ber)\n"), -1);
	return (0);
}

void	read_map(t_struct *st, char *path)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		st->map_str = join_and_free(st->map_str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	close(fd);
	if (check_mapstr(st, st->map_str))
		return ;
	st->map = ft_split(st->map_str, '\n');
	st->cmap = ft_split(st->map_str, '\n');
	st->width = ft_strlen(st->map[0]);
	st->height = ft_strdlen(st->map);
	if (chk_char(st->map_str) || chk_pec(st->map_str) || chk_shape(st)
		|| chk_way(st))
		st->exit_stat = -2;
}

/*Check .ber y que solo haya chars permitidos y un solo P y E*/
int	chk_char(char *map)
{
	int		i;
	int		nplayer;
	int		nexit;
	int		ncollec;

	nplayer = 0;
	nexit = 0;
	ncollec = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '0' || map[i] == '1' || map[i] == 'X' || map[i] == '\n'
			|| map[i] == 'P' || map[i] == 'E' || map[i] == 'C')
			i++;
		else
			return (ft_printf("Error\nWrong characters in map.ber\n"), -1);
	}
	return (0);
}

/*Check si rectangular y si está rodeado de 1*/
int	chk_shape(t_struct *st)
{
	int	i;

	if (st->height >= st->width)
		return (ft_printf("Error\nMap is not rectangular\n"), -1);
	i = -1;
	while (++i < (int)st->width)
	{
		if (st->map[0][i] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
		if (st->map[st->height - 1][i] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
	}
	i = -1;
	while (++i < (int)st->height)
	{
		if (st->map[i][0] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
		if (st->map[i][st->width - 1] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
	}
	return (0);
}

/*Ubicar las coords de player, hacer el famoso floodfill, luego check si hay E*/
int	chk_way(t_struct *st)
{
	int	i;
	int	j;

	player_coordinates(st);
	sl_floodfill(st, st->player_y, st->player_x);
	i = -1;
	while (++i < (int)st->height)
	{
		j = -1;
		while (++j < (int)st->width)
		{
			if (st->cmap[i][j] == 'E' || st->cmap[i][j] == 'C')
				return (ft_printf("Error\nNo valid path in the map\n"), -1);
		}
	}
	return (0);
}
