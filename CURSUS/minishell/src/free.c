/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 08:24:28 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/23 17:16:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_clean_input(t_input *input)
{
	if (input->cmd_n > 0)
	{
		ft_free_cmds(input);
		free(input->cmds);
	}
	if (input->n_elements > 0)
	{
		ft_free_arr(input, input->n_elements);
		free(input->elements);
	}
	input->cmd_n = 0;
	input->n_elements = 0;
	if (input->pipes != NULL)
		free(input->pipes);
	input->pipes = NULL;
	if (access(".heredoc", F_OK) == 0)
		unlink(".heredoc");
}

void	ft_free_data(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->env_size)
	{
		free(d->env_arr[i].full);
		free(d->env_arr[i].title);
		free(d->env_arr[i].line);
	}
	free(d->env_arr);
	ft_totalfree(d->env_dup);
	d->env_dup = NULL;
	ft_totalfree(d->env_exp);
	d->env_exp = NULL;
}

void	ft_free_cmds(t_input *in)
{
	int	i;
	int	j;

	i = -1;
	while (++i < in->cmd_n)
	{
		ft_free_str(in->cmds[i].path_cmd);
		ft_free_str(in->cmds[i].cmd_line);
		if (in->cmds[i].paths != NULL)
			ft_totalfree(in->cmds[i].paths);
		if (in->cmds[i].cmd_tab != NULL)
			ft_totalfree(in->cmds[i].cmd_tab);
		if (in->cmds[i].tokens != NULL)
		{
			j = -1;
			while (++j < in->cmds[i].size)
				ft_free_str(in->cmds[i].tokens[j].data);
			free(in->cmds[i].tokens);
		}
	}
}

void	ft_free_arr(t_input *in, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (in->elements[i].data != NULL)
		{
			ft_free_str(in->elements[i].data);
			in->elements[i].data = NULL;
		}
	}
}

void	ft_clean_exit(t_data *d)
{
	ft_clean_input(&d->in);
	if (d->rl_input != NULL)
		free(d->rl_input);
	ft_free_data(d);
}
