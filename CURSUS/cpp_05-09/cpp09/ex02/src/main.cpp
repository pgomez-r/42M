/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:35:56 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/18 11:09:13 by pgruz11          ###   ########.fr       */
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

int	main()
{
	std::vector<int>	vec;
	std::list<int>		lst;
	
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	for (int i = 0; i < 11; ++i)
	{
		int value = std::rand() % 100;
		vec.push_back(value);
		// vec.push_back(93);
		// lst.push_back(93);
		// vec.push_back(95);
		// lst.push_back(95);
		// vec.push_back(34);
		// lst.push_back(34);
		// vec.push_back(32);
		// lst.push_back(32);
	}

	std::cout << "VECTOR OF SIZE: " << vec.size() << " - before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "LIST OF SIZE:   " << lst.size() << " - before: ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	PmergeMe merger;
	merger.sortVector(vec);
	std::cout << std::endl;
	//merger.sortList(lst);

	std::cout << YELLOW << "Vector after:  ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	if (isSorted(vec))
		std::cout << GREEN << "VECTOR OF SIZE: " << vec.size() << " ORDER: OK" << RESET << std::endl;
	else
		std::cout << RED << "VECTOR OF SIZE: " << vec.size() << " ORDER: NOK" << RESET << std::endl;

	// std::cout << YELLOW << "List after:    ";
	// for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
	// 	std::cout << *it << " ";
	// std::cout << RESET << std::endl;
	// if (isSorted(lst))
	// 	std::cout << GREEN << "LIST OF SIZE: " << lst.size() << " ORDER: OK" << RESET << std::endl;
	// else
	// 	std::cout << RED << "LIST OF SIZE: " << lst.size() << " ORDER: NOK" << RESET << std::endl;

	return (0);	
}
