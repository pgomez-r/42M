/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:51 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/31 11:46:26 by pgomez-r         ###   ########.fr       */
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
	npc.guardGate();
	std::cout << "Robot Morty has " << npc.getEnergyPts() << " energy points left and "
		<< npc.getHitPts() << " hit points" << std::endl;
	return (0);
}
