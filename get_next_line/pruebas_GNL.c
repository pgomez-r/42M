/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas_GNL.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:54:32 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/04 00:13:19 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr != (char)c)
	{
		if (*ptr == '\0')
			return (NULL);
		ptr++;
	}
	return (ptr);
}

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	//if (!stack || !*stack)
	//	return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
		i++;
	if (stack[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (stack[i] != '\n' && stack[i] != '\0')
	{
		line[i] = stack[i];
		i++;
	}
	if (stack[i] == '\n')
	{	
		line[i] = stack[i];
		i++;
	}
	line [i] = '\0';
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
	{
		free (stack);
		return (NULL);
	}
	p++;
	aux = malloc(sizeof(char) * (ft_strlen(p) + 1));
	if (!aux)
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
	char *aux;

	aux = ft_strjoin(stack, tmp);
	free (stack);
	return (aux);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*tmp;
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	// if (!stack)
	// {
	// 	stack = malloc (sizeof(char) * 1);
	// 	if (!stack)
	// 		return (NULL);
	// }
	tmp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	readbytes = 1;
	while (!(ft_strchr(stack, '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[readbytes] = '\0';
		stack = join_and_free(stack, tmp);
	}
	free (tmp);
	line = create_line(stack);
	stack = update_stack(stack);
	return (line);
}

void	ft_leaks(void)
{
	system("leaks -q gnl");
}

int	main(void)
{
	int		fd;
	char	*line;

	atexit(ft_leaks);
	fd = open("nl", O_RDONLY);
	line = get_next_line(fd);
	printf("Línea:%s\n", line);
	free (line);
	line = get_next_line(fd);
	printf("Línea:%s\n", line);

	// line = get_next_line(fd);
	// printf("Línea:%s\n", line);
	// free (line);
	// line = get_next_line(fd);
	// printf("Línea:%s\n", line);
	free (line);
	close (fd);
	return (0);
}
