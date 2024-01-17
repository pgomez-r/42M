/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 04:19:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_get_cmdline(t_input *in, t_command *cmds)
{
	int	i;
	int	j;

	i = -1;
	while (++i < in->cmd_n)
	{
		cmds[i].cmd_line = malloc(sizeof(char) * 1);
		cmds[i].cmd_line[0] = '\0';
		j = -1;
		while (++j < cmds[i].size)
		{
			if (cmds[i].tokens[j].type == '0')
			{
				if (cmds[i].cmd_line[0] != '\0')
					cmds[i].cmd_line = ft_addspace(cmds[i].cmd_line);
				cmds[i].cmd_line
					= ft_strjoint(cmds[i].cmd_line, cmds[i].tokens[j].data);
			}
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
	in->cmds = malloc(sizeof(t_command) * in->cmd_n);
	i = 0;
	curr = 0;
	while (i < in->cmd_n)
	{
		start = curr;
		in->cmds[i].paths = NULL;
		in->cmds[i].path_cmd = NULL;
		in->cmds[i].cmd_tab = NULL;
		in->cmds[i].cmd_line = NULL;
		in->cmds[i].size = ft_cmd_size(in, &curr);
		curr++;
		in->cmds[i].tokens = malloc(sizeof(t_element) * in->cmds[i].size);
		j = -1;
		while (++j < in->cmds[i].size)
			in->cmds[i].tokens[j] = in->elements[start++];
		i++;
	}
}

void	ft_cmd_maker(t_input *in)
{
	int	i;

	ft_init_cmd(in);
	ft_init_pipes(in);
	i = -1;
	while (++i < in->cmd_n)
		ft_init_files(&in->cmds[i]);
	ft_get_cmdline(in, in->cmds);
	i = -1;
	while (++i < in->cmd_n)
		split_cmd(&in->cmds[i], in->cmds[i].cmd_line);
	ft_tag_builts(in->cmds, in->cmd_n);
}

/*Estoy planteando el movimiento de fds-archivos antes de exegguttor,
pero creo que tendría que cambiarlo y meterlo dentro, justo antes de
ejecutar cada comando, para modificar los archivos encadenados si es
necesario*/