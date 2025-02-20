/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 01:35:56 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/20 13:44:02 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

template <typename Container>
void	printContainer(const Container &arr, const std::string &msg)
{
	if (!msg.empty())
		std::cout << msg << std::endl;
	for (typename Container::const_iterator it = arr.begin(); it != arr.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

template <typename Container>
bool	isSorted(const Container &arr)
{
	if (arr.size() < 2)
		return (true);
	typename Container::const_iterator it = arr.begin();
	typename Container::const_iterator next_it = it;
	++next_it;
	while (next_it != arr.end())
	{
		if (*it > *next_it)
			return (false);
		++it;
		++next_it;
	}
	return (true);
}

std::string	validateInput(std::vector<std::string> av)
{
	for (size_t i = 0; i < av.size(); i++)
	{
		long	n = strtol(av[i].c_str(), NULL, 10);
		if (n == 0 && av[i] != "0")
			return ("non-number arguments not allowed");
		if (av[i][0] == '-')
			return ("negative numbers not allowed");
		if (n > INT_MAX)
			return ("only integer numbers allowed");
	}
	return ("");
}

std::vector<std::string>	argvToStr(int ac, char **av)
{
	std::vector<std::string>	args;
	for (int i = 1; i < ac; i++)
		args.push_back(std::string(av[i]));
	if (args.size() == 1)
	{
		std::vector<std::string>	split;
		std::string word;
		std::stringstream ss(args[0]);
		while (getline(ss, word, ' '))
		{
			if(!word.empty())
				args.push_back(word);
		}
		return (split);
	}
	return (args);
}
template <typename Container>
Container	initContainer(std::vector<std::string> &args)
{
	Container arr;
	for (size_t i = 0; i < args.size(); i++)
		arr.push_back(atoi(args[i].c_str()));
	return (arr);
}

int	main(int ac, char **av)
{
	if (ac < 2)
		return (std::cerr << "Error: usage: ./PmergeMe <numbers>" << std::endl, 1);

	std::vector<std::string>	args = argvToStr(ac, av);
	std::string	stat = validateInput(args);
	if (!stat.empty())
	{
		std::cerr << "Error: " << stat << std::endl;
		return (1);
	}
	
	std::vector<int>	print_vec = initContainer<std::vector<int> >(args);
	std::cout << "Before (" << print_vec.size() << " num): ";
	for (std::vector<int>::iterator it = print_vec.begin(); it != print_vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	PmergeMe merger;

	clock_t				vec_start = clock();
	std::vector<int>	vec = initContainer<std::vector<int> >(args);
	merger.sortVector(vec);
	clock_t				vec_end = clock();
	double				vec_time = static_cast<double>(vec_end - vec_start);

	clock_t				lst_start = clock();
	std::list<int>		lst = initContainer<std::list<int> >(args);
	merger.sortList(lst);
	clock_t				lst_end = clock();
	double				lst_time = static_cast<double>(lst_end - lst_start);

	std::cout << YELLOW << "After  (" << vec.size() << " num): ";
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << " ";
	std::cout << RESET << std::endl;
	std::cout << std::endl;
	
	if (isSorted(vec))
		std::cout << GREEN << "SORTED: OK" << RESET << std::endl;
	else
		std::cout << RED << "SORTED: NOK" << RESET << std::endl;
	std::cout << std::endl;
	
	std::string	vec_color = RED;
	std::string	lst_color = CYAN;
	if (vec_time < lst_time)
	{
		vec_color = CYAN;
		lst_color = RED;
	}
	std::cout << "Time to process a range of " << print_vec.size() << " elements with " << vec_color
		<< "std::vector: " << std::fixed << std::setprecision(6) << vec_time << RESET << std::endl;
	std::cout << "Time to process a range of " << print_vec.size() << " elements with " << lst_color
		<< "std::list  : " << std::fixed << std::setprecision(6) << lst_time << RESET << std::endl;
	
	return (0);	
}
