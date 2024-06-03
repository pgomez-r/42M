/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 17:49:31 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/06/25 20:57:26 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long_bonus.h"

void	string_check(t_struct *st)
{
	int	y;

	y = st->height * PIX;
	if (st->step_pix >= 64)
	{	
		st->step_cnt++;
		st->step_pix = 0;
		mlx_delete_image(st->window, st->moves_num);
		free(st->moves_cnt);
		st->moves_cnt = (ft_itoa(st->step_cnt));
		st->moves_num = mlx_put_string(st->window, st->moves_cnt, 70, y - 42);
		ft_printf("MOVES: %d\r", (int)st->step_cnt);
	}
	if (st->collec_cnt < st->col_aux)
	{
		st->col_aux = st->collec_cnt;
		free(st->orbs_left);
		st->orbs_left = ft_itoa(st->collec_cnt);
		mlx_delete_image(st->window, st->cols_left);
		st->cols_left = mlx_put_string(st->window, st->orbs_left, 196, y - 42);
	}
}

void	print_screen(char *path)
{
	char	*line;
	char	*strscreen;
	char	**screen;	
	int		fd;

	strscreen = malloc(1 * 1);
	fd = open(path, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		strscreen = join_and_free(strscreen, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line != NULL)
		free(line);
	close(fd);
	screen = ft_split(strscreen, '\n');
	ft_print_dstr(screen);
	free(strscreen);
	ft_totalfree(screen);
}

void	player_coordinates(t_struct *st)
{
	int	i;
	int	j;

	i = -1;
	while (++i < (int)st->height)
	{
		j = -1;
		while (++j < (int)st->width)
		{
			if (st->map[i][j] == 'P')
			{
				st->player_y = i;
				st->player_x = j;
				return ;
			}
		}
	}
}

int	check_mapstr(t_struct *st, char *map_str)
{
	size_t	i;

	if (!map_str || map_str[0] == '\0' || map_str[0] == '\n')
	{	
		st->exit_stat = -2;
		return (ft_printf_error("Error\nEmpty map or missing first line\n"), -1);
	}
	i = 0;
	while (map_str[i] != '\0')
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			st->exit_stat = -2;
			return (ft_printf_error("Error\nMap has  empty lines\n"), -1);
		}
		i++;
	}
	return (0);
}

void	sl_floodfill(t_struct *st, int y, int x)
{
	int	h;
	int	w;

	h = st->height;
	w = st->width;
	if (y < 0 || x < 0 || y > h || x > w || st->cmap[y][x] == 'F'
		|| st->cmap[y][x] == '1' || st->cmap[y][x] == 'X')
		return ;
	if (st->cmap[y][x] == '0' || st->cmap[y][x] == 'C' || st->cmap[y][x] == 'E')
		st->cmap[y][x] = 'F';
	sl_floodfill(st, y - 1, x);
	sl_floodfill(st, y + 1, x);
	sl_floodfill(st, y, x - 1);
	sl_floodfill(st, y, x + 1);
}
