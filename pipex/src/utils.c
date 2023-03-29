/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 22:57:46 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/03/29 23:01:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_leaks(void)
{
	system("leaks -q pipex");
}

void	ft_print_dstr(char **dstr)
{
	size_t	i;

	i = 0;
	while (dstr[i] != NULL)
	{
		printf("%s\n", dstr[i]);
		i++;
	}
}

int	is_path(char *str)
{
	if (str[0] == 'P' && str[1] == 'A' && str[2] == 'T'
		&& str[3] == 'H' && str[4] == '=')
		return (0);
	return (1);
}
