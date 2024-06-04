/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 18:02:55 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 13:50:03 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_content_buffer(t_data *d)
{
	d->content = ft_strjoint(d->content, d->read);
	d->content = ft_strjoint(d->content, "\n");
	free(d->read);
}

void	ft_heredoc_init(t_data *d, t_command *cmd, int pos)
{
	d->content = NULL;
	d->read = NULL;
	d->eof = NULL;
	if (cmd->tokens[pos + 1].type == 'e' || cmd->tokens[pos + 1].type == 'E')
		d->eof = cmd->tokens[pos + 1].data;
}

void	ft_check_hdocfile(t_command *cmd)
{
	int		fd;
	ssize_t	check;
	char	buff[10];

	if (access(".heredoc", F_OK) < 0)
	{
		fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		ft_open_check(cmd, fd, ".heredoc");
		close(fd);
	}
	else
	{
		fd = open(".heredoc", O_RDONLY);
		check = read(fd, buff, 10);
		if (check < 0)
		{
			close(fd);
			unlink(".heredoc");
			fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		}
		close(fd);
	}
}

int	ft_expand_char(char c)
{
	if (c != '\0' && c != ' ' && c != '\n' && c != '$'
		&& c != '\'' && c != '\"')
		return (1);
	return (0);
}
