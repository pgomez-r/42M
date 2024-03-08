/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:29:12 by pgruz11           #+#    #+#             */
/*   Updated: 2024/02/23 17:11:33 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_write_doc(t_command *cmd, char *content)
{
	int		fd;
	ssize_t	check;

	check = 0;
	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_open_check(cmd, fd, ".heredoc");
	check = write(fd, content, ft_strlen(content));
	if (check == -1)
	{
		cmd->dataptr->exit_code = 1;
		ft_printf_error("cascaribash: %s: %s\n", ".heredoc", strerror(errno));
	}
	close(fd);
}

void	ft_heredoc(t_command *cmd, int pos, t_data *d, int *exit)
{
	ft_heredoc_init(d, cmd, pos);
	d->read = readline("> ");
	if (d->read == NULL)
		(*exit) = 242;
	if ((*exit) != 242 && ft_strcmp(d->read, d->eof))
	{
		while ((*exit) != 211 && ft_strcmp(d->read, d->eof))
		{
			ft_content_buffer(d);
			d->read = readline("> ");
			if (d->read == NULL && d->content != NULL)
				(*exit) = 211;
		}
		d->content = ft_expand(d->content, d);
		ft_write_doc(cmd, d->content);
		if (d->content != NULL)
			free(d->content);
	}
	if (d->read != NULL)
		free(d->read);
}

int	ft_heredoc_loop(t_command *cmd, t_data *d)
{
	int	i;
	int	hd_exit;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < cmd->size)
	{
		hd_exit = 0;
		if (cmd->tokens[i].type == 'h')
		{
			ret = 1;
			signal(SIGINT, SIG_IGN);
			d->pid = fork();
			if (d->pid > 0)
				ft_wait(d->pid, d, 1);
			else
			{
				signal(SIGINT, ft_here_sig);
				ft_heredoc(cmd, i, d, &hd_exit);
				exit (hd_exit);
			}
		}
	}
	return (ret);
}

void	ft_is_heredoc(t_command *cmd, t_data *d)
{
	if (access(".heredoc", F_OK) == 0)
	{
		unlink(".heredoc");
		g_sign = 0;
	}
	if (ft_heredoc_loop(cmd, d))
		ft_check_hdocfile(cmd);
}
