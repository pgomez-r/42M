/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:30:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 13:33:48 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ft_replace(char **av)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		outfileMame;

	std::string		target;
	std::string		swap;
	std::string		temp;
	
	int				i;
	int				exit = 0;
	
	target = av[2];
	swap = av[3];
	infile.open(av[1]);
	outfileMame = av[1];
	outfileMame = outfileMame + ".replace";
	if(!infile.is_open())
	{
		return (std::cout << "Error: cannot open file" << std::endl, 1);
	}
	if (std::getline(infile, temp, '\0'))
	{
		if (target != swap)
		{
			while ((i = temp.find(target)) != -1)
			{
				temp.erase(i, target.length());
				temp.insert(i, swap);
			}
		}
			outfile.open(outfileMame.c_str());
			outfile << temp;
	}
	else	
	{
		std::cout << "Error: file is empty" << std::endl;
		exit = 1;
	}
	infile.close();
	outfile.close();
	return (exit);
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (std::cout << "Error: usage: ./ft_replace <filename> <s1> <s2>" << std::endl, 1);
	return (ft_replace(av));
}
