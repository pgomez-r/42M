/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/13 23:09:52 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

void	load_map(t_struct *st)
{
	mlx_texture_t	*way;
	mlx_texture_t	*wall;

	way = mlx_load_png("./Sprites/grass.png");
	st->way = mlx_texture_to_image(st->window, way);
	wall = mlx_load_png("./Sprites/rock.png");
	st->wall = mlx_texture_to_image(st->window, wall);
}

/**
 * TODO -> función que recorra el mapa y ponga en cada 1 roca, lo demás grass
 */

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

int	main(int ac, char **av)
{
	t_struct	st;

	(void)ac;
	read_map(&st, av[1]);
	st.window = mlx_init(st.width, st.height, "so_long_42", false);
	//load_map(&st);
	ft_printf("El mapa, linea 1:\n%s\n", st.map_arr[0]);
	ft_printf("El mapa completo:\n");
	ft_print_dstr(st.map_arr);
	return (0);
}
