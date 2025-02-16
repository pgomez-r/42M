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

// Function to generate Jacobsthal sequence up to a given size
// std::vector<size_t> generateJacobsthalSequence(size_t size)
// {
// 	std::vector<size_t> jacobsthal = {0, 1};
// 	while (jacobsthal.size() < size)
// 	{
// 		size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
// 		jacobsthal.push_back(next);
// 	}
// 	return (jacobsthal);
// }

/**
 * @brief: Performs a binary search on an array to find the position where
 * a value should be inserted. It uses a standard binary search algorithm:
 * (1) Calculate the middle index (mid).
 * (2) Compare the middle element with value.
 * (3) Adjust the search range (left and right) based on the comparison.
 * (4) Continue until the correct position is found.
 * @param mainChain the array to look for the correct position
 * @param value the value to insert in the array
 * @param left search range
 * @param right search range
 * @return size_t the index (left) where value should be inserted.
 */
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

	// Step 4: Insert pend elements into the main chain using Jacobsthal order
	// TDO: Jacobsthal order is not currently implemented in this code
	for (size_t i = 0; i < pend.size(); ++i)
	{
		int value = pend[i];
		size_t pos = binarySearch(mainChain, value, 0, mainChain.size() - 1);
		mainChain.insert(mainChain.begin() + pos, value);
	}

	// (!) THIS IS PROBLEMATIC, AS WE DO HANDLE THE OOD NUMBER ABOVE (!)
	// Step 5: Handle the odd element (if any)
	// if (arr.size() % 2 != 0)
	// {
	// 	int oddElement = arr.back();
	// 	size_t pos = binarySearch(mainChain, oddElement, 0, mainChain.size() - 1);
	// 	mainChain.insert(mainChain.begin() + pos, oddElement);
	// }

	// Update the original array with the sorted result
	arr = mainChain;
}

int main()
{
	std::vector<int> numbers = {6, 2, 11, 0, 17, 9, 18, 14, 19, 5, 12};

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

/**
 * Explanation of the Code
 * Pair and Sort:
 *
 * The algorithm starts by pairing elements and sorting each pair so the smaller number comes first.
 * 
 * Recursively Sort Pairs:
 * 
 * The larger elements of the pairs are recursively sorted to build a hierarchy of sorted pairs.
 * 
 * Main Chain and Pend:
 * 
 * The mainChain is initialized with the smallest element and the larger elements of the pairs.
 * 
 * The pend contains the smaller elements of the remaining pairs.
 * 
 * Insert Pend Elements:
 * 
 * Elements from the pend are inserted into the mainChain using binary search to minimize comparisons.
 * 
 * Handle Odd Element:
 * 
 * If there’s an odd element (unpaired), it is inserted into the mainChain using binary search.
 * 
 * Final Sorted Vector:
 * 
 * The mainChain becomes the fully sorted vector. 
 * 
 */