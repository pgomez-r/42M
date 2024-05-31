/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 01:28:25 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 11:36:07 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Fixed.hpp"

/*----Constructors----*/
Fixed::Fixed()
{
	this->_fpValue = 0;
}

Fixed::Fixed(const int n)
{
	this->_fpValue = n << this->_fractBits;
}

Fixed::Fixed(const float n)
{
	this->_fpValue = roundf(n * (1 << _fractBits));
}

Fixed::Fixed(const Fixed &src)
{
	*this = src;
}

/*----Destructor----*/
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/*---int/float <> fixed-point - member functions---*/
int		Fixed::getRawBits(void) const
{
	return (this->_fpValue);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((static_cast<float>(this->getRawBits())) / (1 << _fractBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fpValue >> _fractBits);
}

/*--Class member operator overloads--*/
/*----Copy assignment operator----*/
Fixed	&Fixed::operator=(Fixed const &rhs)
{
	this->_fpValue = rhs.getRawBits();
	return (*this);
}

/*----Comparison opertaros----*/
bool    Fixed::operator>(const Fixed &rhs) const
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool    Fixed::operator<(const Fixed &rhs) const
{
	return (this->getRawBits() < rhs.getRawBits());
}
bool    Fixed::operator>=(const Fixed &rhs) const
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool    Fixed::operator<=(const Fixed &rhs) const
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool    Fixed::operator==(const Fixed &rhs) const
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool    Fixed::operator!=(const Fixed &rhs) const
{
	return (this->getRawBits() != rhs.getRawBits());
}

/*----Arithmetic operators----*/
Fixed   Fixed::operator+(const Fixed &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed   Fixed::operator-(const Fixed &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed   Fixed::operator*(const Fixed &rhs) const
{
	return (this->toFloat() * rhs.toFloat());
}

Fixed   Fixed::operator/(const Fixed &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

/*---Increment & Decrement operators----*/
Fixed	&Fixed::operator++(void)
{
	this->_fpValue += 1;
	return (*this);
}

Fixed	&Fixed::operator--(void)
{
	this->_fpValue -= 1;
	return (*this);
}

Fixed   Fixed::operator++(int)
{
	Fixed	aux(*this);

	this->_fpValue += 1;
	return (aux);
}

Fixed   Fixed::operator--(int)
{
	Fixed	aux(*this);

	this->_fpValue -= 1;
	return (aux);
}

/*----MIN & MAX----*/
Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return (a);
	return (b);
}

/*Operator overload (outside the class scope)*/
std::ostream	&operator<<(std::ostream &output, Fixed const &fpNum)
{
	output << fpNum.toFloat();
	return (output);
}
