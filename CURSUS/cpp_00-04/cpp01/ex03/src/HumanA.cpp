/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:08:39 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 12:57:49 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon){
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
		std::cout << this->name << " attacks with their imagination! (empty " " weapon provided...)" << std::endl;
}
