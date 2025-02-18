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

int	main()
{
	std::vector<int> vec;
	std::list<int> lst;
	
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	
	for (int i = 0; i < 21; ++i)
	{
		int value = std::rand() % 100;
		vec.push_back(value);
		lst.push_back(value);
	}

	std::cout << "Vector before: ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "List before:   ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	PmergeMe merger;
	merger.sortVector(vec);
	merger.sortList(lst);

	std::cout << "Vector after:  ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "List after:    ";
	for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	return (0);	
}
