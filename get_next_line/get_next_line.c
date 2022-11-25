/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/24 16:08:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;

	line = "Holamundo\n";
}

int	main(void)
{
	int	fd;

	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
	printf(get_next_line(fd));
}
