/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:30:40 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 23:34:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO Check weird uses!
// TODO Decide one file or using class - remove files if needed

//#include "../inc/FileReplace.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
    std::ifstream   infile;
	std::ofstream   outfile;
    std::string     outfileMame;

	std::string     target;
	std::string     swap;
	std::string     temp;
	
    int		    	i;

    if (ac != 4)
    {
        return (std::cout << "Error: usage: ./ft_replace <filename> <s1> <s2>" << std::endl, 1);
    }
    target = av[2];
    swap = av[3];
    infile.open(av[1]);
    outfileMame = av[1];
    outfileMame = outfileMame + ".replace";
	outfile.open(outfileMame.c_str());
	if(!infile.is_open() || !outfile.is_open())
	{
        return (std::cout << "Error: cannot open file" << std::endl, 1);
    }
	if (std::getline(infile, temp, '\0'))
	{
		while ((i = temp.find(target)) != -1)
		{
            temp.erase(i, target.length());
			temp.insert(i, swap);
		}
		outfile << temp;
	}
	else	
	{
        std::cout << "Error: file is empty" << std::endl;
    }
	infile.close();
	outfile.close();
    return (0);
}
