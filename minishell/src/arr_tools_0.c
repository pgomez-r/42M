/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:59:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/28 15:09:22 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_element	*ft_arr_update(t_input *in, int i, char c)
{
	char		**new_text;
	t_element	*new_arr;
	int			new_size;
	int			size;

	size = in->n_elements;
	new_text = ft_element_split(in->elements[i].data, c);
	new_size = in->n_elements + (int)ft_strdlen(new_text) - 1;
	new_arr = ft_malloc(sizeof(t_element) * new_size);
	in->n_elements = new_size;
	ft_fill_arr(in, new_arr, i, new_text);
	ft_tag_type(new_arr, i, (int)ft_strdlen(new_text), c);
	ft_totalfree(new_text);
	ft_free_arr(in, size);
	free(in->elements);
	return (new_arr);
}

char	**ft_element_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = ft_malloc(sizeof(char *) * (ft_count_elements(str, c) + 1));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i > j)
			tab[k++] = ft_savewords(str + j, i - j);
		if (str[i] == c)
		{
			tab[k++] = ft_write_token(c);
			i++;
		}
	}
	tab[k] = NULL;
	return (tab);
}

void	ft_fill_arr(t_input *in, t_element *new_arr, int tar, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < in->n_elements)
	{
		if (i == tar)
		{
			k++;
			j = -1;
			while (tab[++j] != NULL)
			{
				new_arr[i].data = ft_strdup(tab[j]);
				new_arr[i++].type = '0';
			}
		}
		else
		{
			new_arr[i].data = ft_strdup(in->elements[k].data);
			new_arr[i++].type = in->elements[k++].type;
		}
	}
}

t_element	*ft_db_redirs(t_input *in, int i, char c)
{
	char		**new_text;
	t_element	*new_arr;
	int			new_size;
	int			size;

	size = in->n_elements;
	new_text = ft_dbredir_split(in->elements[i].data, c);
	new_size = in->n_elements + (int)ft_strdlen(new_text) - 1;
	new_arr = ft_malloc(sizeof(t_element) * new_size);
	in->n_elements = new_size;
	ft_fill_arr(in, new_arr, i, new_text);
	ft_tag_redtype(new_arr, i, (int)ft_strdlen(new_text), c);
	ft_totalfree(new_text);
	ft_free_arr(in, size);
	free(in->elements);
	return (new_arr);
}

char	**ft_dbredir_split(char *str, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	tab = ft_malloc(sizeof(char *) * ft_count_elements(str, c));
	i = 0;
	k = 0;
	while (str[i] != '\0')
	{
		j = i;
		while (str[i] != c && str[i] != '\0')
			i++;
		if (i > j)
			tab[k++] = ft_savewords(str + j, i - j);
		if (str[i] == c)
		{
			tab[k++] = ft_save_dbred(c);
			i += 2;
		}
	}
	tab[k] = NULL;
	return (tab);
}
