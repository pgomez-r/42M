/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:59:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/25 17:51:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	max = 0;
	oldest = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::prompt(void)
{
	std::cout << "|| ADD || SEARCH || EXIT ||" << std::endl;
	std::cout << "|| Type your command...  ||" << std::endl;
	return ;
}

void	PhoneBook::add(void)
{
	int	i;

	i = max;
	if (i > 7)
	{
		i = oldest;
		oldest++;
		if (oldest > 7)
			oldest = 0;
	}
	contact[i].fill_info(i);
	max++;
	return ;
}

int	PhoneBook::search(void)
{
	int			i;
	std::string	str;

	i = -1;
	std::cout << std::setw(10) << std::right << "INDEX" << " | ";
	std::cout << std::setw(10) << std::right << "NAME" << " | ";
	std::cout << std::setw(10) << std::right << "LASTNAME" << " | ";
	std::cout << std::setw(10) << std::right << "NICKNAME" << std::endl;
	while (++i < 8)
		contact[i].preview();
	std::cout << "Please, enter contact index to display:" << std::endl;
	std::cin >> i;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (std::cout << "Error: invalid input for index search" << std::endl, 1);
	}
	if (i < 0 || i > 7)
		return (std::cout << "Error: index out of range" << std::endl, 1);
	contact[i].display_all();
	return (0);
}
