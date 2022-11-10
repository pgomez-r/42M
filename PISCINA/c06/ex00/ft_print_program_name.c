/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:57:10 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/06 08:36:22 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	cnt;

	(void) argc;
	(void) argv;
	cnt = 0;
	while (argv[0][cnt] != '\0')
	{
		write(1, &argv[0][cnt], 1);
		cnt++;
	}
	write (1, "\n", 1);
	return (0);
}
