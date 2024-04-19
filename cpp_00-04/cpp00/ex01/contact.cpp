/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:58:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/19 17:19:45 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include "phonebook.hpp"

Contact::Contact(void)
{
	std::cout << "Contact constructor called" << std::endl;
	return ;
}

Contact::~Contact(void)
{
	std::cout << "Contact destructor called" << std::endl;
	return ;
}

void	Contact::fill_info(void)
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
}
