/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:57:29 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 09:18:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_env_withargs(char **args, t_data *d)
{
	int	i;

	if (ft_strdlen(args) == 2 && !ft_strcmp(args[1], "-"))
		return (0);
	i = 0;
	while (args[i] != NULL && !ft_strcmp(args[i], "env"))
		i++;
	if (args[i] != NULL)
	{
		if (args[i][0] == '-' && args[i][1])
			return (ft_printf_error("cascaribash: env: illegal option -- %c\n",
					args[i][1]), 1);
		else
		{
			ft_printf_error("cascaribash: env: %s: No such file or directory\n",
				args[1]);
			return (127);
		}
	}
	return (ft_print_dstr(d->env_dup), 0);
}

void	bi_env(char **args, t_data *d)
{
	if (ft_strdlen(args) > 1)
		d->exit_code = ft_env_withargs(args, d);
	else
	{
		ft_print_dstr(d->env_dup);
		d->exit_code = 0;
	}
}

void	ft_exit_mod(char **args, t_data *d)
{
	int	exit_stat;

	exit_stat = 0;
	if (ft_is_num(args[1]))
	{
		ft_printf_error("cascaribash: exit: %s: numeric argument required\n",
			args[1]);
		ft_clean_exit(d);
		exit(255);
	}
	if (!ft_is_num(args[1]) && ft_strdlen(args) == 2)
	{
		exit_stat = ft_atoi(args[1]);
		ft_printf("exit\n");
		ft_clean_exit(d);
		exit(exit_stat);
	}
	if (!ft_is_num(args[1]) && ft_strdlen(args) > 2)
	{
		d->exit_code = 1;
		ft_printf_error("exit\ncascaribash: exit: too many arguments\n");
		return ;
	}
}

void	bi_exit(char **args, t_data *d)
{
	if (ft_strdlen(args) > 1)
		ft_exit_mod(args, d);
	else
	{
		ft_clean_exit(d);
		ft_printf("exit\n");
		exit(0);
	}
}

void	bi_echo(t_data *d, char **args)
{
	int	i;
	int	nl;
	int	len;

	len = ft_strdlen(args);
	nl = 1;
	i = 0;
	while (++i < len && !ft_strcmp(args[i], "-n"))
		nl = 0;
	while (i < len)
	{
		ft_printf("%s", args[i]);
		if (i + 1 < len)
			ft_printf(" ", args[i]);
		i++;
	}
	if (nl == 1)
		ft_printf("\n");
	d->exit_code = 0;
}
