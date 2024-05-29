/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 03:01:14 by codespace         #+#    #+#             */
/*   Updated: 2024/05/29 04:09:19 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Cat.hpp"

Cat::Cat(void) : Animal("Cat"){
	std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat &src) : Animal(src){
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat(void){
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound(void) const{
	std::cout << "Meeeeoow, meowtherf***er!! (^._.^)ﾉ" << std::endl;
}
