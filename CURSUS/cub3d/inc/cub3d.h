/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:13:53 by codespace         #+#    #+#             */
/*   Updated: 2024/06/13 02:55:11 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# define NAME "CVB3D"
# define PIX 64
# define MOV 4

# include "libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_struct		t_struct; //general program data
typedef struct s_map		t_map; 	//main map and mimimap info and value
typedef struct s_mlx_st		t_mlx_st; //mlx game instance data
typedef struct s_graphic	t_graphic; //mlx textures, images and other visuals
typedef struct s_player		t_player; //first person view player info and values

typedef struct s_struct
{
	int		exit_code;
	char	*map[8];
	size_t	height;
	size_t	width;
	size_t	mini_h;
	size_t	mini_w;
}	t_struct;

typedef struct s_player
{
	t_mlx_st	*st_pt;
	double		x;
	double		y;
	double		ang;
}	t_player;
typedef struct s_graphic
{
	t_mlx_st	*st_ptr;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
	mlx_image_t	*minimap;
}	t_graphic;

typedef struct s_mlx_st
{
	t_struct	*d;
	t_graphic	gfx;
	t_player	fpp;
	mlx_t		*game;
}	t_mlx_st;

void			render_map(t_mlx_st *st);
void			load_images(t_mlx_st *st);
void			key_control(t_mlx_st *st);
void			basic_ray(t_mlx_st *st);
void			update_minimap(t_mlx_st *st);
#endif
