/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 11:32:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/28 11:32:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);

int	main(void)
{
	int		fd;
	char	*linea;

	fd = open("sometext.txt", O_RDONLY);
	linea = get_next_line(fd);
	printf("Línea:%s\n", linea);
	free (linea);
	return (0);
}
