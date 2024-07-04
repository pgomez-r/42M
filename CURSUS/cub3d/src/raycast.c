/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:58:21 by pgruz11           #+#    #+#             */
/*   Updated: 2024/07/02 16:51:45 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * TODO: shorten variable name 'map_scale_x' (and '..._y') to fit 80chars
 */

void	ft_raycast(t_data *d, t_rays *rc, float scale_x, float scale_y)
{
	int		i;

	rc->incr_ang = FOV / (N_RAYS - 1);
	rc->curr_ang = d->ply.ang - (FOV / 2);
	ft_set_background(d->imgs.game_view);
	i = N_RAYS;
	while (--i >= 0)
	{
		rc->ray_x = d->ply.x;
		rc->ray_y = d->ply.y;
		while (d->maps.map[(int)rc->ray_y / CELL][(int)rc->ray_x / CELL] != '1')
		{
			mlx_put_pixel(d->imgs.mini_src, (int)(rc->ray_x * scale_x),
				(int)(rc->ray_y * scale_y), PINK);
			rc->ray_y -= sin(rc->curr_ang);
			rc->ray_x += cos(rc->curr_ang);
		}
		ft_wall_render(d, rc, i);
		rc->curr_ang += rc->incr_ang;
	}
}

/*This function bellow is in working progress, still needs many tests*/
void	ft_wall_render(t_data *d, t_rays *rc, int ray_num)
{
	double	win_x;
	double	col_width;
	int		end_x;

	col_width = (double)WIDTH / N_RAYS;
	if (ray_num == 0)
		win_x = 0;
	else
		win_x = round(ray_num * col_width);
	if (ray_num == N_RAYS - 1)
		end_x = WIDTH;
	else
		end_x = round((ray_num + 1) * col_width) - 1;
	rc->wall_dist = ft_wall_distance(d, rc);
	rc->wall_height = ft_wall_heigth(rc->wall_dist, PP);
	ft_draw_wall(d, rc, win_x, (end_x - win_x) + 1);
}

void ft_draw_wall(t_data *d, t_rays *rc, int win_x, int col_width)
{
	int	start;
	int	end;
	int	i;
	int	mid_win;
	int	x;

	mid_win = HEIGTH / 2;
	start = mid_win - (int)(rc->wall_height / 2);
	if (start < 0) 
		start = 0;
	end = start + (int)rc->wall_height;
	if (end >= HEIGTH)
		end = HEIGTH - 1;
	x = win_x;
	while (x < (win_x + col_width))
	{
		i = start;
		while (i < end)
		{
			mlx_put_pixel(d->imgs.game_view, x, i, WHITE);
			i++;
		}
		x++;
	}
}

float	ft_wall_distance(t_data *d, t_rays *rc)
{
	return (sqrt(pow(rc->ray_x - d->ply.x, 2)
		+ pow(rc->ray_y - d->ply.y, 2)));
}

int	ft_wall_heigth(float distance, float plane)
{
	float	wall_gh;
	float	height;

	wall_gh = (float)CELL;
	height = (wall_gh * plane) / distance;
	if (height < 1.0)
		height = 1.0;
	return ((int)height);
}
