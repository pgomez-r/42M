/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:14 by codespace         #+#    #+#             */
/*   Updated: 2024/05/30 10:57:19 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : AAnimal("Cat"){
	this->_brain = new Brain();
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : AAnimal(src){
	this->_brain = new Brain(*src._brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void){
	delete (this->_brain);
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		delete (this->_brain);
		this->_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Meeeeoow, meowtherf***er!! (^._.^)ﾉ" << std::endl;
}
