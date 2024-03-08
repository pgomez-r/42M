/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 04:19:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/29 09:08:08 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_check_empty(t_command *cmd)
{
	int		i;
	char	t;

	i = -1;
	while (++i < cmd->size)
	{
		t = cmd->tokens[i].type;
		if (t != 'h' && t != 'E' && t != 'e')
			return (1);
	}
	return (0);
}

void	ft_get_cmdline(t_command *cmd)
{
	int	i;

	cmd->cmd_line = ft_malloc(sizeof(char) * 1);
	cmd->cmd_line[0] = '\0';
	i = -1;
	while (++i < cmd->size)
	{
		if (cmd->tokens[i].type == '0' || cmd->tokens[i].type == '\''
			|| cmd->tokens[i].type == '\"')
		{
			if (cmd->cmd_line[0] != '\0')
				cmd->cmd_line = ft_addspace(cmd->cmd_line);
			cmd->cmd_line = ft_strjoint(cmd->cmd_line, cmd->tokens[i].data);
		}
	}
}

void	ft_init_cmd(t_input *in)
{
	int	i;
	int	j;
	int	start;
	int	curr;

	in->cmd_n = ft_element_cnt(in, '|') + 1;
	in->cmds = ft_malloc(sizeof(t_command) * in->cmd_n);
	i = 0;
	curr = 0;
	while (i < in->cmd_n)
	{
		start = curr;
		in->cmds[i].dataptr = in->dptr;
		ft_init_files(&in->cmds[i]);
		in->cmds[i].size = ft_cmd_size(in, &curr);
		curr++;
		in->cmds[i].tokens = ft_malloc(sizeof(t_element) * in->cmds[i].size);
		j = -1;
		while (++j < in->cmds[i].size)
		{
			in->cmds[i].tokens[j].data = ft_strdup(in->elements[start].data);
			in->cmds[i].tokens[j].type = in->elements[start++].type;
		}
		i++;
	}
}

void	ft_format_cmd(t_command *cmd, t_data *d)
{
	ft_get_cmdline(cmd);
	ft_split_cmd(cmd, d);
	if (ft_is_built(cmd->cmd_tab[0]))
		cmd->built = 1;
}

void	ft_cmd_maker(t_input *in)
{
	ft_init_cmd(in);
	ft_init_pipes(in);
}
