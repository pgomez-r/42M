/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:08:37 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 04:26:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = setType(type);
}

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called" << std::endl;
}

const std::string   &Weapon::getType(void)
{
    return (this->type);
}

void                Weapon::setType(std::string newType)
{
    this->type = newType;
}
