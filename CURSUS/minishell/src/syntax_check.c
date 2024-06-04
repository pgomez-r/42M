/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 06:35:26 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 10:49:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_spcset_check(t_input *in)
{
	int		i;
	int		j;
	char	*set;
	char	*msg;

	msg = "cascaribash: syntax error, not supported token";
	set = ";\\&()\0";
	i = -1;
	while (set[++i] != '\0')
	{
		j = -1;
		while (++j < in->n_elements)
		{
			if (in->elements[j].type == set[i])
			{
				in->dptr->exit_code = 258;
				ft_printf_error("%s `%c'\n", msg, set[i]);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_stdset_check(t_input *in)
{
	int		i;
	int		j;
	char	*set;

	set = "|<>ha\0";
	i = -1;
	while (set[++i] != '\0')
	{
		j = -1;
		while (++j < in->n_elements)
		{
			if (in->elements[j].type == set[i]
				&& in->elements[j + 1].type == set[i])
				return (ft_syntax_error(in, j), 1);
			if (in->elements[j].type == set[i] && (j + 1) >= in->n_elements)
				return (ft_syntax_error(in, j), 1);
			if (in->elements[j].type == set[i] && in->elements[j].type != '|'
				&& ft_strchr(set, in->elements[j + 1].type) != NULL)
				return (ft_syntax_error(in, j), 1);
		}
	}
	return (0);
}

int	ft_syntax_check(t_input *in)
{
	if (ft_stdset_check(in))
		return (1);
	if (ft_spcset_check(in))
		return (1);
	if (ft_eof_check(in))
		return (1);
	return (0);
}
