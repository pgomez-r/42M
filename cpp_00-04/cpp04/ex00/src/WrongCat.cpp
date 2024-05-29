/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:25:06 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 04:45:08 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongCat.hpp"

WrongCat::WrongCat(void) : Animal("WrongCat"){
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &src) : Animal(src){
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	this->type = rhs.type;
	return (*this);
}
