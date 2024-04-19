/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:59:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/19 16:08:26 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
	max = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::prompt(void)
{
	std::cout << "This is your phonebook, enter your command:" << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	int	i;

	i = max;
	if (max > 7)
	{
		i = oldest;
		oldest++;
		if (oldest > 7)
			oldest = 0;
	}
	contact[i].fill_info();
	max++;
	return ;
}