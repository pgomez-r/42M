/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 10:57:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

int	main(void)
{
	std::cout << "DECLARING 4 INSTANCES OF FIXED CLASS(a, b, c, d)" << std::endl;
	std::cout << "For instance 'a': ";
	Fixed		a;
	std::cout << "For instance 'b': ";
	Fixed const	b(11);
	std::cout << "For instance 'c': ";
	Fixed const	c(42.42f);
	std::cout << "For instance 'd': ";
	Fixed const	d(b);
	std::cout << "Now we give vaule to instance 'a' in this manner: "<< std::endl;
	a = Fixed(1992.1103f);
	
	std::cout << "LET'S SEE THE VALUE OF OR FIXED-POINT OBJECTS..." << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "AND NOW, LET'S PRINT THEM AS INTEGERS..." << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
	return (0);
}
