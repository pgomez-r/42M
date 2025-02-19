/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:39:05 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/19 14:42:36 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"	

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
void simpleInsert(Container &mainChain, Container &pend)
{
	for (typename Container::iterator it = pend.begin(); it != pend.end(); ++it)
	{
		typename Container::iterator insert_pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
		mainChain.insert(insert_pos, *it);
	}
}

template <typename Container>
void	printContainer(const Container &arr, const std::string &msg)
{
	if (!msg.empty())
		std::cout << msg << std::endl;
	//std::cout << "Size: " << arr.size() << std::endl;
	for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

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
		Container	largerElements, smallerElements;
		typename Container::iterator ptr = arr.begin();
	
		while(ptr != arr.end())
		{
			typename Container::iterator next = ptr;
			++next;
			if (next == arr.end())
			{
				if (!smallerElements.empty() && *ptr > smallerElements.back())
					largerElements.push_back(*ptr);
				else
					smallerElements.push_back(*ptr);
				break ;
			}
			largerElements.push_back(*next);
			smallerElements.push_back(*ptr);
			std::advance(ptr, 2);
		}
		this->_fordJohnsonSort(largerElements);
		this->_fordJohnsonSort(smallerElements);

		// Step 2.5: Rebuild the array based on sorted larger elements
		Container	sortedArr;
		typename Container::iterator larger_it = largerElements.begin();
		typename Container::iterator smaller_it = smallerElements.begin();
		while (larger_it != largerElements.end() && smaller_it != smallerElements.end())
		{
			sortedArr.push_back(*smaller_it);
			sortedArr.push_back(*larger_it);
			++smaller_it;
			++larger_it;
		}
		while (smaller_it != smallerElements.end())
		{
			sortedArr.push_back(*smaller_it);
			++smaller_it;
		}
		while (larger_it != largerElements.end())
		{
			sortedArr.push_back(*larger_it);
			++larger_it;
		}
		arr = sortedArr;
	}
	// Step 3: Create the main chain and pend
	Container mainChain, pend;

	mainChain.push_back(*arr.begin());
	typename Container::iterator second = arr.begin();
	++second;
	if (second != arr.end())
		mainChain.push_back(*second);

	typename Container::iterator i = arr.begin();
	std::advance(i, 2);
	while (i != arr.end())
	{
		pend.push_back(*i);
		typename Container::iterator next = i;
		++next;
		if (next != arr.end())
			mainChain.push_back(*next);
		else
			break ;
		std::advance(i, 2);
	}
	// Step 4: Insert pend elements to mainChain in Jacobsthal order
	if (pend.size() > 0)
		//simpleInsert(mainChain, pend);
		this->_insertJacobsthalOrder(mainChain, pend);
	arr = mainChain;
}

template <typename Container>
void 	PmergeMe::_insertJacobsthalOrder(Container &mainChain, Container &pend)
{
	if (pend.empty())
		return ;

	int prev_jacobsthal = static_cast<int>(this->_jacobNum(1));
	int inserted_numbers = 0;

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

		while (nbr_of_times > 0 && pend_it != pend.end())
		{
			int value = *pend_it;
			size_t pos = this->_binarySearch(mainChain, value, 0, mainChain.size() - 1);
			typename Container::iterator insert_pos = mainChain.begin();
			std::advance(insert_pos, pos);
		
			mainChain.insert(insert_pos, value);
			pend_it = pend.erase(pend_it);
			if (pend_it != pend.begin() && pend_it != pend.end())
				--pend_it;
			nbr_of_times--;

		}
		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
	}

	while (!pend.empty())
	{
		int value = *pend.begin();
		size_t pos = this->_binarySearch(mainChain, value, 0, mainChain.size() - 1);
		typename Container::iterator insert_pos = mainChain.begin();
		std::advance(insert_pos, pos);	
		mainChain.insert(insert_pos, value);
		pend.erase(pend.begin());
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