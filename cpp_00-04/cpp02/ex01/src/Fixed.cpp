/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:25 by codespace         #+#    #+#             */
/*   Updated: 2024/05/15 03:29:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fpValue = n << this->_fractBits;
}

Fixed::Fixed(const float n)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fpValue = std::roundf(n * (1 << _fractBits));
}

Fixed::Fixed(Fixed &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed	&operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fpValue = rhs.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void)
{
	std::cout << "getRawBits method called" << std::endl;
	return (this->_fpValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

float	Fixed::toFloat(void)
{
	return (static_cast<float>(this->getRawBits() / (1 << _fractBits)));
}

int		Fixed::toInt(void)
{
	return (this->_fpValue >> _fractBits);
}

std::ostream	&operator<<(std::ostream &output, Fixed const &fpNum)
{
	output << fpNum.toFloat();
	return (output);
}
