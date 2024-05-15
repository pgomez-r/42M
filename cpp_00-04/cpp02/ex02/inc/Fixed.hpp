/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:17 by codespace         #+#    #+#             */
/*   Updated: 2024/05/15 04:11:28 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_fpValue;
		static const int	_fractBits = 8;
	public:
		Fixed();
		Fixed(Fixed &src);
		Fixed(const int n);
		Fixed(const float n);
		~Fixed();
		Fixed	&operator=(Fixed const &rhs);

		int		getRawBits(void);
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
	
		bool    operator>(const Fixed &rhs) const;
		bool    operator<(const Fixed &rhs) const;
		bool    operator>=(const Fixed &rhs) const;
		bool    operator<=(const Fixed &rhs) const;
		bool    operator==(const Fixed &rhs) const;
		bool    operator!=(const Fixed &rhs) const;

		Fixed   operator+(const Fixed &rhs) const;
		Fixed   operator-(const Fixed &rhs) const;
		Fixed   operator*(const Fixed &rhs) const;
		Fixed   operator/(const Fixed &rhs) const;

		Fixed&  operator++(void); // prefix
		Fixed   operator++(int); // postfix
		Fixed&  operator--(void); // prefix
		Fixed   operator--(int); // postfix

		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(const Fixed &a, const Fixed &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fpNum);

#endif