/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 18:23:33 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/20 10:23:13 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

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
	while (i++ < (len - 5))
		path++;
	if (!ft_strcmp(path, ".brew"))
		return (ft_printf("Error\nWrong map file format (not .brew)\n"), -1);
	return (1);
}

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
	st->cmap = ft_split(map_str, '\n');
	st->width = ft_strlen(st->map[0]);
	st->height = ft_strdlen(st->map);
	if (!check_elements(map_str) || !check_shape(st) || !check_wayout(st))
		st->exit_stat = -2;
}

/*Check .brew y que solo haya chars permitidos y un solo P y E*/
int	check_elements(char *map)
{
	int		i;
	int		flag_p;
	int		flag_e;

	flag_p = 0;
	flag_e = 0;
	i = 0;
	while (map[i] != '\0')
	{
		if (map[i] == '0' || map[i] == '1' || map[i] == 'X' || map[i] == 'C')
			i++;
		else if (map[i] == 'P' || map[i] == 'E')
		{
			if (map[i] == 'P')
				flag_p++;
			if (map[i] == 'E')
				flag_e++;
			i++;
		}
		else
			return (ft_print("Error\nWrong characters in map.brew\n"), -1);
	}
	if (flag_p > 1 || flag_e > 1)
		return (ft_printf("Error\nMore than one PLAYER or EXIT\n"), -1);
	return (1);
}

/*Check si rectangular y si está rodeado de 1*/
int	check_shape(t_struct *st)
{
	int	i;
	int	j;

	if (st->height >= st->width)
		return (ft_printf("Error\nMap is not rectangular\n"), -1);
	i = -1;
	while (i++ < (int)st->width)
	{
		if (st->map[0][i] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
		if (st->map[st->height][i] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
	}
	i = -1;
	while (i++ < (int)st->height)
	{
		if (st->map[i][0] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
		if (st->map[i][st->width] != '1')
			return (ft_printf("Error\nMap is not surrounded by walls\n"), -1);
	}
	return (1);
}

/*Ubicar las coords de player, hacer el famoso floodfill, luego check si hay E*/
int	check_wayout(t_struct *st)
{
	int	i;
	int	j;

	player_coordinates(st);
	sl_floodfill(st, st->player_y, st->player_x);
	i = -1;
	while (i++ < st->height)
	{
		j = -1;
		while (j++ < st->width)
		{
			if (st->cmap[i][j] == 'E')
				return (ft_printf("Error\nNo valid path in the map\n"), -1);
		}
	}
	return (1);
}
