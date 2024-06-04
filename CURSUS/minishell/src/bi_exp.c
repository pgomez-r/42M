/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 23:43:59 by pgruz11           #+#    #+#             */
/*   Updated: 2024/02/28 15:09:28 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_var_replace(t_data *d, char *var)
{
	int		i;
	size_t	len;

	i = -1;
	while (++i < d->env_size)
	{
		len = ft_strlen(d->env_arr[i].title);
		if (!ft_strncmp(d->env_arr[i].title, var, len)
			&& (var[len] == '=' || var[len] == '\0'))
		{
			ft_overwrite_var(d, d->env_arr[i].title, var + (len + 1));
			ft_get_envarray(d);
			return (0);
		}
	}
	return (1);
}

char	**ft_env_update(t_data *d, char *var)
{
	char	**aux;
	int		i;

	aux = ft_malloc(sizeof(char *) * (ft_strdlen(d->env_dup) + 2));
	i = -1;
	while (++i < (int)ft_strdlen(d->env_dup))
		aux[i] = ft_strdup(d->env_dup[i]);
	aux[i] = ft_strdup(var);
	aux[i + 1] = NULL;
	ft_totalfree(d->env_dup);
	return (aux);
}

char	**ft_exp_update(t_data *d, char *var)
{
	char	**aux;
	int		i;

	aux = ft_malloc(sizeof(char *) * (ft_strdlen(d->env_exp) + 2));
	i = -1;
	while (++i < (int)ft_strdlen(d->env_exp))
		aux[i] = ft_strdup(d->env_exp[i]);
	aux[i] = ft_export_varcopy(var);
	aux[i + 1] = NULL;
	ft_totalfree(d->env_exp);
	return (aux);
}

void	bi_export(t_data *d, t_command *cmd)
{
	int	i;

	if (ft_strdlen(cmd->cmd_tab) == 1)
		ft_export_print(d);
	i = 0;
	while (cmd->cmd_tab[++i] != NULL)
	{
		if (ft_val_id(cmd->cmd_tab[i], 0))
		{
			d->exit_code = 1;
			continue ;
		}
		if (!ft_isvar(cmd->cmd_tab[i]))
		{
			if (!ft_var_replace(d, cmd->cmd_tab[i]))
				continue ;
			d->env_dup = ft_env_update(d, cmd->cmd_tab[i]);
			ft_get_envarray(d);
			d->env_exp = ft_exp_update(d, cmd->cmd_tab[i]);
		}
		else
			d->env_exp = ft_exp_update(d, cmd->cmd_tab[i]);
		ft_export_order(d->env_exp);
		d->exit_code = 0;
	}
}
