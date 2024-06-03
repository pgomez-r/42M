/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:16:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/21 20:29:00 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
Vamos a sacar de @param env la línea PATH y guardar todas sus direcciones
en nuestra variable @param	paths
*/
void	get_paths(t_command *st, char **env)
{
	size_t	i;
	char	*path_fix;

	i = 0;
	path_fix = NULL;
	while (env[i] && is_path(env[i]))
		i++;
	st->paths = ft_split(env[i], ':');
	path_fix = ft_strcpy(path_fix, st->paths[0] + 5);
	free(st->paths[0]);
	st->paths[0] = ft_strcpy(st->paths[0], path_fix);
	free(path_fix);
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->paths[i] = (join_and_free(st->paths[i], "/"));
		i++;
	}
}

/*Ya tenemos los paths de env en una variable, esta función tiene que
encontrar el MATCH entre el comando a ejecutar y su correspondiente path*/
int	find_path_index(t_command *st, char *cmd)
{
	int	i;

	if (!st->path_cmd)
	{
		st->path_cmd = malloc(sizeof(char) * 1);
		st->path_cmd = NULL;
	}
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->path_cmd = ft_strjoin(st->paths[i], cmd);
		if (access(st->path_cmd, F_OK | X_OK) == 0)
			return (0);
		if (st->path_cmd != NULL)
			free(st->path_cmd);
		i++;
	}
	return (-1);
}

/**
 * Función para guardar cmd1 y cmd2 -que entra a pipex por av[2] y av[3]-
 * el comando y sus opciones, ej -> cmd1= "ls -la" tenemos que quedarnos con
 * ls como cmd1[0] -la como cmd1[1], ya que execve necesita que el comando entre
 * como una matriz de cadenas *av[]
 */
void	split_cmd(t_command *st, char *cmdstr)
{
	st->cmd = ft_split(cmdstr, ' ');
	if (!st->cmd)
		perror ("pipex: parse error");
}

/**
 * keep it cutre =) 
 */
int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}
