/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:51 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/24 12:47:23 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

int main()
{
	ClapTrap	player("Rick");
	ScavTrap	npc("Robot Morty");

	player.attack("Robot Morty");
	npc.takeDamage(player.getAttackDmg());
	npc.attack("Rick");
	player.takeDamage(npc.getAttackDmg());
	npc.beRepaired(20);
	std::cout << "Robot Morty has " << npc.getEnergyPts() << " energy points left and "
		<< npc.getHitPts() << " hit points" << std::endl;
	return (0);
}
