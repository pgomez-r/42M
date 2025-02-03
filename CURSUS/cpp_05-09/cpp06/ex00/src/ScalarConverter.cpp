/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:53:44 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/03 14:13:35 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
 * TODO: delete comments and debug-prints before submitting to intra
 */

ScalarConverter::ScalarConverter(void)
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
	if (this != &src)
		*this = src;
	std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	(void)src;
	return (*this);
}

void	ScalarConverter::convert(const std::string &input)
{
	//Handling single char input
	if (input.length() == 1 && isprint(input[0]) && !isdigit(input[0]))
	{
		std::cout << "char: " << input[0] << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double> (input[0]) << ".0" << std::endl;
		return ;
	}
	
	//Handling NaN - Not a Number - and infinity
	char	*ptr = NULL;
	double	input_double = strtod(input.c_str(), &ptr);
	if (std::isnan(input_double))
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return ;
	}
	else if (std::isinf(input_double))
	{
		std::cout << "int: impossible" << std::endl;
		std::cout << "char: impossible" << std::endl;
		if (input_double > 0)
		{
			std::cout << "double: +inf" << std::endl;
			std::cout << "float: +inff" << std::endl;
		}
		else
		{
			std::cout << "double: -inf" << std::endl;
			std::cout << "float: -inf" << std::endl;
		}
		return ;
	}

	//HANDLING VALID NUMBERS
	//Input is a double (assigned before)
	if (input_double && *ptr == '\0')
	{
		std::cout << "char: ";
		if (input_double >= 32 && input_double <= 126)
			std::cout << static_cast<char>(input_double) << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (input_double <= std::numeric_limits<int>::max() && input_double >= std::numeric_limits<int>::min())
			std::cout << static_cast<int>(input_double) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		if (input_double == static_cast<int>(input_double))
			std::cout << std::fixed << std::setprecision(1);
		if (input_double <= std::numeric_limits<float>::max() && input_double >= std::numeric_limits<float>::min())
			std::cout << "float: " <<  static_cast<float>(input_double) << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		if (input_double <= std::numeric_limits<double>::max() && input_double >= std::numeric_limits<double>::min())
			std::cout << "double: " << input_double << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	//Input is a float
	ptr = NULL;
	float	input_float = strtof(input.c_str(), &ptr);
	if (input_float && *ptr == 'f')
	{
		std::cout << "char: ";
		if (input_float >= 32 && input_float <= 126)
			std::cout <<  static_cast<char>(input_float)<< std::endl;
		else
			std::cout << "Non displayable" << std::endl;
		std::cout << "int: ";
		if (input_float <= std::numeric_limits<int>::max() && input_float >= std::numeric_limits<int>::min())
			std::cout << static_cast<int>(input_float) << std::endl;
		else
			std::cout << "impossible" << std::endl;
		if (input_float == static_cast<int>(input_float))
			std::cout << std::fixed << std::setprecision(1);
		if (input_float <= std::numeric_limits<float>::max() && input_float >= std::numeric_limits<float>::min())
			std::cout << "float: " << input_float << "f" << std::endl;
		else
			std::cout << "float: impossible" << std::endl;
		if (input_float <= std::numeric_limits<double>::max() && input_float >= std::numeric_limits<double>::min())
			std::cout << "double: " << static_cast<double>(input_float) << std::endl;
		else
			std::cout << "double: impossible" << std::endl;
		return ;
	}
	
	//Input is an int
	ptr = NULL;
	long	input_int = strtol(input.c_str(), &ptr, 10);
	if(input_int && *ptr == '\0')
	{
		std::cout << "char: ";
		if (input_int >= 32 && input_int <= 126)
			std::cout <<  static_cast<char>(input_int);
		else
			std::cout << "Non displayable";
		std::cout << std::endl << "int: ";
		if (input_int <= std::numeric_limits<int>::max() && input_int >= std::numeric_limits<int>::min())
			std::cout << static_cast<int>(input_int);
		else
			std::cout << "impossible";
		std::cout << std::endl;
		std::cout << "float: " <<  static_cast<float>(input_int) << ".0f" <<std::endl;
		std::cout << "double: " <<  static_cast<double>(input_int) << ".0" << std::endl;
		return ;
	}

	//None of the cases, for instance a string - NaN
	std::cout <<"char: impossible"<< std::endl;
	std::cout <<"int: impossible"<< std::endl;
	std::cout <<"float: nanf"<< std::endl;
	std::cout <<"double: nan"<< std::endl;
}
