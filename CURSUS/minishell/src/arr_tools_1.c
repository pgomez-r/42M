/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tools_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 22:59:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/02/28 15:09:25 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_tag_type(t_element *arr, int start, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(arr[start].data, c))
			arr[start++].type = c;
		else
			arr[start++].type = '0';
		i++;
	}
}

void	ft_tag_redtype(t_element *arr, int start, int size, char c)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (ft_strchr(arr[start].data, c))
		{
			if (c == '<')
				arr[start++].type = 'h';
			else if (c == '>')
				arr[start++].type = 'a';
			else if (c == '&')
				arr[start++].type = '&';
		}
		else
			arr[start++].type = '0';
		i++;
	}
}

char	*ft_write_token(char c)
{
	char	*str;

	str = ft_malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_save_dbred(char c)
{
	char	*str;

	str = ft_malloc(sizeof(char) * 3);
	str[0] = c;
	str[1] = c;
	str[2] = '\0';
	return (str);
}

size_t	ft_count_elements(char *str, char c)
{
	int		i;
	size_t	cnt;

	i = -1;
	cnt = 1;
	while (str[++i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			cnt++;
		if (str[i + 1] != '\0')
			cnt++;
	}
	return (cnt);
}
