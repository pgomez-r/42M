/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 09:35:55 by pgruz11           #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_open_check(int fd, char *file_path)
{
	if (fd == -1)
	{
		ft_printf("carcaribash: %s: %s\n", strerror(errno), file_path);
		exit(EXIT_FAILURE);
	}
}

void	ft_open_file(t_command *cmd, char *file, int type)
{
	if (type == 0)
	{
		if (cmd->fd_in != -1)
			close(cmd->fd_in);
		cmd->fd_in = open(file, O_RDONLY);
		ft_open_check(cmd->fd_in, file);
	}
	if (type == 1)
	{
		if (cmd->fd_out != -1)
			close(cmd->fd_out);
		cmd->fd_out = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		ft_open_check(cmd->fd_out, file);
	}
	if (type == 2)
	{
		if (cmd->fd_out != -1)
			close(cmd->fd_out);
		cmd->fd_out = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		ft_open_check(cmd->fd_out, file);
	}
}

void	ft_file_fds(t_command *cmd)
{
	int		i;

	if (access(".heredoc", F_OK) == 0)
		ft_open_file(cmd, ".heredoc", 0);
	i = -1;
	while (++i < cmd->size)
	{
		if (cmd->tokens[i].type == 'i')
			ft_open_file(cmd, cmd->tokens[i].data, 0);
		else if (cmd->tokens[i].type == 'o')
			ft_open_file(cmd, cmd->tokens[i].data, 1);
		else if (cmd->tokens[i].type == 'O')
			ft_open_file(cmd, cmd->tokens[i].data, 2);
	}
}

void	ft_std_redir(t_command *cmd)
{
	ft_file_fds(cmd);
	if (cmd->fd_in != -1)
	{
		dup2(cmd->fd_in, 0);
		close(cmd->fd_in);
	}
	if (cmd->fd_out != -1)
	{
		dup2(cmd->fd_out, 1);
		close(cmd->fd_out);
	}
}

void	ft_std_shield(t_data *d, int mode)
{
	if (mode == 0)
	{
		d->og_stdin = dup(0);
		d->og_stdout = dup(1);
	}
	else
	{
		dup2(d->og_stdin, 0);
		dup2(d->og_stdout, 1);
		close(d->og_stdin);
		close(d->og_stdout);
	}
}
