/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:25 by codespace         #+#    #+#             */
/*   Updated: 2024/05/15 04:15:12 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/*Constructors*/
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

/*Destructor*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*- int/float <> fixed-point - member functions*/
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

/*Class member operator overloads*/
Fixed	&operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fpValue = rhs.getRawBits();
	return (*this);
}

/*Operator overload (outside the class scope)*/
std::ostream	&operator<<(std::ostream &output, Fixed const &fpNum)
{
	output << fpNum.toFloat();
	return (output);
}
