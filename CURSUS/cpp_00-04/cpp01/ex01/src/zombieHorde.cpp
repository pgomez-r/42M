/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 22:23:38 by pgomez-r          #+#    #+#             */
/*   Updated: 2024/05/06 22:23:40 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
    Zombie  *horde;
    int     i;

    horde = new Zombie[N];
    i = -1;
    while (++i < N)
        horde[i].nameSetter(name);
    return (horde);
}
