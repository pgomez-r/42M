/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:08:39 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 04:26:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon)
{
    this->name = name;
    this->weapon = weapon;
}

HumanA::~HumanA()
{
        std::cout << "HumanA destructor called" << std::endl;
}

void    HumanA::attack(void)
{
    if (this->weapon.getType() != "")
        std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
}
