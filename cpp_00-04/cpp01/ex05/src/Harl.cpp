/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:19:44 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 16:12:52 by pgomez-r         ###   ########.fr       */
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
    void (Harl::*refs[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string options[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int i;

    for (i = 0; i < 4; i++)
    {
        if (!options[i].compare(level))
        {
            (this->*refs[i])();
        }
    }
}
