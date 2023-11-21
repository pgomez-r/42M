/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 22:00:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/11/21 22:04:53 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_exegguttor(char *cmd, char **env)
{
	t_command	st;

	get_paths(&st, env);
	split_cmd(&st, cmd);
	find_path_index(&st, st.cmd[0]);
	if (execve(st.path_cmd, st.cmd, env) == -1)
	{
		ft_printf_error("pipex: command not found: %s\n", st.cmd[0]);
		free_cache(&st, 127);
	}
}

/**
 * ft_pipex genera un pipe para que "comunique" el output del primer comando
 * al siguiente comando, que lo tomará como input
 * fork() genera procesos nuevos dentro del mismo programa
 * dup() intercambia file descriptors del sistema, nos permite hacer que el fd de
 * un archivo que hemos abierto pase a ser el fd 0 de standard input
 * el proceso generado ejecuta cada comando que entra por consola, usando excve()
 */
void	ft_pipex(char *cmd, char **env, int fd)
{
	pid_t	pid;
	int		pipe_end[2];

	pipe(pipe_end);
	pid = fork();
	if (pid == -1)
		perror("pipex: fork process failed");
	else if (pid > 0)
	{
		close(pipe_end[1]);
		dup2(pipe_end[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipe_end[0]);
		dup2(pipe_end[1], 1);
		if (fd == 0)
			exit(1);
		else
			ft_exegguttor(cmd, env);
	}
}

int	main(int ac, char **av, char **env)
{
	t_struct	d;

	d.cmd_n = 3;
	if (ac < 5)
		return (perror("Error: wrong number of arguments\n"), 1);
	if (!env || !*env)
		return (perror("pipex: env parse error"), 1);
	ft_openfiles(&d, av, ac - 1);
	dup2(d.fd_in, 0);
	dup2(d.fd_out, 1);
	ft_pipex(av[2], env, d.fd_in);
	while (d.cmd_n < ac - 2)
		ft_pipex(av[d.cmd_n++], env, 1);
	ft_exegguttor(av[ac - 2], env);
	return (0);
}
