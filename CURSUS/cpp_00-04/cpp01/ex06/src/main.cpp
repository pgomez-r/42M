/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 03:47:45 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 12:12:20 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Harl.hpp"

int main(int ac, char **av)
{
    Harl        rick;
    std::string input;

    if (ac != 2)
    {
        return (std::cout << "Error: usage: exactly just one argument needed" << std::endl, 1);
    }
    input = av[1];
    rick.complain(input);
    return (0);
}
