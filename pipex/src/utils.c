/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:57:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/22 20:35:10 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

void	ft_print_dstr(char **dstr)
{
	size_t	i;

	i = 0;
	while (dstr[i] != NULL)
	{
		printf("%s\n", dstr[i]);
		i++;
	}
}

void	close_fds(t_struct *st)
{
	if (st->fd_in != -1)
		close(st->fd_in);
	if (st->fd_out != -1)
		close(st->fd_out);
}

void	close_pipe(t_struct *st)
{
	close(st->pipe[0]);
	close(st->pipe[1]);
}

/**
 * Función para terminar el programa, comprueba si las variables de
 * la struct están inicializadas y si es así las libera
 * error = 2 -> command_not found
 */
void	exit_pipex(t_struct *st, int error)
{
	if (st)
	{
		close_fds(st);
		*st = set_st_empty();
		// if (st->pipe != NULL)
		// 	free(st->pipe);
		// if (st->paths != NULL)
		// 	ft_totalfree(st->paths);
		// if (st->cmd1 != NULL)
		// 	ft_totalfree(st->cmd1);
		// if (st->cmd2 != NULL)
		// 	ft_totalfree(st->cmd2);
		// if (st->path_cmd != NULL)
		// 	free(st->path_cmd);
	}
	if (error > 0)
		exit(EXIT_FAILURE);
}
