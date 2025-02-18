/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:39:05 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/18 10:56:33 by pgruz11          ###   ########.fr       */
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
#include <cstdlib>
#include <ctime>

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
		long	_jacobNum(long n);
		template <typename Container>
		void	_fordJohnsonSort(Container &arr);
		template <typename Container>
		void	_insertJacobsthalOrder(Container &mainChain, Container &pend);
		template <typename Container>
		size_t	_binarySearch(const Container &mainChain, int value, size_t left, size_t right);
};

template <typename Container>
void 	PmergeMe::_fordJohnsonSort(Container &arr)
{
	if (arr.size() < 2)
		return ;

	// Step 1: Pair elements and sort each pair
	typename Container::iterator it = arr.begin();
	while (it != arr.end())
	{
		typename Container::iterator next_it = it;
		++next_it;
		if (next_it == arr.end())
			break ;
		if (*it > *next_it)
			std::swap(*it, *next_it);
		it = next_it;
		++it;
	}
	// Step 2: Recursively sort the pairs by their larger element
	if (arr.size() > 2)
	{
		Container	largerElements;
		for (typename Container::iterator it = ++arr.begin(); it != arr.end(); std::advance(it, 2))
			largerElements.push_back(*it);
		this->_fordJohnsonSort(largerElements);

		// Rebuild the array based on sorted larger elements
		Container	sortedArr;
		typename Container::iterator larger_it = largerElements.begin();
		typename Container::iterator arr_it = arr.begin();
		while (larger_it != largerElements.end())
		{
			sortedArr.push_back(*arr_it);
			sortedArr.push_back(*larger_it);
			std::advance(arr_it, 2);
			++larger_it;
		}
		if (arr.size() % 2 != 0)
			sortedArr.push_back(arr.back());
		arr = sortedArr;
	}

	// Step 3: Create the main chain and pend
	Container mainChain;
	mainChain.push_back(*arr.begin());
	typename Container::iterator second = arr.begin();
	++second;
	mainChain.push_back(*second);

	Container pend;
	typename Container::iterator i = arr.begin();
	std::advance(i, 2);
	while (i != arr.end())
	{
		pend.push_back(*i);
		typename Container::iterator next = i;
		++next;
		if (next != arr.end())
			mainChain.push_back(*next);
		std::advance(i, 2);
	}

	// Step 4: Insert pend elements to mainChain in Jacobsthal order
	this->_insertJacobsthalOrder(mainChain, pend);
	arr = mainChain;
}

template <typename Container>
void 	PmergeMe::_insertJacobsthalOrder(Container &mainChain, Container &pend)
{
	int prev_jacobsthal = static_cast<int>(this->_jacobNum(1));
	int inserted_numbers = 0;
	int offset = 0;

	for (int k = 2; ; k++)
	{
		int curr_jacobsthal = this->_jacobNum(k);
		int jacobsthal_diff = curr_jacobsthal - prev_jacobsthal;

		if (jacobsthal_diff > static_cast<int>(pend.size()))
			break ;

		int nbr_of_times = jacobsthal_diff;
		typename Container::iterator pend_it = pend.begin();
		std::advance(pend_it, jacobsthal_diff - 1);
		typename Container::iterator bound_it = mainChain.begin();
		std::advance(bound_it, curr_jacobsthal + inserted_numbers);

		while (nbr_of_times)
		{
			int value = *pend_it;
			size_t pos = this->_binarySearch(mainChain, value, 0, mainChain.size() - 1);
			typename Container::iterator insert_pos = mainChain.begin();
			std::advance(insert_pos, pos);
			typename Container::iterator inserted = mainChain.insert(insert_pos, value);

			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			if (pend_it != pend.begin())
				pend_it--;
	
			offset += (std::distance(mainChain.begin(), inserted)) == (curr_jacobsthal + inserted_numbers);
			bound_it = mainChain.begin();
			std::advance(bound_it, curr_jacobsthal + inserted_numbers - offset);
		}

		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	if (!pend.empty())
	{
		int value = *pend.begin();
		size_t pos = this->_binarySearch(mainChain, value, 0, mainChain.size() - 1);
		typename Container::iterator insert_pos = mainChain.begin();
		std::advance(insert_pos, pos);
		mainChain.insert(insert_pos, value);
	}
}

template <typename Container>
size_t 	PmergeMe::_binarySearch(const Container &mainChain, int value, size_t left, size_t right)
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