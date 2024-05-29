/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:15 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 04:21:24 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Dog.hpp"

Dog::Dog(void) : Animal("Dog"){
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &src) : Animal(src){
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog(void){
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound(void) const{
	std::cout << "Woooff! ₍ᐢ•`ᴥ´•ᐢ₎" << std::endl;
}
