/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:51:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/31 22:11:55 by pgomez-r         ###   ########.fr       */
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

# define NAME "So_(so)_LONG"
# define PIX 64
# define MOV 4

/*structs - mega_struct*/
typedef struct s_struct
{
	char			**map;
	size_t			width;
	size_t			height;
	size_t			collec_cnt;
	size_t			step_cnt;
	size_t			walls;
	size_t			ways;
	size_t			exits;
	size_t			cols;
	size_t			enms;
	size_t			frame_enemy;
	size_t			frame_wall;
	size_t			frame_bg;
	size_t			frame_col;
	int				*dirs;
	int				*flags;
	int				movs[4];
	mlx_t			*window;
	mlx_texture_t	*texture;
	mlx_image_t		*wall;
	mlx_image_t		*wall1;
	mlx_image_t		*wall2;
	mlx_image_t		*wall3;
	mlx_image_t		*way;
	mlx_image_t		*way1;
	mlx_image_t		*way2;
	mlx_image_t		*exit_o;
	mlx_image_t		*exit_c;
	mlx_image_t		*player_u;
	mlx_image_t		*player_d;
	mlx_image_t		*player_l;
	mlx_image_t		*player_r;
	mlx_image_t		*enemy_u;
	mlx_image_t		*enemy_d;
	mlx_image_t		*enemy_l;
	mlx_image_t		*enemy_r;	
	mlx_image_t		*col1;
	mlx_image_t		*col2;
	mlx_image_t		*col3;
	mlx_image_t		*col4;
	mlx_image_t		*col5;
	mlx_image_t		*col6;
}	t_struct;

/*main.c*/

/*init.c*/
void				read_map(t_struct *st, char *path);
void				enemy_patrol(t_struct *st);
void				get_patrol_dirs(t_struct *st);

/*init_struct.c*/
void				init_struct(t_struct *st);
void				init_mlx(t_struct *st);
void				init_params(t_struct *st);

/*load_images.c*/
void				load_images(t_struct *st);
void				map_imgs(t_struct *st);
void				player_imgs(t_struct *st);
void				cols_imgs(t_struct *st);
void				enemy_exit_imgs(t_struct *st);

/*render_images.c*/
void				render_images(t_struct *st);
void				render_background(t_struct *st);
void				render_walls(t_struct *st);
void				render_player(t_struct *st);
void				render_enemies(t_struct *st);

/*render_images_2.c*/
void				render_collectables(t_struct *st);
void				render_exits(t_struct *st);
void				collectables_depth(t_struct	*st);
void				remove_collectable(t_struct *st, int y, int x);

/*animation.c*/
int					swap_z(mlx_image_t *img1, mlx_image_t *img2, size_t total);
void				col_animation(t_struct *st, size_t timer);
void				background_animation(t_struct *st, size_t timer);
void				wall_animation(t_struct	*st, size_t timer);

/*key_control.c*/
void				move_up(t_struct *st);
void				move_down(t_struct *st);
void				move_left(t_struct *st);
void				move_right(t_struct *st);
void				key_control(t_struct *st);

/*key_control_2.c*/
void				player_face_y(t_struct *st, char c);
void				player_face_x(t_struct *st, char c);
void				player_move_y(t_struct *st, int direction);
void				player_move_x(t_struct *st, int direction);

/*enemy_patrol*/
int					calculate_axis(t_struct *st, int e);
void				patrol_y(t_struct *st, size_t i);
void				patrol_x(t_struct *st, size_t i);

#endif