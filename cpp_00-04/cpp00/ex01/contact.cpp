/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:58:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/21 23:47:32 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

Contact::Contact(void)
{
	std::cout << "(Contact constructor called)" << std::endl;
	this->index = -1;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "(Contact destructor called)" << std::endl;
	return ;
}

int	ft_setIndent(std::string str)
{
	int	i;
	int	set;

	set = 10;
	i = 0;
	while (str[i] && i < 10)
	{
		if (static_cast<unsigned char>(str[i]) > 127)
			set++;
		i++;
	}
	return (set);
}

void	Contact::fill_info(int i)
{
	std::cout << "Enter the information of the new contact..." << std::endl;
	std::cout << "First name: ";
	std::getline(std::cin, this->name);
	std::cout << "Last name: ";
	std::getline(std::cin, this->lastName);
	std::cout << "Nickname: ";
	std::getline(std::cin, this->nickname);
	std::cout << "Phone number: ";
	std::getline(std::cin, this->phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, this->darkestSecret);
	this->index = i;
	std::cout << "Contact info added" << std::endl;
}

void	Contact::preview(void)
{
	if (this->index != -1)
	{
		std::cout << std::setw(10) << std::right << this->index << " | ";
		std::cout << std::setw(ft_setIndent(this->name)) << std::right << this->name << " | ";
		std::cout << std::setw(ft_setIndent(this->lastName)) << std::right << this->lastName << " | ";
		std::cout << std::setw(ft_setIndent(this->nickname)) << std::right << this->nickname << std::endl;
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
