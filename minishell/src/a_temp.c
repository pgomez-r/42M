/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_temp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:56:07 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/17 20:19:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	bi_env(t_data *d)
{
	ft_print_dstr(d->env_dup);
}
/*Puedo pasar ft_print_dstr cuando build_exe encuentre "env"*/

int	ft_export_chars(char c, int mode)
{
	if (mode == 0)
	{
		if (c < 65 || (c > 90 && c < 95) || c == 96 || c > 122)
			return (1);
	}
	if (mode == 1)
	{
		
	}
	return (0);
}

int	ft_exp_argcheck(char *arg)
{
	int	i;

	i = 0;
	while (arg[++i] != '\0')
	{
		if (ft_export_chars(arg[0], 0))
			return (1);
	}
	return (0);
}

void	ft_export_print(t_data *d)
{
	int		i;

	d->env_exp = malloc(sizeof(char *) * ft_strdlen(d->env_dup) + 1);
	if (d->env_exp == NULL)
	{
		ft_printf_error("cascaribash: malloc error\n");
		return ;
	}
	i = -1;
	while (d->env_dup[++i] != NULL)
		d->env_exp[i] = ft_strdup(d->env_dup[i]);
	d->env_exp[i] = NULL;
	d->env_exp = ft_export_order(d->env_exp);
	i = -1;
	while (d->env_exp[++i] != NULL)
		printf("declare -x %s\n", d->env_exp[i]);
	ft_totalfree(d->env_exp);
	d->env_exp = NULL;
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

void	bi_export(t_data *d, t_command *cmd)
{
	int	i;

	if (ft_strdlen(cmd->cmd_tab) == 1)
		ft_export_print(d);
	else
	{
		i = 0;
		while (cmd->cmd_tab[++i] != NULL)
		{
			if (ft_exp_argcheck(cmd->cmd_tab[i]))
				continue ;
			ft_update_env(d, cmd->cmd_tab[i]);
		}
	}
}
/**
 * TODO: free env_exp en cada llamada a bi_export si no es null y en clean_input!
 */	

/*EXPORT RULES
Naming: The variable name must begin with a letter (a to z or A to Z) or an
underscore (_), followed by letters, digits (0 to 9), or underscores.
Special characters are not allowed along the whole line.
No spaces around the equals sign; VAR=value is correct, VAR = value is not
No command substitution: The value assigned to the variable should not be the
result of a command substitution.
No special shell characters: (; & | > >> < * ? () $ # {} [] ! \); unless they
are properly escaped or enclose in quotes.*/