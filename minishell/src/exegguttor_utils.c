/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exegguttor_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:21:48 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/29 08:44:51 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_paths(t_command *st, char **env)
{
	size_t	i;
	char	*path_fix;

	i = 0;
	path_fix = NULL;
	while (env[i] && is_path(env[i]))
		i++;
	if ((int)i == st->dataptr->env_size)
	{
		ft_printf_error("cascaribash: %s: No such file or directory\n",
			st->cmd_tab[0]);
		exit(127);
	}
	st->paths = ft_split(env[i], ':');
	path_fix = ft_strcpy(path_fix, st->paths[0] + 5);
	free(st->paths[0]);
	st->paths[0] = ft_strcpy(st->paths[0], path_fix);
	free(path_fix);
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->paths[i] = (ft_strjoint(st->paths[i], "/"));
		i++;
	}
}

int	find_path_index(t_command *st, char *cmd)
{
	int	i;

	if (!st->path_cmd)
	{
		st->path_cmd = ft_malloc(sizeof(char) * 1);
		st->path_cmd = NULL;
	}
	i = 0;
	while (st->paths[i] != NULL)
	{
		st->path_cmd = ft_strjoin(st->paths[i], cmd);
		if (access(st->path_cmd, F_OK | X_OK) == 0)
			return (0);
		if (st->path_cmd != NULL)
			free(st->path_cmd);
		i++;
	}
	return (-1);
}

void	ft_split_cmd(t_command *st, t_data *d)
{
	int	i;
	int	len;

	(void)d;
	i = -1;
	len = 1;
	while (++i < st->size)
	{
		if (st->tokens[i].type == '0' || st->tokens[i].type == '\''
			|| st->tokens[i].type == '\"')
			len++;
	}
	st->cmd_tab = ft_malloc(sizeof(char *) * len);
	i = -1;
	len = 0;
	while (++i < st->size)
	{
		if (st->tokens[i].type == '0' || st->tokens[i].type == '\''
			|| st->tokens[i].type == '\"')
			st->cmd_tab[len++] = ft_strdup(st->tokens[i].data);
	}
	st->cmd_tab[len] = NULL;
	if (!st->cmd_tab)
		perror ("cascaribash: parse error");
}

void	ft_excve_error(t_command *cmd)
{
	ft_printf_error("cascaribash: %s: command not found\n", cmd->cmd_tab[0]);
	if (cmd)
	{
		if (cmd->paths != NULL)
			ft_totalfree(cmd->paths);
		if (cmd->cmd_tab != NULL)
			ft_totalfree(cmd->cmd_tab);
	}
	exit(127);
}

int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}
