/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 23:18:10 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 10:00:26 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_dir_back(t_data *d, char *arg)
{
	char	*aux;
	int		i;
	int		len;

	i = (int)ft_strlen(arg) - 1;
	while (arg[i] != '/' && i > 0)
		i--;
	if (i == 0)
	{
		if (chdir("/\0") != 0)
			ft_error(d, 1, "cascaribash: cd error");
		return (0);
	}
	aux = ft_malloc(sizeof(char) * (i + 1));
	if (!aux)
		return (ft_error(d, 1, "cacaribash: ft_ft_malloc error"), 1);
	len = i;
	aux[i] = '\0';
	i = -1;
	while (++i < len)
		aux[i] = arg[i];
	if (chdir(aux) != 0)
		ft_error(d, 1, "cascaribash: cd error");
	free (aux);
	return (0);
}

void	ft_dir_home(t_data *d)
{
	char	*dir;

	dir = ft_getenv(d, "HOME");
	if (dir == NULL)
		ft_error(d, 1, "cascaribash: cd: HOME not set");
	else if (chdir(dir) != 0)
		ft_error(d, 1, "cascaribash: cd error");
	else
		d->exit_code = 0;
}

void	bi_cd(t_data *d, t_command *cmd)
{
	char	curr_dir[PATH_MAX];

	getcwd(curr_dir, PATH_MAX);
	if (ft_strdlen(cmd->cmd_tab) == 1 || !ft_strcmp("~", cmd->cmd_tab[1]))
		ft_dir_home(d);
	else if (!ft_strcmp(".", cmd->cmd_tab[1])
		|| !ft_strcmp("./", cmd->cmd_tab[1]))
	{
		d->exit_code = 0;
		return ;
	}
	else if (!ft_strcmp("..", cmd->cmd_tab[1])
		|| !ft_strcmp("../", cmd->cmd_tab[1]))
		ft_dir_back(d, curr_dir);
	else
	{
		if (ft_is_dir(d, cmd->cmd_tab[1]) != 0)
			return ;
		else if (chdir(cmd->cmd_tab[1]) != 0)
			ft_error(d, 1, "cascaribash: cd error");
		else
			d->exit_code = 0;
	}
	ft_update_pwd(d, curr_dir);
}

void	ft_update_pwd(t_data *d, char *old_pwd)
{
	char	curr_pwd[PATH_MAX];

	getcwd(curr_pwd, PATH_MAX);
	if (!ft_strcmp(old_pwd, curr_pwd))
		return ;
	if (!ft_cd_protect(d, "OLDPWD"))
		ft_overwrite_var(d, "OLDPWD", old_pwd);
	if (!ft_cd_protect(d, "PWD"))
		ft_overwrite_var(d, "PWD", curr_pwd);
	ft_get_envarray(d);
}

void	bi_pwd(t_data *d)
{
	char	*pwd;

	pwd = ft_calloc(PATH_MAX, sizeof(char));
	if (getcwd(pwd, PATH_MAX) == NULL)
		ft_error(d, 1, "cascaribash: pwd error");
	ft_printf("%s\n", pwd);
	ft_free_str(pwd);
}
