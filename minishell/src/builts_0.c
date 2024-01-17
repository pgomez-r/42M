/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builts_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:29 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	bi_exit(t_data *d)
{
	ft_clean_exit(d);
	exit(0);
}

void	bi_echo(char **cmd_line)
{
	int	i;

	i = 0;
	while (cmd_line[++i] != NULL)
		ft_printf("%s ", cmd_line[i]);
	ft_printf("\n");
}

void	bi_env(t_data *d)
{
	int	i;

	i = 0;
	while (d->env_dup[i])
	{
		printf("%s\n", d->env_dup[i]);
		i++;
	}
}

void	bi_export(t_data *d)
{
	char	**temp;
	int		i;

	i = -1;
	temp = ft_export_order(d->env_dup);
	while (temp[++i])
		printf("%s\n", temp[i]);
}

char	**ft_export_order(char **env)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (env[i])
	{
		j = i + 1;
		while (env[j])
		{
			if (ft_strcmp(env[i], env[j]) > 0)
			{
				temp = env[i];
				env[i] = env[j];
				env[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (env);
}
