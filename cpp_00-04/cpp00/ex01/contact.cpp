/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:58:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/25 18:41:42 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

Contact::Contact(void)
{
	this->index = -1;
	return ;
}

Contact::~Contact(void)
{
}

int	ft_allDigit(std::string str)
{
	int	i;

	i = -1;
	while (++i < str.length())
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}

int	ft_readInput(std::string *dst, int mode)
{
	while (!dst->empty())
	{
		std::getline(std::cin, *dst);
		if (std::cin.eof())
			return (std::cout << "Goodbye!" << std::endl, 1);
		else if (dst->empty())
			std::cout << "Empty field, please insert value" << std::endl;
		else if (mode == 1 && !ft_allDigit(*dst))
			std::cout << "Phone number must contain only number, please try again" << std::endl;
	}
	return (0);
}

void	Contact::fill_info(int i)
{
	std::cout << "Enter the information of the new contact..." << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, this->name);;
	std::cout << "Last name: ";
	std::getline(std::cin, this->lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->darkestSecret);
	this->index = i;
	std::cout << "Contact info added!" << std::endl;
}

void	Contact::preview(void)
{
	if (this->index != -1)
	{
		std::cout << std::setw(10) << std::right << this->index << " | ";
		std::cout << std::setw(10) << std::right << this->name << " | ";
		std::cout << std::setw(10) << std::right << this->lastName << " | ";
		std::cout << std::setw(10) << std::right << this->nickname << std::endl;
	}
	return ;
}

int	Contact::display_all(void)
{
	if (this->index == -1)
		return (std::cout << "No contact in this index" << std::endl, 1);
	std::cout << "Name: " << this->name << std::endl;
	std::cout << "Lastname: " << this->lastName << std::endl;
	std::cout << "Nickname: " << this->nickname << std::endl;
	std::cout << "Phonenumber: " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	return (0);
}
