/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 17:12:51 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/01/14 18:17:48 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_red(char	*s)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] == '<' || s[i] == '>')
			return (i);
	}
	return (-1);
}

int	ft_eof_check(t_input *in)
{
	int	i;
	int	hd;
	int	eof;

	hd = 0;
	eof = 0;
	i = -1;
	while (++i < in->n_elements)
	{
		if (in->elements[i].type == 'h')
			hd++;
		if (in->elements[i].type == 'e' || in->elements[i].type == 'E')
			eof++;
	}
	if (hd != eof)
		return (ft_syntax_error(in, i), 1);
	return (0);
}

void	ft_syntax_error(t_input *in, int i)
{
	char	*msg;

	msg = "cascaribash: syntax error near unexpected token ";
	if (i + 1 < in->n_elements)
		ft_printf_error("%s`%s'\n", msg, in->elements[i + 1].data);
	else
		ft_printf_error("%s`newline'\n", msg);
}
