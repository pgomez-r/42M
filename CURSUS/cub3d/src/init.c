/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 14:58:49 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/30 20:47:47 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_place_player(t_data *d)
{
	int	y;
	int	x;

	y = -1;
	while (++y < d->maps.map_height)
	{
		x = -1;
		while (++x < d->maps.map_width)
		{
			if (d->maps.map[y][x] == 'P')
			{
				d->ply.y = (y * CELL) + (CELL / 2);
				d->ply.x = (x * CELL) + (CELL / 2);
				break ;
			}
		}
	}
}

void	ft_map_maker(t_data *d)
{
	int	i;

	i = -1;
	while (++i < 8)
		d->maps.map[i] = malloc(sizeof(char) * 9);
	d->maps.map[0] = "11111111\0";
	d->maps.map[1] = "10100001\0";
	d->maps.map[2] = "10110001\0";
	d->maps.map[3] = "10010001\0";
	d->maps.map[4] = "10000001\0";
	d->maps.map[5] = "10P00101\0";
	d->maps.map[6] = "10000001\0";
	d->maps.map[7] = "11111111\0";
	d->maps.map[8] = NULL;
}

void	ft_fake_map_parse(t_data *d)
{
	d->maps.map = malloc(sizeof(char *) * 9);
	ft_map_maker(d);
	d->maps.map_height = 8;
	d->maps.map_width = 8;
	d->maps.pix_height = d->maps.map_height * CELL;
	d->maps.pix_width = d->maps.map_width * CELL;
	d->maps.minimap_w = d->maps.map_width * MINICELL; 
	d->maps.minimap_h = d->maps.map_height * MINICELL;
	d->imgs.c_color = BLUE;
	d->imgs.f_color = GREEN;
	ft_place_player(d);
	d->ply.ang = NORTH;
}

void	ft_init(t_data *d)
{
	d->exit_code = 0;
	d->maps.dpt = d;
	d->imgs.dpt = d;
	d->ply.dpt = d;
	d->rc.dpt = d;
	ft_fake_map_parse(d);
}
