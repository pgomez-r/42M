/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2024/05/14 04:06:21 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int	main(void)
{
	std::cout << "DECLARING INSTANCE #1 OF CLASS WITH DEFAULT CONSTRUCTOR..." << std::endl;
	Fixed a;
	std::cout << std::endl;
	std::cout << "DECLARING INSTANCE #2 OF CLASS USING COPY OF #1 CONSTRUCTOR..." << std::endl;
	Fixed b(a);
	std::cout << std::endl;
	std::cout << "DECLARING INSTANCE #3 OF CLASS USING DEFAULT CONSTRUCTOR AGAIN..." << std::endl;
	Fixed c;
	std::cout << std::endl;
	std::cout << "GIVING INSTANCE #3 SAME VALUE OF #2 (c = b)..." << std::endl;
	c = b;
	std::cout << std::endl;

	std::cout << "CHECKING VALUES OF EACH INSTANCE..." << std::endl;
	std::cout << a.getRawBits() << " is the value of instance #1" << std::endl; 
	std::cout << b.getRawBits() << " is the value of instance #2" << std::endl;
	std::cout << c.getRawBits() << " is the value of instance #3" << std::endl;
	return (0);
}
