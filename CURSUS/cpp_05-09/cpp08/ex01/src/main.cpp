/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:17:08 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/07 13:17:09 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * TODO: improve main with more test (negatives, iteratorAddNumber(), exceptions, etc)
 */
#include "Span.hpp"

int	main(void)
{
	Span	sp = Span(5);

	try
	{
		sp.addNumber(42);
		sp.addNumber(42);
		sp.addNumber(42);
		// sp.addNumber(9);
		// sp.addNumber(11);
		//sp.addNumber(15);

		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
