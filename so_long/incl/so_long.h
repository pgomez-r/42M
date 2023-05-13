/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 21:51:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/13 22:56:08 by pgomez-r         ###   ########.fr       */
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

# define PIXELS 64

/*structs*/
typedef struct s_struct
{
	char		**map;
	size_t		width;
	size_t		height;
	size_t		collec_cnt;
	size_t		step_cnt;
	mlx_t		*game;
	mlx_image_t	*wall;
	mlx_image_t	*way;
	mlx_image_t	*exit_o;
	mlx_image_t	*exit_c;
	mlx_image_t	*player;
	mlx_image_t	*enemy;	
	mlx_image_t	*collec;
}	t_struct;

/*temp_pruebas*/

#endif