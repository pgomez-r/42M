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
	std::cout << "Contact constructor called" << std::endl;
	this->index = -1;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

void	Contact::fill_info(int i)
{
	std::cout << "Enter the information of the new contact" << std::endl;
	std::cout << "First name:" << std::endl;
	std::getline(std::cin, this->name);
	std::cout << "Last name:" << std::endl;
	std::getline(std::cin, this->lastName);
	std::cout << "Nickname:" << std::endl;
	std::getline(std::cin, this->nickname);
	std::cout << "Phone number:" << std::endl;
	std::getline(std::cin, this->phoneNumber);
	std::cout << "Darkest secret:" << std::endl;
	std::getline(std::cin, this->darkestSecret);
	this->index = i;
	std::cout << "Contact info added" << std::endl;
}

void	Contact::preview(void)
{
	if (this->index != -1)
	{
		std::cout << this->index << "| ";
		std::cout << this->name << "| ";
		std::cout << this->lastName << "| ";
		std::cout << this->nickname << "|" << std::endl;
	}
	return ;
}

int	Contact::display_all(void)
{
	if (this->index == -1)
		return (std::cout << "No contact in this index" << std::endl, 1);
	std::cout << this->name << std::endl;
	std::cout << this->lastName << std::endl;
	std::cout << this->nickname << std::endl;
	std::cout << this->phoneNumber << std::endl;
	std::cout << this->darkestSecret << std::endl;
	return (0);
}
