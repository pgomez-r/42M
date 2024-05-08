/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 02:19:46 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 03:40:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(void)
{
    Harl        rick;
    std::string input;
    int         flag = 0;

    std::cout << "WELCOME TO RICK SANCHEZ CATCH PHRASES SELECTOR" << std::endl;
    while (!flag)
    {
        std::cout << "Please type a level [ DEBUG | INFO | WARNING | ERROR ] or EXIT to close the program..." << std::endl;
        std::cin >> input;
        rick.complain(input);
        if (!input.compare("EXIT") || std::cin.eof())
        {
            flag = 1;
            std::cout << "Bye Morty! ... And that's the waaaaay the news goes!" << std::endl;
        }
    }
    return (0);    
}
