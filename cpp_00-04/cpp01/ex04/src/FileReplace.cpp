/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FileReplace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 04:36:54 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 22:36:02 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FileReplace.hpp"

FileReplace::FileReplace(std::string filePath)
{
	this->inFile = filePath;
	this->outFile = this->inFile + ".replace";
}

FileReplace::~FileReplace()
{
	std::cout << "FileReplace destructor called" << std::endl;
}

void    FileReplace::ftReplace(std::string target, std::string swap)
{
	std::ifstream   src;
	std::ifstream   dst;
	std::string     content;
	size_t			i;

	src.open(this->inFile);
	dst.open(this->outFile);
	if(!src.is_open() || !dst.is_open())
	{
		std::cout << "Error: cannot open file" << std::endl;
		return ;
	}
	if (std::getline(src, content, '\0'))
	{
	}
	else	
		std::cout << "Error: file is empty" << std::endl;
	src.close();
	dst.close();
}
