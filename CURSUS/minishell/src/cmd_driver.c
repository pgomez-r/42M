/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_driver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:21:34 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 13:52:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_built_exe(t_command *cmd, t_data *d)
{
	if (ft_std_redir(cmd) > 0)
		return ;
	if (ft_strcmp(cmd->cmd_tab[0], "echo") == 0)
		bi_echo(d, cmd->cmd_tab);
	else if (ft_strcmp(cmd->cmd_tab[0], "cd") == 0)
		bi_cd(d, cmd);
	else if (ft_strcmp(cmd->cmd_tab[0], "pwd") == 0)
		bi_pwd(d);
	else if (ft_strcmp(cmd->cmd_tab[0], "export") == 0)
		bi_export(d, cmd);
	else if (ft_strcmp(cmd->cmd_tab[0], "unset") == 0)
		bi_unset(d, cmd);
	else if (ft_strcmp(cmd->cmd_tab[0], "env") == 0)
		bi_env(cmd->cmd_tab, d);
	else if (ft_strcmp(cmd->cmd_tab[0], "exit") == 0)
		bi_exit(cmd->cmd_tab, d);
}

void	ft_excve(t_command *cmd, t_data *d, int mode)
{
	signal(SIGINT, ft_cmd_sig);
	if (mode == 0)
	{
		get_paths(cmd, d->env_dup);
		find_path_index(cmd, cmd->cmd_tab[0]);
		if (execve(cmd->path_cmd, cmd->cmd_tab, d->env_dup) == -1)
			ft_excve_error(cmd);
	}
	ft_excve_dircheck(cmd->cmd_tab[0]);
	if (execve(cmd->cmd_tab[0], cmd->cmd_tab, d->env_dup) == -1)
		ft_excve_error(cmd);
}

void	ft_exegguttor(t_command *cmd, t_data *d)
{
	pid_t	pid;

	if (ft_std_redir(cmd) > 0)
		return ;
	signal(SIGINT, ft_cmd_sig);
	pid = fork();
	if (pid == -1)
		ft_printf_error("cascaribash: fork process failed");
	else if (pid > 0)
		ft_wait(pid, d, 0);
	else
	{
		if (!ft_strchr(cmd->cmd_tab[0], '/'))
			ft_excve(cmd, d, 0);
		else
			ft_excve(cmd, d, 11);
	}
}

void	ft_shell_pipex(t_data *d, int i)
{
	if (i != 0)
	{
		dup2(d->in.pipes[i - 1][0], 0);
		close(d->in.pipes[i - 1][0]);
	}
	if (i != d->in.cmd_n - 1)
	{
		dup2(d->in.pipes[i][1], 1);
		close(d->in.pipes[i][1]);
	}
}

int	ft_cmd_driver(t_data *d, t_command *cmds)
{
	int			curr_cmd;

	curr_cmd = -1;
	while (++curr_cmd < d->in.cmd_n)
	{
		g_sign = 0;
		ft_dollar_check(&cmds[curr_cmd], d);
		ft_quotes(&cmds[curr_cmd], d);
		ft_format_cmd(&cmds[curr_cmd], d);
		ft_std_shield(d, 0);
		ft_is_heredoc(&cmds[curr_cmd], d);
		if (!ft_check_empty(&cmds[curr_cmd]))
			continue ;
		ft_shell_pipex(d, curr_cmd);
		if (cmds[curr_cmd].built == 1)
			ft_built_exe(&cmds[curr_cmd], d);
		else
			ft_exegguttor(&cmds[curr_cmd], d);
		ft_std_shield(d, 1);
	}
	return (0);
}
