/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 06:56:52 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/23 06:56:55 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_check_file_name(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] == 'b' && argv[i - 1] == 'u' && argv[i - 2] == 'c'
		&& argv[i - 3] == '.')
		return (1);
	return (0);
}

void	ft_check_args(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Error: Wrong number of arguments\n", 33);
		printf("Usage: ./cub3d <map_name>.cub\n");
		exit(1);
		return ;
	}
	fd = open(argv[1], O_RDONLY);
	close(fd);
	if (fd < 0 || !ft_check_file_name(argv[1]))
	{
		write(2, "Error: Invalid file\n", 20);
		printf("Usage: ./cub3d <map_name>.cub\n");
		exit(1);
	}
	return ;
}

void	ft_check_rgb_color(char *color)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(color);
	if (color[0] == ',' || color[len - 1] == ',')
		ft_invalid_map(1);
	while (color[i] == ',' || ft_isdigit(color[i]))
		i++;
	if (i < len)
		ft_invalid_map(1);
}

void	ft_invalid_map(int mode)
{
	if (mode == 1)
	{
		write (2, "Error: Invalid map\n", 19);
		exit (1);
	}
}
