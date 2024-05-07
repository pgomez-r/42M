/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:08:38 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 04:25:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{
    std::cout << "HumanB destructor called" << std::endl;
}

void    HumanB::attack(void)
{
    if (this->_weapon != NULL && this->weapon.getType() != "")
        std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
