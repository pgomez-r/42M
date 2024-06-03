/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:51 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/31 11:53:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

int main()
{
	ClapTrap	player("Rick");
	ScavTrap	npc("Robot Morty");
	FragTrap	frag("Pickle Rick");

	std::cout << std::endl;
	player.attack("Robot Morty");
	npc.takeDamage(player.getAttackDmg());
	npc.attack("Rick");
	player.takeDamage(npc.getAttackDmg());
	
	std::cout << std::endl;
	frag.attack("Robot Morty");
	npc.takeDamage(frag.getAttackDmg());
	npc.attack("Pickle Rick");
	frag.takeDamage(npc.getAttackDmg());
	npc.beRepaired(20);
	
	std::cout << std::endl;
	std::cout << "Robot Morty has " << npc.getEnergyPts() << " energy points left and "
		<< npc.getHitPts() << " hit points" << std::endl;
	std::cout << "Pickle Rick has " << frag.getEnergyPts() << " energy points left and "
		<< frag.getHitPts() << " hit points" << std::endl;
	std::cout << std::endl;

	frag.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
