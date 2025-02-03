/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:53:57 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/03 13:15:31 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * TEST TO CHECK
 * - input: 4254564564546544454545554 -> float/double: 4.25456e+24(f)
 */

int main(int ac, char **av)
{
	if (ac != 2)
		std::cout << "Error: usage: ./convert <input_to_convert>" << std::endl;
	else
		ScalarConverter::convert(av[1]);
	return (0);
}
