/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2024/05/16 13:32:37 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO - Comment constructor and method cout? TMI...
// TODO - Check test outputs, << may not be working (getting rawBits now!)

#include "../inc/Fixed.hpp"

/*----SUBJECT_MAIN---*/
// int	main(void)
// {
// 	Fixed			a;
// 	Fixed const		b(Fixed(5.05f) * Fixed(2));

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;

// 	std::cout << Fixed::max(a, b) << std::endl;
// 	return (0);
// }

/*----MY_OWN_MAIN----*/
int main(void)
{
	Fixed a;
	Fixed const b(Fixed(42.42f) * Fixed(11));

	std::cout << "VALUES BEFORE TESTING" << std::endl;
	std::cout << "A = " << a << std::endl;
	std::cout << "B = " << b << std::endl;
	
	std::cout << "Test operator [++] (prefix) on A: " << ++a << std::endl; // Expected output: 1
	std::cout << "Test operator [++] (postfix) on A: " << a++ << std::endl; // Expected output: 1
	std::cout << "Test value of A after [++] postfix: " << a << std::endl; // Expected output: 2

	std::cout << "Test operator [+] (a + b) = " << (a + b) << std::endl; // Expected output: 468.62
	std::cout << "Test operator [-] (a - b) = " << (a - b) << std::endl; // Expected output: 464.62
	std::cout << "Test operator [*] (a * b): " << (a * b) << std::endl; // Expected output: 933.24
	std::cout << "Test operator [/] (a / b): " << (a / b) << std::endl; // Expected output: 0.00428

	std::cout << "Test operator [>] (a > b) = " << (a > b) << std::endl; // Expected output: 0
	std::cout << "Test operator [<] (a < b) = " << (a < b) << std::endl; // Expected output: 1
	std::cout << "Test operator [>=] (a >= b) = " << (a >= b) << std::endl; // Expected output: 0
	std::cout << "Test operator [<=] (a <= b) = " << (a <= b) << std::endl; // Expected output: 1
	std::cout << "Test operator [==] (a == b) = " << (a == b) << std::endl; // Expected output: 0
	std::cout << "Test operator [!=] (a != b) = " << (a != b) << std::endl; // Expected output: 1

	// Test max and min functions
	std::cout << "Test [max] function (max(a, b)) = " << Fixed::max(a, b) << std::endl; // Expected output: 466.62
	std::cout << "Test [min] function (min(a, b)) = " << Fixed::min(a, b) << std::endl; // Expected output: 2

	return (0);
}
