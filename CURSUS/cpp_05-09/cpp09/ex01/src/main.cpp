/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:01:49 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/14 23:38:43 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: usage: ./RPN <operation_to_do_in_one_string>" << std::endl;
		return (1);
	}
	
	RPN	polska(av[1]);
	polska.calculate();
	
	return (0);	
}
