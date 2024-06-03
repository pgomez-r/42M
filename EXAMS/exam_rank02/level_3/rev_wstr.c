/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:04:00 by pgomez-r          #+#    #+#             */
/*   Updated: 2023/09/28 13:54:57 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(int ac, char **av)
{
	int	start = 0;
	int	end = 0;

	if (ac == 2)
	{
		while (av[1][end] != '\0')
			end++;
		while (end > 0)
		{
			end--;
			while (av[1][end] != ' ' && av[1][end] != '\t' && end > 0)
				end--;
			start = end;
			if (end > 0)
				start++;
			while (av[1][start] != ' ' && av[1][start] != '\t'
				&& av[1][start] != '\0')
			{	
				ft_putchar(av[1][start]);
				start++;
			}
			if (end > 0)
				write(1, " ", 1);
		}
	}
	return (write(1, "\n", 1), 0);
}
