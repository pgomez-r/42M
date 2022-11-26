/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/26 16:48:48 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	size_t	nbytes_read;
	char	[10];
	nbytes_read = read(fd, buffer, 5);
}

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("sometext.txt", O_RDONLY);
	if (fd == -1)
		printf("Error al abrir el archivo \n");
		return (-1);
	line = get_next_line(fd);
	printf("LINEA: %s\n", line);
	close (fd);
	
	return (0);
}
