/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:17 by codespace         #+#    #+#             */
/*   Updated: 2024/05/15 03:29:48 by codespace        ###   ########.fr       */
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
};

std::ostream	&operator<<(std::ostream &output, Fixed const &fpNum);

#endif