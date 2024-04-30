/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:58:59 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/30 17:06:21 by pgomez-r         ###   ########.fr       */
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

int	Contact::fill_info(int i)
{
	int	ret;

	ret = 0;
	std::cout << "Enter the information of the new contact..." << std::endl;
	std::cout << "First name    : ";
	ret = ft_readInput(&this->name, 0);
	if (!ret && std::cout << "Last name     : ")
		ret = ft_readInput(&this->lastName, 0);
	if (!ret && std::cout << "Nickname      : ")
		ret = ft_readInput(&this->nickname, 0);
	if (!ret && std::cout << "Phone number  : ")
		ret = ft_readInput(&this->phoneNumber, 1);
	if (!ret && std::cout << "Darkest secret: ")
		ret = ft_readInput(&this->darkestSecret, 0);
	this->index = i;
	if (!ret)
		std::cout << "Contact info added!" << std::endl;
	return (ret);
}

void	Contact::preview(void)
{
	if (this->index != -1)
	{
		std::cout << std::setw(10) << std::right << this->index << " | ";
		std::cout << std::setw(10) << std::right << ft_formatStr(this->name) << " | ";
		std::cout << std::setw(10) << std::right << ft_formatStr(this->lastName) << " | ";
		std::cout << std::setw(10) << std::right << ft_formatStr(this->nickname) << std::endl;
	}
	return ;
}

int	Contact::display_all(void)
{
	if (this->index == -1)
		return (std::cout << "No contact in this index" << std::endl, 1);
	std::cout << "Name          : " << this->name << std::endl;
	std::cout << "Lastname      : " << this->lastName << std::endl;
	std::cout << "Nickname      : " << this->nickname << std::endl;
	std::cout << "Phonenumber   : " << this->phoneNumber << std::endl;
	std::cout << "Darkest secret: " << this->darkestSecret << std::endl;
	return (0);
}

std::string	Contact::ft_formatStr(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0 , 9) + ".");
	return (str);	
}
