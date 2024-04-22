/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 11:59:13 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/21 23:44:55 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void)
{
	std::cout << "PhoneBook constructor called" << std::endl;
	max = 0;
	oldest = 0;
	return ;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructor called" << std::endl;
	return ;
}

void	PhoneBook::prompt(void)
{
	std::cout << "Enter your command:" << std::endl;
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

//Display all contacts with info-> index, first name, last name, nickname
//Column must be MAX 10 chars,  ’|’ separates them 
//Text must be right-aligned. If text is longer than the column, it must be truncated 
//and the last displayable character must be replaced by a dot (’.’).

//Prompt user for index of the entry to display. If the index is out of range or wrong, 
//define a relevant behavior. Otherwise, display (ALL?) contact information, one field per line.
int	PhoneBook::search(void)
{
	int			i;
	std::string	str;

	i = -1;
	while (++i < 8)
		contact[i].preview();
	std::cout << "Please, select contact index to display:" << std::endl;
	std::getline(std::cin, str);
	for (i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (std::cout << "Error: wrong input for SEARCH command" << std::endl, 1);
	}
	//change stoi for ft_atoi or a different allowed function/method
	i = std::stoi(str);
	if (i > 7)
		return (std::cout << "Error: index out of range" << std::endl, 1);
	contact[i].display_all();
	return (0);
}
