/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 04:25:21 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 17:52:43 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void){
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type){
	this->type = type;
	std::cout << "WrongAnimal constructor called with type: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &src){
	*this = src;
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs){
	this->type = rhs.type;
	return (*this);
}

void		WrongAnimal::makeSound(void) const{
	std::cout << "Ri-bleurghghurrguhrgughrugh...(And some more weird noises...)" << std::endl;
}

std::string	WrongAnimal::getType(void) const{
	return (this->type);
}
