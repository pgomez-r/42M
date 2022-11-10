/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 07:57:24 by pgomez-r          #+#    #+#             */
/*   Updated: 2022/04/06 17:34:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	main(int argc, char *argv[])
{
	int		arg_ind;
	int		a;
	char	*temp;

	arg_ind = 1;
	while (arg_ind < argc)
	{
		ft_strcmp(argv[arg_ind], argv[arg_ind + 1]);
		if (ft_strcmp < 0)
		{
			temp = argv[arg_ind];
			argv[arg_ind] = argv[arg_ind + 1];
			argv[arg_ind + 1] = temp;
		}
		arg_ind++;
	}
	a = 0;
	arg_ind = 1;
	while (arg_ind < argc)
	{
		while (argv[arg_ind][a] != '\0')
		{
			write(1, &argv[arg_ind][a], 1);
			a++;
		}
		a = 0;
		arg_ind++;
	}
	write(1, "\n", 1);
	return (0);
}
