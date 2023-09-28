/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:47:47 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/28 15:45:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	i = 0;
	int	first = 0;
	int	flag = 0;

	if (ac < 2)
		return (write(1, "\n", 1), 1);
	while ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i] != '\0')
		i++;
	first = i;
	while (av[1][i] != ' ' && av[1][i] != '\t' && av[1][i] != '\0')
		i++;
	while ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i] != '\0')
		i++;
	while (av[1][i] != '\0')
	{
		if ((av[1][i] == ' ' || av[1][i] == '\t') && av[1][i + 1] != ' '
			&& av[1][i + 1] != '\t' && av[1][i + 1] != '\0')
			ft_putchar(av[1][i]);
		if (av[1][i] != ' ' && av[1][i] != '\t')
		{	
			ft_putchar(av[1][i]);
			flag++;
		}
		i++;
	}
	if (flag > 0)
		write(1, " ", 1);
	while (av[1][first] != ' ' && av[1][first] != '\t' && av[1][first] != '\0')
	{
		ft_putchar(av[1][first]);
		first++;
	}
	return (write(1, "\n", 1), 0);
}
