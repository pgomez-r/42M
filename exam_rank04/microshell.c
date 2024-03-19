/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 21:54:16 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/19 21:49:26 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

int	ft_err(char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
	return (1);
}

int	ft_cd(char **av, int i)
{
	if (i != 2)
		return (ft_err("error: cd: bad arguments"));
	else if (chdir(av[1]) == -1)
		return (ft_err("error: cd: cannot change directory to "), ft_err(av[1]));
	return (0);
}

int	ft_exe(char **av, char **env, int i)
{
	int	fd[2];
	int	stat;
	int	is_pipe;
	int	pid;

	is_pipe = 0;
	if (av[i] && !strcmp(av[i], "|"))
		is_pipe = 1;
	if (is_pipe && pipe(fd) == -1)
		return (ft_err("error: fatal"));
	pid = fork();
	if (pid < 0)
		return (ft_err("error: fatal"));
	else if (pid == 0)
	{
		av[i] = NULL;
		if (is_pipe && (dup2(fd[1], 1) == -1 || close(fd[0]) == -1
				|| close(fd[1]) == -1))
			return (ft_err("error: fatal"));
		execve(*av, av, env);
		return (ft_err("error: cannot execute "), ft_err(*av));
	}
	waitpid(pid, &stat, 0);
	if (is_pipe && (dup2(fd[0], 0) == -1 || close(fd[0]) == -1
			|| close(fd[1]) == -1))
		return (ft_err("error: fatal"));
	return (WIFEXITED(stat) && WEXITstat(stat));
}

int	main(int ac, char **av, char **env)
{
	int	i;
	int	stat;

	i = 0;
	stat = 0;
	if (ac > 1)
	{
		while (av[i] && av[++i])
		{
			av += i;
			i = 0;
			while (av[i] && strcmp(av[i], "|") && strcmp(av[i], ";"))
				i++;
			if (!strcmp(*av, "cd"))
				stat = ft_cd(av, i);
			else if (i)
				stat = ft_exe(av, env, i);
		}
	}
	return (stat);
}
