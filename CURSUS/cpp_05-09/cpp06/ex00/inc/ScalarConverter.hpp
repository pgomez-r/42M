/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:53:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/03 12:49:51 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTED_HPP
#define SCALARCONVERTED_HPP

#include <iostream>
#include <sstream>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		~ScalarConverter(void);
		ScalarConverter &operator=(const ScalarConverter &src);
	
	public:
		static void	convert(const std::string &input);
};

#endif