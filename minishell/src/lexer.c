/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:40:28 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/03/01 10:49:13 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_token_spchars(t_input *in)
{
	int		i;
	int		j;
	char	*set;

	set = "|;\\()\0";
	j = -1;
	while (set[++j] != '\0')
	{
		i = -1;
		while (++i < in->n_elements)
		{
			if (in->elements[i].type == '0'
				&& ft_strchr(in->elements[i].data, set[j]))
			{
				if (ft_strlen(in->elements[i].data) > 1)
					in->elements = ft_arr_update(in, i, set[j]);
				else
					in->elements[i].type = set[j];
			}
		}
	}
}

void	ft_token_and(t_input *in)
{
	int	i;
	int	and;

	i = -1;
	while (++i < in->n_elements)
	{
		and = ft_char_pos(in->elements[i].data, '&');
		if (in->elements[i].type == '0' && and >= 0)
		{
			if (in->elements[i].data[and] == in->elements[i].data[and + 1]
				&& in->elements[i].data[and] != in->elements[i].data[and + 2])
				in->elements = ft_db_redirs(in, i, in->elements[i].data[and]);
		}
	}
}

void	ft_token_files(t_input *in)
{
	int		i;
	char	ct;
	char	nt;

	i = -1;
	while (++i < in->n_elements && (i + 1 < in->n_elements))
	{
		ct = in->elements[i].type;
		nt = in->elements[i + 1].type;
		if (ct == '<' && (nt == '0' || nt == '\'' || nt == '\"'))
			in->elements[i + 1].type = 'i';
		else if (ct == 'h')
		{
			if (nt == '0' || nt == '\"')
				in->elements[i + 1].type = 'E';
			else if (nt == '\'')
				in->elements[i + 1].type = 'e';
		}
		else if (ct == '>' && (nt == '0' || nt == '\'' || nt == '\"'))
			in->elements[i + 1].type = 'o';
		else if (ct == 'a' && (nt == '0' || nt == '\'' || nt == '\"'))
			in->elements[i + 1].type = 'O';
	}
}

void	ft_token_redirs(t_input *in)
{
	int	i;
	int	red;

	i = -1;
	while (++i < in->n_elements)
	{
		red = ft_is_red(in->elements[i].data);
		if (in->elements[i].type == '0' && red >= 0)
		{
			if (in->elements[i].data[red] == in->elements[i].data[red + 1]
				&& in->elements[i].data[red] != in->elements[i].data[red + 2])
				in->elements = ft_db_redirs(in, i, in->elements[i].data[red]);
			else if (ft_strlen(in->elements[i].data) > 1)
				in->elements = ft_arr_update(in, i, in->elements[i].data[red]);
			else
				in->elements[i].type = in->elements[i].data[red];
		}
	}
}

int	ft_lexer(t_data *d)
{
	if (ft_manage_input(d))
		return (1);
	ft_token_spchars(&d->in);
	ft_token_and(&d->in);
	ft_token_redirs(&d->in);
	ft_token_files(&d->in);
	if (ft_syntax_check(&d->in))
		return (1);
	return (0);
}
