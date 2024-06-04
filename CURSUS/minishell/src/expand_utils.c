/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 11:17:25 by pgruz11           #+#    #+#             */
/*   Updated: 2024/03/01 13:07:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_expand_init(char *content, t_data *d, int i)
{
	d->var = NULL;
	d->val = NULL;
	d->exp_flag = 0;
	if (content[i + 1])
	{
		d->var = ft_get_dollar_word(content, i + 1);
		d->val = ft_search_value(d->var, d->env_arr, d->env_size);
	}
}

char	*ft_get_dollar_word(char *str, int start)
{
	char	*aux;
	int		c;

	c = start;
	while (str[c] && str[c] != '$' && !ft_is_space(str[c])
		&& !ft_is_quote(str[c]))
		c++;
	aux = ft_substr(str, start, c - start);
	return (aux);
}

char	*ft_search_value(char *comp, t_env *env, int lenv)
{
	int		i;
	char	*aux;

	i = -1;
	while (++i < lenv)
	{
		if (!ft_strcmp(comp, env[i].title))
		{
			aux = ft_strdup(env[i].line);
			return (aux);
		}
	}
	return (NULL);
}

char	*ft_var_del(char *s)
{
	char	*aux;
	int		i;
	int		len;

	i = 0;
	while (s[i] != '$')
		i++;
	len = 1;
	while (ft_expand_char(s[++i]))
		len++;
	aux = ft_malloc(sizeof(char) * (ft_strlen(s) - len + 1));
	i = -1;
	len = -1;
	while (s[++i] != '$')
		aux[++len] = s[i];
	i++;
	while (ft_expand_char(s[i]))
		i++;
	while (s[i] != '\0')
		aux[++len] = s[i++];
	aux[++len] = '\0';
	free (s);
	return (aux);
}

void	ft_quotes(t_command *cmd, t_data *d)
{
	int	i;

	i = -1;
	while (++i < cmd->size)
		cmd->tokens[i].data = ft_clean_quotes(&cmd->tokens[i], d);
}
