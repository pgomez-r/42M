/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:38:51 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/20 11:25:29 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &src)
{
	(void)src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &src)
{
	(void)src;
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

void	PmergeMe::sortVector(std::vector<int> &arr)
{
	this->_fordJohnsonSort(arr);
}

void	PmergeMe::sortList(std::list<int> &arr)
{
	this->_fordJohnsonSort(arr);
}


long PmergeMe::_jacobNum(long n)
{   
	return (round((pow(2, n + 1) + pow(-1, n)) / 3));
}

/**
 * Parsing and aux functions used in main.cpp
 * (i) Subject does not ask for any class implementation, but
 * 		it does limit the files into PmergeMe.cpp/hpp dnd main.cpp;
 * 	For better readability, main functions are defined here
 */

bool isNumInVector(const std::vector<int>& vec, int num)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it == num)
			return (true);
	}
	return (false);
}
