/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:34:32 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/30 11:43:34 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

int	main(void)
{
	std::string	input;

	std::cout << "---   TEST [1]   ---   CREATE ZOMBIE ON THE STACK   ---" << std::endl;
	std::cout << "--- (Declaring the zombie as a local variable in our main) ---" << std::endl;
	std::cout << "Insert zombie name: ";
	std::cin >> input;
	
	Zombie	walkz(input);
	walkz.announce();
	
	std::cout << "---   TEST [2]   ---   CREATE ZOMBIE ON THE HEAP   ---" << std::endl;
	std::cout << "--- (Declaring the zombie with NEW to allocate the variable) ---" << std::endl;
	std::cout << "Insert zombie name: ";
	std::cin >> input;
	
	Zombie	*walky;
	walky = newZombie(input);
	walky->announce();
	
	std::cout << "---   TEST [3]   ---   USING THE FUNCTION randomChump()   ---" << std::endl;
	std::cout << "--- (Creates a zombie on the stack, name it, announces and dies when function finishes) ---" << std::endl;
	std::cout << "Insert zombie name: ";
	std::cin >> input;
	randomChump(input);
	
	std::cout << "---   ALL TESTS ARE DONE  ---" << std::endl;
	std::cout << "--- Now all zombies must die! ---" << std::endl;
	delete walky;
	return (0);
}
