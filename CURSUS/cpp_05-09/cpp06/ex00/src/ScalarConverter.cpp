/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:53:44 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/01/31 14:54:19 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/**
* TODO: combine and simplify _fromPseudoLiteral IF check
* TODO: check: can I leave nan to the same case as not founded/undefined?
*/
ScalarConverter::static void    convert(const std::string &input)
{
	char    *ptr;
	
    strtol(input.c_str(), &ptr, 10);
	if (*ptr == '\0')
		return (this->_fromInt(input));
	strtof(input.c_str(), &ptr);
	if (*ptr == '\0')
		return (this->_fromFloat(input));
	strtod(input.c_str(), &ptr);
	if (*ptr == '\0')
		return (this->_fromDouble(input));

	if (input.size() == 1 && ((input[0] >= 32 && input[0] < 48) || (input[0] > 57 && input[0] < 126)))
		return (this->_fromChar(input));

    if (input == "-inff" || input == "+inff" || input == "nanf" || input == "inff" || input == "+nanf")
		return (this->_fromPseudoLiteral(input));
	if ( input == "-inf" || input == "+inf" || input == "nan" || input == "inf" || input == "+nan")
		return (this->_fromPseudoLiteral(input));
   
    std::cout << "no possible data" << std::endl;
}


static void	_fromInt(const std::string &str)
{

}
static void	_fromFloat(const std::string &str)
{

}
static void	_fromDouble(const std::string &str)
{}
static void	_fromChar(const std::string &str)
{

}
static void	_fromPseudoLiteral(const std::string &str)
{

}
