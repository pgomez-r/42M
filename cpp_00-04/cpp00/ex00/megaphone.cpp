/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 19:24:55 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/15 19:59:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	int		i;
	int		j;
	char	c;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 0;
		while (av[++i] != NULL)
		{
			j = -1;
			while(av[i][++j])
			{
				c = toupper(av[i][j]);
				std::cout << c;
			}
			if (av[i +1])
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}
