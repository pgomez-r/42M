/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:59:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/30 16:28:45 by pgomez-r         ###   ########.fr       */
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
	std::cout << "||-----------------------||" << std::endl;
	std::cout << "||    FT_PHONEBOOK_42    ||" << std::endl;
	std::cout << "|| ADD || SEARCH || EXIT ||" << std::endl;
	std::cout << "|| Type your command...  ||" << std::endl;
	std::cout << "||-----------------------||" << std::endl;
	return ;
}

int	PhoneBook::add(void)
{
	int	i;
	int	ret;

	ret = 0;
	i = max;
	if (i > 7)
	{
		i = oldest;
		oldest++;
		if (oldest > 7)
			oldest = 0;
	}
	ret = contact[i].fill_info(i);
	max++;
	return (ret);
}

int	PhoneBook::search(void)
{
	int			i;
	std::string	str;

	if (!max)
		return (std::cout << "There isn't any contact in this phonebook yet!" << std::endl, 0);
	i = -1;
	std::cout << std::setw(10) << std::right << "INDEX" << " | ";
	std::cout << std::setw(10) << std::right << "NAME" << " | ";
	std::cout << std::setw(10) << std::right << "LASTNAME" << " | ";
	std::cout << std::setw(10) << std::right << "NICKNAME" << std::endl;
	while (++i < 8)
		contact[i].preview();
	std::cout << "Please, enter contact index to display [0 to 7]:" << std::endl;
	std::cin >> i;
	if (std::cin.fail() || (i < 0 || i > 7))
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return (std::cout << "Error: invalid input for index search" << std::endl, 0);
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	contact[i].display_all();
	return (0);
}
