/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 18:36:09 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/05/11 18:45:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/so_long.h"

static mlx_image_t		*g_image;

void	ft_paintsquare(uint32_t color)
{
	int32_t		x;
	int32_t		y;

	x = 0;
	while (x < (int32_t)g_image->width)
	{
		y = 0;
		while (y < (int32_t)g_image->height)
		{
			mlx_put_pixel(g_image, x, y, color);
			y++;
		}
		x++;
	}
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		g_image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		g_image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		g_image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		g_image->instances[0].x += 5;
}

int	main(void)
{
	mlx_t			*mlx;
	mlx_texture_t	*texture;

	mlx = mlx_init(1024, 864, "42", false);
	texture = mlx_load_png("hacker.png");
	g_image = mlx_texture_to_image(mlx, texture);
	//g_image = mlx_new_image(mlx, 128, 128);
	mlx_image_to_window(mlx, g_image, 0, 0);
	//ft_paintsquare(0x800080ff);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("Has cerrado la ventanada, shulo\n");
	return (0);
}
