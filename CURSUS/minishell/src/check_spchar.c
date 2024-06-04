/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:29:29 by fclaus-g          #+#    #+#             */
/*   Updated: 2024/02/23 17:28:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_special_char(char c)
{
	if (c == '|' || c == '>' || c == '<')
		return (1);
	return (0);
}

void	ft_check_special_chars_right(t_data *d)
{
	int		c;
	char	*aux;

	c = -1;
	aux = NULL;
	while (d->rl_input[++c])
	{
		if (ft_is_special_char(d->rl_input[c])
			&& !ft_is_space(d->rl_input[c + 1]) && d->rl_input[c + 1] != '<'
			&& d->rl_input[c + 1] != '>' && d->rl_input[c + 1] != '\0')
		{
			if (!ft_in_quotes(d->rl_input, c))
			{
				aux = ft_insert_right_space(d->rl_input, c);
				if (aux)
				{
					free (d->rl_input);
					d->rl_input = aux;
				}
			}
		}
	}
}

char	*ft_insert_right_space(char *s, int pos)
{
	int		c;
	int		i;
	char	*aux;

	c = -1;
	aux = ft_calloc(sizeof(char), ft_strlen(s) + 2);
	while (++c <= pos)
		aux[c] = s[c];
	i = c;
	aux[i++] = ' ';
	while (s[c])
		aux[i++] = s[c++];
	aux[i] = '\0';
	return (aux);
}

void	ft_check_special_chars_left(t_data *d)
{
	int		c;
	char	*aux;

	c = 0;
	aux = NULL;
	while (d->rl_input[c])
	{
		if (ft_is_special_char(d->rl_input[c])
			&& !ft_is_space(d->rl_input[c - 1]) && d->rl_input[c - 1] != '<'
			&& d->rl_input[c - 1] != '>' && c >= 0)
		{
			if (!ft_in_quotes(d->rl_input, c))
			{
				aux = ft_insert_left_space(d->rl_input, c);
				if (aux)
				{
					free (d->rl_input);
					d->rl_input = aux;
				}
			}
		}
		c++;
	}
}

char	*ft_insert_left_space(char *s, int pos)
{
	int		c;
	int		i;
	char	*aux;

	c = -1;
	aux = ft_calloc(sizeof(char), ft_strlen(s) + 2);
	while (s[++c])
	{
		if (c < pos)
			aux[c] = s[c];
		else if (c == pos)
		{
			aux[c] = ' ';
			aux[c + 1] = s[c];
			i = c + 1;
		}
		else
			aux[++i] = s[c];
	}
	aux[++i] = '\0';
	return (aux);
}
