/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:57:19 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/06 08:51:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	arg_ind;
	int	cnt;

	(void) argc;
	(void) argv;
	cnt = 0;
	arg_ind = 1;
	while (arg_ind < argc)
	{
		while (argv[arg_ind][cnt] != '\0')
		{
			write(1, &argv[arg_ind][cnt], 1);
			cnt++;
		}
		write(1, "\n", 1);
		cnt = 0;
		arg_ind++;
	}
	return (0);
}
