/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:10 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/07 13:17:11 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _maxSize(0)
{
}

Span::Span(unsigned int n) : _maxSize(n)
{
}

Span::Span(const Span &src)
{
	if (this != &src)
		*this = src;
}

Span::~Span()
{
}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		this->_maxSize = rhs._maxSize;
		this->_numbers = rhs._numbers;
	}
	return (*this);
}


void	Span::addNumber(int n)
{
	if (_numbers.size() == _maxSize)
		throw StorageLimitException();
	this->_numbers.push_back(n);
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_numbers.size() + std::distance(begin, end) > this->_maxSize)
		throw StorageLimitException();
	this->_numbers.insert(_numbers.end(), begin, end);
}

int	Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	int	min = this->_numbers[1] - this->_numbers[0];
	for (int i = 1; i < static_cast<int>(this->_numbers.size()); i++)
	{
		if (this->_numbers[i] - this->_numbers[i - 1] < min)
			min = this->_numbers[i] - this->_numbers[i - 1];
	}
	return (min);
}

int	Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NoSpanException();
	std::sort(this->_numbers.begin(), this->_numbers.end());
	int	max = this->_numbers[this->_numbers.size() - 1] - this->_numbers[0];
	return (max);
}

const char *Span::StorageLimitException::what() const throw()
{
	return ("Storage limit reached");
}

const char *Span::NoSpanException::what() const throw()
{
	return ("No span to calculate: not enough numbers in the container");
}

// std::ostream &operator<<(std::ostream &out, const Span &src)
// {
// 	out << "Max size: " << src._maxSize << std::endl;
// 	out << "Numbers: ";
// 	for (int i = 0; i < src._numbers.size(); i++)
// 	{
// 		out << src._numbers[i];
// 		if (i < src._numbers.size() - 1)
// 			out << ", ";
// 	}
// 	out << std::endl;
// 	return (out);
// }
