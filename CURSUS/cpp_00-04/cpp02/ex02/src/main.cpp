/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:27 by codespace         #+#    #+#             */
/*   Updated: 2024/05/31 11:03:04 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	
	std::cout << "Test operator [++] (prefix) on A: " << ++a << std::endl;
	std::cout << "Test operator [++] (postfix) on A: " << a++ << std::endl;
	std::cout << "Test value of A after [++] postfix: " << a << std::endl;

	std::cout << "Test operator [+] (a + b) = " << (a + b) << std::endl;
	std::cout << "Test operator [-] (a - b) = " << (a - b) << std::endl;
	std::cout << "Test operator [*] (a * b): " << (a * b) << std::endl;
	std::cout << "Test operator [/] (a / b): " << (a / b) << std::endl;

	std::cout << "Test operator [>] (a > b) = " << (a > b) << std::endl;
	std::cout << "Test operator [<] (a < b) = " << (a < b) << std::endl;
	std::cout << "Test operator [>=] (a >= b) = " << (a >= b) << std::endl;
	std::cout << "Test operator [<=] (a <= b) = " << (a <= b) << std::endl;
	std::cout << "Test operator [==] (a == b) = " << (a == b) << std::endl;
	std::cout << "Test operator [!=] (a != b) = " << (a != b) << std::endl;

	std::cout << "Test [max] function (max(a, b)) = " << Fixed::max(a, b) << std::endl;
	std::cout << "Test [min] function (min(a, b)) = " << Fixed::min(a, b) << std::endl;

	return (0);
}
