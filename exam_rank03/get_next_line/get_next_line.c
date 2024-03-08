/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:41:14 by pgruz11           #+#    #+#             */
/*   Updated: 2024/03/08 11:42:40 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_nl(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	ft_strfree(char *s)
{
	if (s != NULL)
	{
		free(s);
		s = NULL;
	}
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
	{
		s1 = malloc(1);
		s1[0] = 0;
	}
	if (!s2)
		return (s1);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[i])
		new[j++] = s1[i++];
	i = 0;
	while (s2[i])
		new[j++] = s2[i++];
	new[j] = '\0';
	ft_sfree(s1);
	return (new);
}

char	*ft_line(char *s)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (s);
	line = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
		line[j] = s[j++];
	line[j];
	return (line);
}

char	*ft_stack(char *s)
{
	int		i;
	int		j;
	char	*stack;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (ft_sfree(s), NULL);
	stack = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	j = 0;
	while (s[i])
		stack[j++] = s[i++];
	stack[j];
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		buff[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		cnt;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	cnt = 1;
	while (cnt > 0 && !ft_nl(stack))
	{
		cnt = read(fd, buff, BUFFER_SIZE);
		if (cnt > 0)
		{
			buff[cnt] = '\0';
			stack = ft_join(stack, buff);
		}
	}
	if (stack)
	{
		line = ft_line(stack);
		stack = ft_stack(stack);
	}
	return (line);
}
