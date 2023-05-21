/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:51:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/21 23:18:38 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif
/*libs*/
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"
# include "./MLX42/include/MLX42/MLX42_Input.h"

# define PIX 64

/*structs*/
typedef struct s_struct
{
	char		**map;
	size_t		width;
	size_t		height;
	size_t		collec_cnt;
	size_t		step_cnt;
	size_t		player_y;
	size_t		player_x;
	size_t		walls;
	size_t		ways;
	size_t		frame_delay;
	mlx_t		*window;
	mlx_image_t	*wall;
	mlx_image_t	*wall1;
	mlx_image_t	*wall2;
	mlx_image_t	*wall3;
	mlx_image_t	*way;
	mlx_image_t	*way1;
	mlx_image_t	*way2;
	mlx_image_t	*exit_o;
	mlx_image_t	*exit_c;
	mlx_image_t	*player;
	mlx_image_t	*enemy;	
	mlx_image_t	*collec;
}	t_struct;

/*main.c*/

/*init.c*/
void				read_map(t_struct *st, char *path);
void				load_images(t_struct *st);
void				load_background(t_struct *st);
void				load_walls(t_struct *st);
void				load_player_collect(t_struct *st);

/*utils.c*/
t_struct			set_empty(void);
void				error_exit(char *error);

#endif