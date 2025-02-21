/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:51 by pgruz11           #+#    #+#             */
/*   Updated: 2025/02/21 16:16:58 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

int main()
{
	ClapTrap	player("Rick");
	ClapTrap	npc("Morty");
	int			i;

	player.attack("Morty");
	npc.takeDamage(player.getAttackDmg());
	std::cout << "Morty has " << npc.getHitPts() << " hits points left" << std::endl;
	for (i = 0; i < 5; i++)
	{
		player.attack("to its own imagination...");
		player.beRepaired(10);
	}
	std::cout << "Rick has " << player.getEnergyPts() << " energy points left and "
		<< player.getHitPts() << " hit points" << std::endl;
	return (0);
}
