/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/03 23:15:35 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	if (stack[i] == '\n')
	{	
		line[i] = stack[i];
		i++;
	}
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

	i = 0;
	p = ft_strchr(stack, '\n');
	if (!p)
		return (NULL);
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	if (aux == NULL)
		return (NULL);
	while (*p != '\0')
	{
		aux[i] = *p;
		i++;
		p++;
	}
	aux[i] = '\0';
	free (stack);
	return (aux);
}
char	*join_and_free(char *stack, char *tmp)
{
	char *temp;

	temp = ft_strjoin(stack, tmp);
	free (stack);
	return (temp);
}
char	*get_next_line(int fd)
{
	static char	*stack;
	char		*tmp;
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stack)
	{
		stack = malloc (sizeof(char) * 1);
		if (stack == NULL)
			return (NULL);
	}
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (tmp == NULL)
		return (NULL);
	readbytes = 1;
	while (!ft_strchr(stack, '\n') && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (NULL);
		tmp[readbytes] = '\0';
		stack = join_and_free(stack, tmp);
	}
	free (tmp);
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}