/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/04/08 18:00:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

/**
 * Pipex tiene que crear un pipe y dos procesos hijos con fork, que el padre 
 * espere a que los dos hijos terminen su trabajo y devulve el exit_code del 
 * ultimo proceso en terminar
 */
int	ft_pipex(t_struct *st)
{
	int		exit_code;
	pid_t	child1;
	pid_t	child2;
	pid_t	res;
	int		status;

	exit_code = 0;
	pipe_gen(st);
	child1 = fork();
	if (child1 == -1)
		exit_pipex(st);
	if (child1 == 0)
	{
		usleep(500000);
		get_iofiles(st);
		dup2(st->fd_in, STDIN_FILENO);
		dup2(st->pipe[1], STDOUT_FILENO);
		close_pipe(st);
		find_path_index(st, st->cmd1[0]);
		execve(st->path_cmd, st->cmd1, st->env);
	}
	else if (child1 > 0)
	{
		child2 = fork();
		if (child2 == -1)
			exit_pipex(st);
		if (child2 == 0)
		{
			usleep(400000);
			get_iofiles(st);
			dup2(st->pipe[0], STDIN_FILENO);
			dup2(st->fd_out, STDOUT_FILENO);
			close_pipe(st);
			find_path_index(st, st->cmd2[0]);
			execve(st->path_cmd, st->cmd2, st->env);
		}
		else if (child2 > 0)
		{
			res = waitpid(child1, &status, 0);
			exit_code = WEXITSTATUS(status);
			res = waitpid(child2, &status, 0);
			exit_code = WEXITSTATUS(status);
		}
	}
	return (exit_code);
}

/**
 Un nuevo argumento para main -> @param env
	@param env = puntero a la variables de entorno del sistema
	almacena en un string cada línea de env
	//TODO en main -> inicializar la struct, comenzar pipex, retornar exit_code
	//! protecciones de los argumentos y gestión de errores (mejorar)
*/
int	main(int ac, char **av, char **env)
{
	t_struct	st;
	int			exit_code;

	if (ac != 5)
		return (printf("Error\n"), 1);
	if (!env || !*env)
		return (printf("Error\n"), 1);
	st = init_struct(ac, av, env);
	exit_code = ft_pipex(&st);
	return (exit_code);
}
