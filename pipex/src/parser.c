/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:16:45 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/07 21:08:16 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
Vamos a sacar de @param env la línea PATH y guardar todas sus direcciones
en nuestra variable @param	paths
*/
void	get_paths(t_struct *st)
{
	size_t	i;
	char	*path_fix;

	i = 0;
	path_fix = NULL;
	while (st->env[i] && is_path(st->env[i]))
		i++;
	st->paths = ft_split(st->env[i], ':');
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
int	find_path_index(t_struct *st)
{
	int	i;

	if (!st->path_cmd)
		st->path_cmd = NULL;
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->path_cmd = ft_strjoin(st->paths[i], st->cmd);
		if (access(st->path_cmd, F_OK | X_OK) == 0)
			return (i);
		free(st->path_cmd);
		i++;
	}
	return (-1);
}

void	get_iofiles(t_struct *st)
{
	st->fd_in = open(st->av[1], O_RDONLY);
	if (st->fd_in == -1)
		exit_pipex(st);
	st->fd_out = open(st->av[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (st->fd_out == -1)
		exit_pipex(st);
}

int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}
