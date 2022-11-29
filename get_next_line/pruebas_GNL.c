/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_GNL.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:54:32 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/29 15:18:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{

}

void	free_stack(t_list *stack)
{

}

void	create_line(char **line, t_list *stack)
{
	
}

int	ft_lstlast(t_list *stack)
{

}

int	newline_check(t_list *stack)
{
	
}

void	clean_stack()
{
	
}

void	pull_line()
{
	
}

void	move_to_stack()
{
	
}

void	read_and_save()
{
	
}

char	*get_next_line(int fd)
{
	
}

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
