/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 00:13:53 by codespace         #+#    #+#             */
/*   Updated: 2024/06/06 16:20:09 by pgruz11          ###   ########.fr       */
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

typedef struct s_struct	t_struct;
typedef struct s_mlx_st	t_mlx_st;
typedef struct s_graphic	t_graphic;

typedef struct s_struct
{
	int		exit_code;
	char	*map[8];
	size_t	height;
	size_t	width;
}	t_struct;

typedef struct s_graphic
{
	t_mlx_st	*st_ptr;
	mlx_image_t	*player;
	mlx_image_t	*wall;
	mlx_image_t	*ground;
}	t_graphic;

typedef struct s_mlx_st
{
	t_struct	*d;
	t_graphic	gfx;
	mlx_t		*game;
}	t_mlx_st;

void			render_map(t_mlx_st *st);
void			load_images(t_mlx_st *st);
void			key_control(t_mlx_st *st);

#endif
