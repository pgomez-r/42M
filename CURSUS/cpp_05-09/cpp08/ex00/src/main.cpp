/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:16:27 by pgomez-r          #+#    #+#             */
/*   Updated: 2025/02/13 12:15:59 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>
#include <set>

int main()
{
	// Test with std::vector
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(-4);
	vec.push_back(5);
	try
	{
		easyFind(vec, -4);
		easyFind(vec, 6);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with std::list
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	try
	{
		easyFind(lst, 20);
		easyFind(lst, 60);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	// Test with std::deque
	std::deque<int> deq;
	deq.push_back(100);
	deq.push_back(200);
	deq.push_back(300);
	deq.push_back(400);
	deq.push_back(500);
	try
	{
		easyFind(deq, 100);
		easyFind(deq, 600);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
