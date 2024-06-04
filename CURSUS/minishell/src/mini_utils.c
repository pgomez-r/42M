/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 23:16:26 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/23 15:13:14 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_wait(pid_t pid, t_data *d, int mode)
{
	waitpid(pid, &d->pes, 0);
	if (WIFEXITED(d->pes))
		d->exit_code = WEXITSTATUS(d->pes);
	if (mode == 1)
	{
		if (d->exit_code != 0 && d->exit_code != 211)
			g_sign = 1;
		if (d->exit_code == 242 || d->exit_code == 211)
			d->exit_code = 0;
	}
	ft_signal();
}

void	ft_free_str(char *str)
{
	if (str != NULL)
		free(str);
	str = NULL;
}

char	*ft_str_rplc(char *src, char *new)
{
	char	*aux;

	aux = ft_strdup(new);
	free (src);
	return (aux);
}

int	ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_flag_check(t_data *d, char c, int mode)
{
	if (mode == 0)
	{
		d->q = c;
		d->q_flag = 1;
	}
	else
	{
		d->q = 0;
		d->q_flag = 0;
	}
}
