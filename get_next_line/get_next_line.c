/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:54:32 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/11/30 21:39:11 by pgomez-r         ###   ########.fr       */
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
char	*ft_free_and_join(char *stack, char *tmp)
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
		stack = ft_free_and_join(stack, tmp);
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
