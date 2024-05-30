/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 17:52:22 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Animal.hpp"

Animal::Animal(void){
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string type){
	this->type = type;
	std::cout << "Animal constructor called with type: " << type << std::endl;
}

Animal::Animal(const Animal &src){
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal(void){
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &rhs){
	this->type = rhs.type;
	return (*this);
}

void		Animal::makeSound(void) const{
	std::cout << "Hoo hoo! Hoot hoot! Whooo!..." << std::endl;
}

std::string	Animal::getType(void) const{
	return (this->type);
}
