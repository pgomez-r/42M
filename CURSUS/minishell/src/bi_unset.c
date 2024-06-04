/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:00:53 by pgruz11           #+#    #+#             */
/*   Updated: 2024/02/29 14:55:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**ft_delete_var(char **str_tab, int pos)
{
	char	**aux;
	int		i;
	int		j;

	aux = ft_malloc(sizeof(char *) * ft_strdlen(str_tab));
	i = 0;
	j = 0;
	while (str_tab[i] != NULL)
	{
		if (i != pos)
		{
			aux[j] = ft_strdup(str_tab[i]);
			j++;
		}
		i++;
	}
	aux[j] = NULL;
	ft_totalfree(str_tab);
	return (aux);
}

void	ft_unset_env(t_data *d, char *arg)
{
	int	i;

	i = -1;
	while (++i < d->env_size)
	{
		if (!ft_strcmp(d->env_arr[i].title, arg))
		{
			d->env_dup = ft_delete_var(d->env_dup, i);
			return ;
		}
	}
}

void	ft_unset_exp(t_data *d, char *arg)
{
	int		i;
	size_t	len;

	len = ft_strlen(arg);
	i = -1;
	while (d->env_exp[++i] != NULL)
	{
		if ((!ft_strncmp(d->env_exp[i], arg, len))
			&& (d->env_exp[i][len] == '=' || d->env_exp[i][len] == '\0'))
		{
			d->env_exp = ft_delete_var(d->env_exp, i);
			return ;
		}
	}
}

void	bi_unset(t_data *d, t_command *cmd)
{
	int	i;

	i = 0;
	while (cmd->cmd_tab[++i] != NULL)
	{
		if (ft_val_id(cmd->cmd_tab[i], 1))
		{
			ft_printf_error("cascaribash: unset: `%s': not valid identifier\n",
				cmd->cmd_tab[i]);
			d->exit_code = 1;
			continue ;
		}
		ft_unset_env(d, cmd->cmd_tab[i]);
		ft_unset_exp(d, cmd->cmd_tab[i]);
		ft_get_envarray(d);
		d->exit_code = 0;
	}
}
