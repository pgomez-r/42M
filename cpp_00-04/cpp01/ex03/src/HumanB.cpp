/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:08:38 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 12:59:45 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanB.hpp"

HumanB::HumanB(std::string name)
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
    if (this->weapon == NULL)
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
    else if (this->weapon->getType() == "")
        std::cout << this->name << " attacks with their imagination! (empty " " weapon provided...)" << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}
