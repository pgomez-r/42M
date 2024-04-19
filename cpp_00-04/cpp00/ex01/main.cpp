/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:07:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/19 13:43:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"

int	ft_action(std::string input, PhoneBook agenda)
{
	if (input == "ADD")
		agenda.add();
	else if (input == "SEARCH")
		agenda.search();
	else if (input == "EXIT")
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	PhoneBook	agenda;
	std::string	input;
	int			flag;

	flag = 0;
	if (ac > 1)
		std::cout << "Usage error" << std::endl;
	//add welcome and usage msg or phoneBook::function
	while (!flag)
	{
		agenda.prompt();
		std::getline(std::cin, input);
		flag = ft_action(input, agenda);
	}
	return (0);
}