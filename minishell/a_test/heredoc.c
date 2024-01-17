/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:29:12 by pgruz11           #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_is_heredoc(t_command *cmd)
{
	int	i;

	if (access(".heredoc", F_OK) == 0)
		remove(".heredoc");
	i = -1;
	while (++i < cmd->size)
	{
		if (cmd->tokens[i].type == 'h')
			ft_heredoc(cmd, i);
	}
}

void	ft_write_doc(char *content)
{
	int		fd;
	ssize_t	check;

	fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_open_check(fd, ".heredoc");
	check = write(fd, content, ft_strlen(content));
	if (check == -1)
		ft_printf("carcaribash: %s: %s\n", strerror(errno), ".heredoc");
	close(fd);
}
/**
 * TODO: permisos para .heredoc al crearlo? 
 */

void	ft_heredoc(t_command *cmd, int pos)
{
	char	*content;
	char	*read;
	char	*eof;

	content = NULL;
	read = NULL;
	eof = NULL;
	if (cmd->tokens[pos + 1].type == 'e' || cmd->tokens[pos + 1].type == 'E')
		eof = cmd->tokens[pos + 1].data;
	read = readline("> ");
	while (ft_strcmp(read, eof))
	{
		content = ft_strjoint(content, read);
		content = ft_strjoin(content, "\n");
		free(read);
		read = readline("> ");
	}
	if (read != NULL)
		free(read);
	ft_write_doc(content);
	free(content);
}
