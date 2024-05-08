/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:19:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 04:11:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I'm Pickle Rick!" << std::endl;
    std::cout << std::endl;
}
 
void    Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "Lick, lick, lick my b**ls! Ha ha ha, yeah! Say that all the time!" << std::endl;
    std::cout << std::endl;
}

void    Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I want that Mulan McNugget sauce, Morty!" << std::endl;
    std::cout << std::endl;
}

void    Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "That's why I always say: shum-shum-schlippety-dop!" << std::endl;
    std::cout << std::endl;
}

void    Harl::complain(std::string level)
{
    std::string options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int         i = 0;

    while (i < 4 && options[i].compare(level))
        i++;
    switch (i)
    {
        case    0: 
            this->debug();
        case    1: 
            this->info();
        case    2: 
            this->warning();
        case    3: 
            this->error();
            break ;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
