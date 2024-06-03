/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 20:07:25 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/04/30 17:07:27 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include "contact.hpp"

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
	while (42)
	{
		std::getline(std::cin, *dst);
		if (std::cin.eof())
			return (std::cout << "Goodbye, happy coding!" << std::endl, 1);
		else if (dst->empty())
			std::cout << "Empty input, please try again" << std::endl;
		else if (mode == 1 && !ft_allDigit(*dst))
			std::cout << "Phone number must contain only number, please try again" << std::endl;
		else
			return (0);
	}
}

int	ft_action(std::string input, PhoneBook &agenda)
{
	int	ret;

	ret = 0;
	if (input == "ADD")
		ret = agenda.add();
	else if (input == "SEARCH")
		ret = agenda.search();
	else if (input == "EXIT")
		return (std::cout << "Goodbye, happy coding!" << std::endl, 1);
	else
		std::cout << "Error: Command not found" << std::endl;
	return (ret);
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
		flag = ft_readInput(&input, 0);
		if (!flag)
			flag = ft_action(input, agenda);
		std::cin.clear();
	}
	return (0);
}
