/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:39:05 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/15 02:02:39 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <cmath>

/**
 * Class PmergeMe; canonical form elements + sortVector + sortList
 */
class	PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();

		void	sortVector(std::vector<int> &arr);
		void	sortList(std::list<int> &arr);
	private:
		template <typename Container>
		void	_fordJohnsonSort(Container &arr);
		template <typename Container>
		void	_insertJacobsthalOrder(Container &mainChain, Container &pend);
		template <typename Container>
		size_t	_binarySearch(const Container &mainChain, int value, size_t left, size_t right);
		long	_jacobNum(long n);
};

template <typename Container>
void 	_fordJohnsonSort(Container &arr)
{

}

template <typename Container>
void 	_insertJacobsthalOrder(Container &mainChain, Container &pend)
{
	int prev_jacobsthal = jacobNum(1);
	int inserted_numbers = 0;
	int offset = 0;

	for (int k = 2; ; k++)
	{
		int curr_jacobsthal = jacobNum(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;

		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break ;

		int nbr_of_times = jacobsthal_diff;
		std::Container<int>::iterator pend_it = pend.begin() + (jacobsthal_diff - 1);
		std::Container<int>::iterator bound_it = mainChain.begin() + (curr_jacobsthal + inserted_numbers);

		while (nbr_of_times)
		{
			int value = *pend_it;
			size_t pos = binarySearch(mainChain, value, 0, mainChain.size() - 1);
			std::Container<int>::iterator inserted = mainChain.insert(mainChain.begin() + pos, value);

			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			if (pend_it != pend.begin())
				pend_it--;
	
			offset += (inserted - mainChain.begin()) == (curr_jacobsthal + inserted_numbers);
			bound_it = mainChain.begin() + (curr_jacobsthal + inserted_numbers - offset);
		}

		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	if (!pend.empty())
	{
		int value = pend[0];
		size_t pos = binarySearch(mainChain, value, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, value);
	}
}

template <typename Container>
size_t 	_binarySearch(const Container& mainChain, int value, size_t left, size_t right)
{
	typename Container::const_iterator left_it = mainChain.begin();
	typename Container::const_iterator right_it = mainChain.begin();
	std::advance(left_it, left);
	std::advance(right_it, right);

	while (left <= right)
	{
		size_t mid = left + (right - left) / 2;
		typename Container::const_iterator mid_it = left_it;
		std::advance(mid_it, mid - left);

		if (*mid_it < value)
		{
			left = mid + 1;
			left_it = mid_it;
			std::advance(left_it, 1);
		}
		else
		{
			if (mid == 0)
				break;
			right = mid - 1;
			right_it = mid_it;
			std::advance(right_it, -1);
		}
	}
	return (left);
}

/**
 * Auxiliary functions for the main.cpp file (or leave them in the main.cpp file?)
 * TODO: check if allowed to add functions in Class.cpp file that are not part of the class
 */
// Will add functions here as needed

#endif