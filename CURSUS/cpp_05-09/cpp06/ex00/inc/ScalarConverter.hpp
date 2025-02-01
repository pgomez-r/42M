/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:53:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/01/31 15:55:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTED_HPP
#define SCALARCONVERTED_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &src);
	
		static void	_fromInt(const std::string &str);
		static void	_fromFloat(const std::string &str);
		static void	_fromDouble(const std::string &str);
		static void	_fromChar(const std::string &str);
		static void	_fromPseudoLiteral(const std::string &str);
	public:
		static void	convert(const std::string &input);
};

std::ostream	&operator<<(std::ostream &output, const ScalarConverter &src);

#endif