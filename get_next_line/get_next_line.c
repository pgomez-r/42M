/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/28 09:39:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_text(int fd)
{
	int		ctr;
	char	*full_text;

	ctr = read(fd, full_text, BUFF_SIZE);
	while (ctr)
	{
		ctr += read(fd, full_text, BUFF_SIZE);
	}
	return (full_text);
}

char	*get_next_line(int fd)
{
	static char	*full_text;
	char		line[BUFF_SIZE];
	char		*aux_str;
	size_t		read_return;

	if (!fd)
		return (-1);
	full_text = save_text(fd, line);
	read_return = read(fd, line, BUFF_SIZE);
	while (read_return > 0)
	{
		line[read_return] = '\0';
	}
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("sometext.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo \n");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		printf("LINEA: %s\n", line);
	}
	close (fd);
	return (0);
}
