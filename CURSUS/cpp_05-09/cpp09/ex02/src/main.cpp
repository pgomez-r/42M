/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:35:56 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/19 14:58:39 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

template <typename Container>
bool	isSorted(const Container &arr)
{
	if (arr.size() < 2)
		return (true);
	typename Container::const_iterator it = arr.begin();
	typename Container::const_iterator next_it = it;
	++next_it;
	while (next_it != arr.end())
	{
		if (*it > *next_it)
			return (false);
		++it;
		++next_it;
	}
	return (true);
}

bool isNumInVector(const std::vector<int>& vec, int num)
{
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
		if (*it == num)
			return (true);
	}
	return (false);
}

int	main()
{
	std::vector<int>	vec;
	std::list<int>		lst;
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	while (vec.size() < 557)
	{
		int value = (std::rand() % 6001) - 3000;
		if (!isNumInVector(vec, value))
		{
			vec.push_back(value);
			lst.push_back(value);
		}
	}

	std::cout << "ARRAY OF SIZE: " << vec.size() << " - before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	PmergeMe merger;
	merger.sortVector(vec);
	merger.sortList(lst);

	std::cout << YELLOW << "VECTOR:  ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	if (isSorted(vec))
		std::cout << GREEN << "VECTOR OF SIZE: " << vec.size() << " ORDER: OK" << RESET << std::endl;
	else
		std::cout << RED << "VECTOR OF SIZE: " << vec.size() << " ORDER: NOK" << RESET << std::endl;
	std::cout << std::endl;

	std::cout << YELLOW << "LIST:    ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	if (isSorted(lst))
		std::cout << GREEN << "LIST OF SIZE: " << lst.size() << " ORDER: OK" << RESET << std::endl;
	else
		std::cout << RED << "LIST OF SIZE: " << lst.size() << " ORDER: NOK" << RESET << std::endl;

	return (0);	
}
