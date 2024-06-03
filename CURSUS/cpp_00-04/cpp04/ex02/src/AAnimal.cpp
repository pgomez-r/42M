/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:12 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 17:52:22 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AAnimal.hpp"

AAnimal::AAnimal(void){
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type){
	this->type = type;
	std::cout << "Animal constructor called with type: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal &src){
	*this = src;
	std::cout << "Animal copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void){
	std::cout << "Animal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &rhs){
	this->type = rhs.type;
	return (*this);
}

void		AAnimal::makeSound(void) const{
	std::cout << "Hoo hoo! Hoot hoot! Whooo!..." << std::endl;
}

std::string	AAnimal::getType(void) const{
	return (this->type);
}
