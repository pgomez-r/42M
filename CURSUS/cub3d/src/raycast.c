/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:58:21 by pgruz11           #+#    #+#             */
/*   Updated: 2024/06/16 21:37:08 by pgruz11          ###   ########.fr       */
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

/*Another test, this time multiple rays covering the whole player's FOV*/
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
				ft_wall_render(st, rc, i);
		}
		rc->curr_ang += rc->incr_ang;
	}
}

float	ft_wall_distance(t_mlx_st *st, t_rays *rc)
{
	return (sqrt(pow(rc->ray_x - st->gfx.player->instances[0].x, 2))
		+ pow(rc->ray_y - st->gfx.player->instances[0].y, 2));
}

int	ft_wall_heigth(t_mlx_st *st, float distance, float plane)
{
	return ((int)st->d->height / distance * plane);
}

void ft_draw_wall(t_mlx_st *st, t_rays *rc, int win_x)
{
	int	start;
	int	end;
	int	i;
	int	mid_win;

	mid_win = (st->d->height * PIX) / 2
	start = mid_screen - ((st->d->height * PIX) / 2);
	if (start < 0) 
		start = 0;
	end = mid_screen + ((st->d->height * PIX) / 2);
	if (end >= (st->d->height * PIX))
		end = (st->d->height * PIX) - 1;
	i = start;
	while (i < end)
	{
		mlx_put_pixel(st->game_view, win_x, i, st->d->wall_color);
		i++;
	}
}

int	ft_wall_render(t_mlx_st *st, t_rays *rc, int ray_num)
{
	rc->wall_dist = ft_wall_distance(st, rc);
	rc->wall_height = ft_wall_heigth(st, rc->wall_dist, st->fpp.proj_plane);
	ft_draw_wall(t_mlx_st *st, t_rays *rc, ray_num);
	return (0);
}

// ### **1. Calculate Ray Distance and Wall Height**
// - For each ray, when it hits '1', calculate the distance from the player to the wall. 
// - Use this distance to calculate the height of the wall slice (vertical) to draw on the screen. 
// `wallHeight = (screenHeight / distanceToWall) * distanceToProjectionPlane`
//	`distanceToProjectionPlane` is a fixed value that depends on the FOV and the screen width.

// ### **2. Draw Walls**
// - For each ray, draw a vertical line on the screen. The height of the line depends of wall height
// The position (x-coordinate) on the screen corresponds to the ray's index or angle.
// - The color of the line can be determined by the type of wall hit or its distance (to simulate lighting effects).

// SUMARY_for each ray:
// - calculate distance to wall
// - calculate wall slice height
// - draw vertical line at ray's x-coordinate with calculated height


// Within cast_rays_range, right before increase `ang_curr` call another function to draw a vertical line
// This line's height will be determined by the distance from the player to the wall
//	which you can calculate based on the final `r_x` and `r_y` values for each ray when it '1'

// Here's a conceptual outline of how you might implement this:

// 1. **Calculate the Distance:** Calculate the distance from the player to the wall for each ray
//This can be done using the difference between the player's position and the ray's collision point with the wall.
// 2. **Determine Wall Height:** 
// Use the calculated distance to determine the height of the wall slice to draw
//The height can be inversely proportional to the distance (closer walls are taller).
// 3. **Draw the Wall Slice:** Call a function to draw a vertical line
//on the screen at the appropriate position, with the calculated height.

// ### **Example Pseudocode**
// *float* distanceToWall = calculate_distance(st->gfx.player->instances[0].x, st->gfx.player->instances[0].y, r_x, r_y);

// *int* wallHeight = calculate_wall_height(distanceToWall, st->d->*projectionPlane*);

// draw_wall_slice(st, i, wallHeight); // i is the current ray's screen x-coordinate

// ### **Supporting Functions**
// You would need to implement or define `calculate_distance`, `calculate_wall_height`, and `draw_wall_slice`

// *float* calculate_distance(*float* *x1*, *float* *y1*, *float* *x2*, *float* *y2*) {

// Use Pythagorean theorem to calculate distance

// return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

// }

// *int* calculate_wall_height(*float* *distance*, *float* *projectionPlane*) {

// Example calculation, adjust based on your FOV and screen dimensions

// return (*int*)(SCREEN_HEIGHT / distance * projectionPlane);

// }

// *void* draw_wall_slice(t_mlx_st **st*, *int* *x*, *int* *height*) {

// Draw a vertical line at x-coordinate [`x`] with the given `height`

// You might need to adjust the starting y-coordinate based on the height

// to draw the line centered vertically on the screen

// }