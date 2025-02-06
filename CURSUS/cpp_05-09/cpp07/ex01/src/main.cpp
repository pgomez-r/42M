/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:46:25 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/06 15:16:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/iter.hpp"
#include <iostream>

// EVAL SHEET TEST MAIN
class Awesome
{
	public:
		Awesome( void ) : _n( 42 ) { return; }
		int get( void ) const { return this->_n; }
	private:
		int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }

int main()
{
	int tab[] = { 0, 1, 2, 3, 4 };
	Awesome tab2[5];
	iter( tab, 5, print );
	iter( tab2, 5, print );
	return 0;
}

// MY OWN MAIN
// Function to be used with iter
// template <typename T>
// void	printElement(const T &element)
// {
// 	std::cout << element << " ";
// }

// int main()
// {
// 	int intArray[] = {1, 2, 3, 4, 5};
// 	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
// 	std::string stringArray[] = {"hello", "world", "this", "is", "iter"};

// 	std::cout << "Int array: ";
// 	iter(intArray, 5, printElement);
// 	std::cout << std::endl;

// 	std::cout << "Double array: ";
// 	iter(doubleArray, 5, printElement);
// 	std::cout << std::endl;

// 	std::cout << "String array: ";
// 	iter(stringArray, 5, printElement);
// 	std::cout << std::endl;

// 	return 0;
// }
