/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fordJohnsonExample.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:43:11 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/16 14:14:01 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// Function to generate Jacobsthal number
long jacobNum(long n)
{
	return (round((pow(2, n + 1) + pow(-1, n)) / 3));
}

size_t binarySearch(const std::vector<int>& mainChain, int value, size_t left, size_t right)
{
	while (left <= right)
	{
		size_t mid = left + (right - left) / 2;
		if (mainChain[mid] < value)
			left = mid + 1;
		else
		{
			if (mid == 0)
				break ; // Avoid underflow
			right = mid - 1;
		}
	}
	return (left);
}

// Insert elements in Jacobsthal order
// This function will be called to insert numbers from pend to main chain
void insertJacobsthalOrder(std::vector<int>& mainChain, std::vector<int>& pend)
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
		std::vector<int>::iterator pend_it = pend.begin() + (jacobsthal_diff - 1);
		std::vector<int>::iterator bound_it = mainChain.begin() + (curr_jacobsthal + inserted_numbers);

		while (nbr_of_times)
		{
			int value = *pend_it;
			size_t pos = binarySearch(mainChain, value, 0, mainChain.size() - 1);
			std::vector<int>::iterator inserted = mainChain.insert(mainChain.begin() + pos, value);

			nbr_of_times--;
			pend_it = pend.erase(pend_it);
			if (pend_it != pend.begin())
				pend_it--;

			// Handle offset logic
			offset += (inserted - mainChain.begin()) == (curr_jacobsthal + inserted_numbers);
			bound_it = mainChain.begin() + (curr_jacobsthal + inserted_numbers - offset);
		}

		prev_jacobsthal = curr_jacobsthal;
		inserted_numbers += jacobsthal_diff;
		offset = 0;
	}

	// Insert the first element (if any)
	if (!pend.empty())
	{
		int value = pend[0];
		size_t pos = binarySearch(mainChain, value, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, value);
	}
}

// Ford-Johnson (Merge-Insertion Sort)
void fordJohnsonSort(std::vector<int>& arr)
{
	if (arr.size() < 2)
		return ;

	// Step 1: Pair elements and sort each pair
	for (size_t i = 0; i < arr.size() - 1; i += 2)
	{
		if (arr[i] > arr[i + 1])
			std::swap(arr[i], arr[i + 1]);
	}

	// Step 2: Recursively sort the pairs by their larger element
	if (arr.size() > 2)
	{
		std::vector<int>	largerElements;
		for (size_t i = 1; i < arr.size(); i += 2)
			largerElements.push_back(arr[i]);
		fordJohnsonSort(largerElements);

		// Rebuild the array based on sorted larger elements
		std::vector<int>	sortedArr;
		for (size_t i = 0; i < largerElements.size(); ++i)
		{
			sortedArr.push_back(arr[2 * i]);     	// Smaller element of the pair
			sortedArr.push_back(largerElements[i]); // Larger element of the pair
		}
		if (arr.size() % 2 != 0)
			sortedArr.push_back(arr.back()); // Add the last odd element
		arr = sortedArr;
	}

	// Step 3: Create the main chain and pend
	std::vector<int> mainChain = {arr[0], arr[1]}; // Start with the first pair
	std::vector<int> pend;
	for (size_t i = 2; i < arr.size(); i += 2)
	{
		pend.push_back(arr[i]); // Smaller elements of the remaining pairs
		if (i + 1 < arr.size())
			mainChain.push_back(arr[i + 1]); // Larger elements of the remaining pairs
	}
	// Step 4: Insert pend elements to mainChain in Jacobsthal order
	insertJacobsthalOrder(mainChain, pend);
	arr = mainChain;
}

int main()
{
	std::vector<int> numbers = {6, 2, 11, 0, 17, 9, 18, 14, 19, 5, 12, 12, 13};
	std::cout << "Vector size: " << numbers.size() << std::endl;

	std::cout << "Original vector: ";
	for (int num : numbers)
		std::cout << num << " ";
	std::cout << std::endl;

	// Sort using Ford-Johnson algorithm
	fordJohnsonSort(numbers);

	std::cout << "Sorted vector:   ";
	for (int num : numbers)
		std::cout << num << " ";
	std::cout << std::endl;

	return (0);
}
