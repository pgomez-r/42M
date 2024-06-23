/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:57:22 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/06 12:53:52 by pgomez-r         ###   ########.fr       */
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
	arg_ind = argc -1;
	while (arg_ind > 0)
	{
		while (argv[arg_ind][cnt] != '\0')
		{
			write(1, &argv[arg_ind][cnt], 1);
			cnt++;
		}
		write(1, "\n", 1);
		cnt = 0;
		arg_ind--;
	}
	return (0);
}
