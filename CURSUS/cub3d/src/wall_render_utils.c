

#include "cub3d.h"

unsigned int	ft_get_pix_color(mlx_texture_t *tex, int x, int y)
{
	unsigned int	pos;
	int				r;
	int				g;
	int				b;
	int				a;

	pos = 4 * x + (4 * y * tex->width);
	if (pos <= tex->height * tex->width * tex->bytes_per_pixel)
	{
		r = tex->pixels[pos];
		g = tex->pixels[pos + 1];
		b = tex->pixels[pos + 2];
		a = tex->pixels[pos + 3];
		return (r << 24 | g << 16 | b << 8 | a);
	}
	return (0);
}

void	ft_texture_select(t_data *d)
{
	if (d->rc.wall_dir == 1)
	{
		if (d->rc.dir_y == 1)
			d->tx.tex_ptr = d->imgs.so_texture;
		else
			d->tx.tex_ptr = d->imgs.no_texture;
	}
	else
	{
		if (d->rc.dir_x == 1)
			d->tx.tex_ptr = d->imgs.ea_texture;
		else
			d->tx.tex_ptr = d->imgs.we_texture;
	}
}

float	ft_wall_distance(t_data *d, t_rays *rc)
{
	float	raw_dist;
	float	ang_diff;
	float	fix_dist;

	raw_dist = sqrt(pow(rc->ray_x - d->ply.x, 2)
			+ pow(rc->ray_y - d->ply.y, 2));
	ang_diff = d->ply.ang - rc->curr_ang;
	ang_diff = ft_normalize_angle(ang_diff);
	fix_dist = raw_dist * cos(ang_diff);
	return (fix_dist);
}

int	ft_wall_height(float distance, float plane)
{
	float	wall_gh;
	float	height;

	wall_gh = (float)CELL;
	height = (wall_gh * plane) / distance;
	if (height < 1.0)
		height = 1.0;
	return ((int)height);
}

void	ft_wall_hitpoint(t_rays *rc)
{
	if (rc->wall_dir == 1)
		rc->wall_hp = rc->ray_x / CELL;
	else
		rc->wall_hp = rc->ray_y / CELL;
	rc->wall_hp -= floor(rc->wall_hp);
}
