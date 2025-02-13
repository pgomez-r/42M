/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:05 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/13 12:18:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>
#include <algorithm>

class   Span
{
	private:
		unsigned int			_maxSize;
		std::vector<int>		_numbers;
		Span();
	public:
		Span(unsigned int n);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &rhs);
	
		void			addNumber(int n);
		void			addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int				shortestSpan();
		int				longestSpan();
	
		class	StorageLimitException : public std::exception
		{
			virtual const char *what() const throw();
		};
		class	NoSpanException : public std::exception
		{
			virtual const char *what() const throw();
		};
};

# endif