/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:17:50 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/05/30 11:43:46 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	Zombie		*horde;
	int			i;
	int			size;
	std::string	name;

	std::cout << "WELCOME TO ZOMBIE HORDE GENERATOR!" << std::endl;
	std::cout << "How big do you want your horde to be?" << std::endl;
	std::cout << "Horde size: ";
	std::cin >> size;
	std::cout << "What's the name of your walkers?" << std::endl;
	std::cout << "Zombies name: ";
	std::cin >> name;
	horde = zombieHorde(size, name);
	std::cout << "Zombie horde is ready, let's hear them announce!" << std::endl;
	for (i = 0; i < size; i++)
		horde[i].announce();
	std::cout << "They have done their thing, time to die (again)" << std::endl;
	delete [] horde;
	return (0);
}
