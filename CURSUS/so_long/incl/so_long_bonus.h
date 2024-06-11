/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:51:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/06/11 06:03:28 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100

# endif
/*libs*/
# include "./libft/libft.h"
# include "./MLX42/include/MLX42/MLX42.h"

# define NAME "So_(so)_LONG"
# define PIX 64
# define MOV 4

/*mega_struct!*/
typedef struct s_struct
{
	char			**map;
	char			**cmap;
	char			*map_str;
	char			*moves;
	char			*moves_cnt;
	char			*orbs_left;
	int				player_y;
	int				player_x;
	size_t			width;
	size_t			height;
	size_t			collec_cnt;
	size_t			col_aux;
	size_t			step_cnt;
	size_t			step_pix;
	size_t			walls;
	size_t			ways;
	size_t			exits;
	size_t			cols;
	size_t			enms;
	size_t			frame_enemy;
	size_t			frame_wall;
	size_t			frame_bg;
	size_t			frame_col;
	size_t			frame_exit;
	size_t			frame_exp;
	int				*dirs;
	int				*flags;
	int				movs[4];
	int				*stat_col;
	int				exit_stat;
	mlx_t			*window;
	mlx_texture_t	*texture;
	mlx_image_t		*wall;
	mlx_image_t		*wall1;
	mlx_image_t		*wall2;
	mlx_image_t		*wall3;
	mlx_image_t		*wall4;
	mlx_image_t		*wall5;
	mlx_image_t		*way;
	mlx_image_t		*way1;
	mlx_image_t		*way2;
	mlx_image_t		*way3;
	mlx_image_t		*exit_o;
	mlx_image_t		*exit_1;
	mlx_image_t		*exit_2;
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
	mlx_image_t		*exp1;
	mlx_image_t		*exp2;
	mlx_image_t		*exp3;
	mlx_image_t		*exp4;
	mlx_image_t		*moves_str;
	mlx_image_t		*moves_num;
	mlx_image_t		*cols_left;
}	t_struct;

/*map_validate_bonus.c*/
void				read_map(t_struct *st, char *path);
int					chk_char(char *map);
int					check_format(char *path);
int					chk_shape(t_struct *st);
int					chk_way(t_struct *st);

/*init_bonus.c*/
void				init_struct(t_struct *st);
void				init_imgs_bg(t_struct *st);
void				init_imgs_env(t_struct *st);
void				init_params(t_struct *st);
void				init_collect_stat(t_struct *st);

/*load_images_bonus.c*/
void				load_images(t_struct *st);
void				bg_player_imgs(t_struct *st);
void				walls_imgs(t_struct *st);
void				cols_imgs(t_struct *st);
void				enemy_exit_imgs(t_struct *st);

/*render_images_bonus.c*/
void				render_images(t_struct *st);
void				render_background(t_struct *st);
void				render_walls(t_struct *st);
void				render_player(t_struct *st);
void				render_enemies(t_struct *st);

/*render_images_2_bonus.c*/
void				render_collectables(t_struct *st);
void				render_exits(t_struct *st);
void				collectables_depth(t_struct	*st);
void				walls_depth(t_struct *st);
void				remove_collectable(t_struct *st, int y, int x);

/*animation_bonus.c*/
int					swap_z(mlx_image_t *img1, mlx_image_t *img2, size_t total);
void				col_animation(t_struct *st, size_t timer);
void				background_animation(t_struct *st, size_t timer);
void				wall_animation(t_struct	*st, size_t timer);
void				open_exit(t_struct *st, size_t timer);

/*animation_2_bonus.c*/
void				exp_animation(t_struct *st, size_t timer);
void				explosion_imgs(t_struct *st);
void				place_exp(t_struct *st, size_t x, size_t y);

/*key_control_bonus.c*/
void				move_up(t_struct *st);
void				move_down(t_struct *st);
void				move_left(t_struct *st);
void				move_right(t_struct *st);
void				key_control(t_struct *st);

/*key_control_2_bonus.c*/
void				player_face_y(t_struct *st, char c);
void				player_face_x(t_struct *st, char c);
void				player_move_y(t_struct *st, int direction);
void				player_move_x(t_struct *st, int direction);

/*enemy_patrol_bonus.c*/
void				enemy_patrol(t_struct *st);
void				patrol_y(t_struct *st, size_t i);
void				patrol_x(t_struct *st, size_t i);
void				enemy_move_y(t_struct *st, int i, int mov);
void				enemy_move_x(t_struct *st, int i, int mov);

/*enemy_patrol_2_bonus.c*/
void				get_patrol_dirs(t_struct *st);
int					calculate_axis(t_struct *st, int e);
int					check_traffic(t_struct *st, int mov_y, int mov_x, int i);
void				check_kill(t_struct	*st);
int					ft_distance(int point_a, int point_b);

/*utils_bonus.c*/
void				string_check(t_struct *st);
void				print_screen(char *path);
void				player_coordinates(t_struct *st);
void				sl_floodfill(t_struct *st, int y, int x);
int					check_mapstr(t_struct *st, char *map_str);

/*game_utils_bonus.c*/
void				game_status(t_struct *st);
void				game_hook(void *param);
void				end_game(t_struct *st);
int					chk_pec(char *map);
void				clean_exit(t_struct *st);

#endif