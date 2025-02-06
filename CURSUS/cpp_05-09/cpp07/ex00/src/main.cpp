/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:35:08 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/06 16:54:54 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/whatever.hpp"
#include <iostream>

// /**
//  * This is a test asked on evaluation sheet to check if the templates functions
//  * also work with complex types such as cpp objects
//  */
// class Awesome
// {
// 	public:
// 		Awesome(void) : _n(0) {}
// 		Awesome( int n ) : _n( n ) {}
// 		Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
// 		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
// 		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 		int get_n() const { return _n; }
// 	private:
// 		int _n;
// };
// 	std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o;}

// int main(void)
// {
// 	Awesome a(2), b(4);
// 	swap(a, b);
// 	std::cout << a << " " << b << std::endl;
// 	std::cout << max(a, b) << std::endl;
// 	std::cout << min(a, b) << std::endl;
// 	return (0);
// }

int main( void )
{
	float a = 42.0;
	float b = 11.30;

	std::cout << "a = " << a << ", b = " << b << std::endl;
	swap(a, b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "Hola";
	std::string d = "Mundo";
	std::cout << "c = " << c << ", d = " << d << std::endl;
	swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
   
	return (0);
}
