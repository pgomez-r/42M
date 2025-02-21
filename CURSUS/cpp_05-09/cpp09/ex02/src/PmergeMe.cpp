/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:38:51 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/21 02:04:12 by pgruz11          ###   ########.fr       */
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

std::string	validateInput(std::vector<std::string> av)
{
	for (size_t i = 0; i < av.size(); i++)
	{
		char	*ptr;
		long	n = strtol(av[i].c_str(), &ptr, 10);
		if (*ptr != '\0')
			return ("non-number arguments not allowed");
		if (av[i][0] == '-' && av[i][1] != '0')
			return ("negative numbers not allowed");
		if (n > INT_MAX)
			return ("only integer numbers allowed");
	}
	return ("");
}

std::vector<std::string>	argvToStr(int ac, char **av)
{
	std::vector<std::string>	args;
	for (int i = 1; i < ac; i++)
		args.push_back(std::string(av[i]));
	
	std::vector<std::string>	split;
	for (size_t i = 0; i < args.size(); i++)
	{		
		std::string word;
		std::stringstream ss(args[i]);
		while (getline(ss, word, ' '))
		{
			if(!word.empty())
				split.push_back(word);
		}
	}
	return (split);
}
