/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz <pgruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:59:47 by pgruz             #+#    #+#             */
/*   Updated: 2023/08/01 22:17:32 by pgruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/philo.h"

int	ft_args_digit(int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			if (!ft_isdigit(av[i][j]))
				return (1);
			j++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (ft_printf_error("Wrong number of arguments\n"), 1);
	if (!ft_args_digit(ac, av))
		return (ft_printf_error("Some/all arguments are not digits\n"), 1);
	return (0);
}
