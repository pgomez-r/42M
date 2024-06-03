/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:25:40 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/12/08 12:11:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/*La parte obligatoria del proyecto ya utiliza una sola variable estática, así
que para el bonus solo necesitamos que la función pueda trabajar con diferentes
fd, así que vasmos a convertir nuestra estática en un array de dos dimensiones,
es decir, la estática va a ser una "cadena de cadenas" (static char *stack[])
y le asignamos el valor máximo de fd posibles en el sistema, para que cada vez
que reciba un fd con valor X, cree una cadena estática en [X] y así, si en main
llamamos a GNL con diferentes fd, cada cadena estática será independiente
y la función podrá seguir devolviendo lineas en orden de cada archivo sin que 
haya conflictos entre si*/

char	*create_line(char *stack)
{
	char	*line;
	int		i;

	if (!stack || !*stack)
		return (NULL);
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
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*update_stack(char *stack)
{
	char	*aux;
	char	*p;
	int		i;

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
	i = 0;
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
	char	*aux;

	if (!stack)
	{
		stack = malloc(1);
		stack[0] = 0;
	}
	if (!stack)
		return (NULL);
	aux = ft_strjoin(stack, tmp);
	free (stack);
	return (aux);
}

/*En get_next_line_bonus.h hemos definido FD_MAX 4096, así que declaramos
la éstatica como *stack[FD_MAX], luego es importante que cada vez que 
"usemos" la estática en el resto de la función, nos refiramos a ella como
stack[fd], porque vamos a estar trabajando siempre con la cadena dentro de
stack que corresponda al fd que le haya mandado main*/

char	*get_next_line(int fd)
{
	static char	*stack[FD_MAX] = {NULL};
	char		tmp[BUFFER_SIZE + 1];
	char		*line;
	ssize_t		readbytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	readbytes = 1;
	while (!(ft_strchr(stack[fd], '\n')) && readbytes > 0)
	{
		readbytes = read(fd, tmp, BUFFER_SIZE);
		if (readbytes < 0)
			return (free(stack[fd]), stack[fd] = NULL, NULL);
		tmp[readbytes] = '\0';
		stack[fd] = join_and_free(stack[fd], tmp);
		if (!stack[fd])
			return (NULL);
	}
	line = create_line(stack[fd]);
	stack[fd] = update_stack(stack[fd]);
	return (line);
}
