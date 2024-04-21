/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:07:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/21 21:58:41 by pgomez-r         ###   ########.fr       */
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
		return (std::cout << "Usage error" << std::endl, 1);
	std::cout << "Welcome to your phonebook" << std::endl;
	while (!flag)
	{
		agenda.prompt();
		std::getline(std::cin, input);
		flag = ft_action(input, agenda);
	}
	return (0);
}