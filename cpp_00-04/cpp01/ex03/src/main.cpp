/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 02:52:46 by codespace         #+#    #+#             */
/*   Updated: 2024/05/07 04:17:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: Check compilation and use
// TODO: When ptr/ref and why?

#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    Weapon  club("crude spike club");
    HumanA  paco("Paco", club);
    HumanB  joaquin("Joaquin");

    std::cout << "--- TEST [1] --- HumanA, HumanB and Weapon declared by default ---" << std::endl;
    paco.attack();
    joaquin.attack();
    
    std::cout << "--- TEST [2] --- HumanB equipped Weapon ---" << std::endl;
    joaquin.setWeapon(&club);
    joaquin.attack();
    
    std::cout << "--- TEST [3] --- WeaponType changed ---" << std::endl;
    club.setType("navajilla de Albacete");
    paco.attack();
    joaquin.attack();
    
    return (0);
}

// // Subject_main
// int main()
// {
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanA bob("Bob", club);
//         bob.attack();
//         club.setType("some other type of club");
//         bob.attack();
//     }
//     {
//         Weapon club = Weapon("crude spiked club");
//         HumanB jim("Jim");
//         jim.setWeapon(club);
//         jim.attack();
//         club.setType("some other type of club");
//         jim.attack();
//     }

//     return 0;
// }
