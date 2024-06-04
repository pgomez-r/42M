/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exp_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:19:07 by pgruz11           #+#    #+#             */
/*   Updated: 2024/03/01 12:55:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_isvar(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0' && arg[i] != '=')
	{
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
			return (1);
		i++;
	}
	if (arg[i] == '\0')
		return (1);
	return (0);
}

int	ft_val_id(char *arg, int mode)
{
	int	i;

	i = 0;
	if (arg[0] != '_' && !ft_isalpha(arg[0]))
	{
		if (mode == 0)
			ft_printf_error(
				"cascaribash: export: `%s': not a valid identifier\n", arg);
		return (1);
	}
	while (arg[++i] != '\0' && arg[i] != '=')
	{
		if (arg[i] != '_' && !ft_isalnum(arg[i]))
		{
			if (mode == 0)
				ft_printf_error(
					"cascaribash: export: `%s': not a valid identifier\n", arg);
			return (1);
		}
	}
	return (0);
}

void	ft_export_print(t_data *d)
{
	int		i;

	i = -1;
	while (d->env_exp[++i] != NULL)
		printf("declare -x %s\n", d->env_exp[i]);
	d->exit_code = 0;
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

char	*ft_export_varcopy(char *str)
{
	char	*aux;
	int		i;
	int		j;

	if (!ft_strchr(str, '='))
		aux = ft_strdup(str);
	else
	{
		aux = ft_malloc(sizeof(char) * (ft_strlen(str) + 3));
		i = -1;
		while (str[++i] != '=')
			aux[i] = str[i];
		aux[i] = str[i];
		j = i + 1;
		aux[j] = '\"';
		while (str[++i] != '\0')
			aux[++j] = str[i];
		aux[j + 1] = '\"';
		aux[j + 2] = '\0';
	}
	return (aux);
}
