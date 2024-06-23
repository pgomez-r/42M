/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:58:21 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/22 11:01:42 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Cast one single ray, just to test and try to learn the basics*/
void	basic_ray(t_mlx_st *st)
{
	double 	r_x;
	double	r_y;
	
	r_x = st->gfx.player->instances[0].x;
	r_y = st->gfx.player->instances[0].y;
	while (42)
	{
		mlx_put_pixel(st->gfx.minimap, (int)(r_x * st->d->scale_x),
			(int)(r_y * st->d->scale_y), 0x00FF00FF);
		r_y -= sin(st->fpp.ang);
		r_x += cos(st->fpp.ang);
		if (st->d->map[(int)r_y / PIX][(int)r_x / PIX] == '1')
			break ;
	}
}

float	ft_wall_distance(t_mlx_st *st, t_rays *rc)
{
	return (sqrt(pow(rc->ray_x - st->gfx.player->instances[0].x, 2)
		+ pow(rc->ray_y - st->gfx.player->instances[0].y, 2)));
}

int	ft_wall_heigth(t_mlx_st *st, float distance, float plane)
{
	float	wall_gh;
	float	height;

	(void)st;
	wall_gh = 64.0;
	height = (wall_gh * plane) / distance;
	if (height < 1.0)
		height = 1.0;
	return ((int)height);
}

// Calculate wall_height using the correct perspective projection formula.
// Calculate start as screen_height / 2 - wall_height / 2.
// Calculate end as start + wall_height.
// Ensure win_x is correctly mapped from ray number to screen coordinates.

void ft_draw_wall(t_mlx_st *st, t_rays *rc, int win_x, int col_width)
{
	int	start;
	int	end;
	int	i;
	int	mid_win;
	int	x;

	mid_win = st->game_view->height / 2;
	start = mid_win - (int)(rc->wall_height / 2);
	if (start < 0) 
		start = 0;
	end = start + (int)rc->wall_height;
	if (end >= (int)st->game_view->height)
		end = st->game_view->height - 1;
	x = win_x;
	while (x < (win_x + col_width))
	{
		i = start;
		while (i < end)
		{
			mlx_put_pixel(st->game_view, x, i, WHITE);
			i++;
		}
		x++;
	}
}

int	ft_wall_render(t_mlx_st *st, t_rays *rc, int ray_num)
{
	int	win_x;
	int	col_width;

	col_width = st->game_view->width / st->fpp.n_rays;
	win_x = ray_num * col_width;
	rc->wall_dist = ft_wall_distance(st, rc);
	rc->wall_height = ft_wall_heigth(st, rc->wall_dist, st->fpp.proj_plane);
	ft_draw_wall(st, rc, win_x, col_width);
	return (0);
}

void	cast_rays_range(t_mlx_st *st, t_rays *rc)
{
	int		i;
	int		flag;

	rc->incr_ang = st->fpp.fov / (st->fpp.n_rays - 1);
	rc->curr_ang = st->fpp.ang - (st->fpp.fov / 2);
	i = -1;
	while (++i < st->fpp.n_rays)
	{
		flag = 42;
		rc->ray_x = st->gfx.player->instances[0].x;
		rc->ray_y = st->gfx.player->instances[0].y;
		while (flag)
		{
			mlx_put_pixel(st->gfx.minimap, (int)(rc->ray_x * st->d->scale_x),
				(int)(rc->ray_y * st->d->scale_y), 0x00FF00FF);
			rc->ray_y -= sin(rc->curr_ang);
			rc->ray_x += cos(rc->curr_ang);
			if (st->d->map[(int)rc->ray_y / PIX][(int)rc->ray_x / PIX] == '1')
				flag = ft_wall_render(st, rc, i);
				//break ;
		}
		rc->curr_ang += rc->incr_ang;
	}
	//mlx_image_to_window(st->game, st->game_view, 0, 0);
}