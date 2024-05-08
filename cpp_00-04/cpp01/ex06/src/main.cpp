/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 03:47:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/08 04:12:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: break and compilation?!

#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
    Harl        rick;
    std::string input;

    if (ac != 2)
    {
        return (std::cout << "Error: usage: only one argument allowed" << std::endl, 1);
    }
    input = av[1];
    rick.complain(input);
    return (0);
}
