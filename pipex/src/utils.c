/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:57:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/08 17:06:28 by pgomez-r         ###   ########.fr       */
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
 * TODO función que cierre fds, libere ints, char y doble char y EXIT
 * ? imprimir en pantalla algún mensaje/código error ?
 */
void	exit_pipex(t_struct *st)
{
	if (st)
	{
		close_fds(st);
		if (st->pipe != NULL)
			free(st->pipe);
		if (st->pids != NULL)
			free(st->pids);
		if (st->path_cmd != NULL)
			ft_totalfree(st->cmd1);
		if (st->cmd_opt != NULL)
			ft_totalfree(st->cmd2);
	}
	exit(printf("Algo ha fallado maki =/"));
}
