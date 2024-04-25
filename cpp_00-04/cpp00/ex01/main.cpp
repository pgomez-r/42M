/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:07:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/25 17:50:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include "contact.hpp"
#include "phonebook.hpp"

int	ft_action(std::string input, PhoneBook &agenda)
{
	if (input == "ADD")
		agenda.add();
	else if (input == "SEARCH")
		agenda.search();
	else if (input == "EXIT")
		return (std::cout << "Goodbye, happy coding!" << std::endl, 1);
	else
		std::cout << "Error: Command not found" << std::endl;
	return (0);
}

int	main(int ac, char **av)
{
	PhoneBook	agenda;
	std::string	input;
	int			flag;

	flag = 0;
	if (ac > 1)
		return (std::cout << "Usage error, no arguments allowed!" << std::endl, 1);
	std::cout << "Welcome to your phonebook!" << std::endl;
	while (!flag)
	{
		agenda.prompt();
		if (!std::getline(std::cin, input) && std::cin.eof())
			return (std::cout << "Goodbye!" << std::endl, 1);
		if (input.empty())
			continue ;
		flag = ft_action(input, agenda);
	}
	return (0);
}

/**
TODO:
- Protect only digits in phone number
- Protect empty fields when fill_info
- Short with '.' when longer than 10 for preview
- Contact indexes from 1 to 8
- "Error:command not found" after SEARCH - uncomment cin.ignore
*/