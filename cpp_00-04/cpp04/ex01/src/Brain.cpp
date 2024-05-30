/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 22:16:47 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/30 08:41:30 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Brain.hpp"

Brain::Brain(void){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &src){
	*this = src;
	std::cout << "Brain copy constructor called" << std::endl;	
}

Brain::~Brain(void){
	std::cout << "Brain destructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &rhs){
	int	i;

	if (this != &rhs){
		for (i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

std::string	Brain::getIdeas(void){
	return (*this->ideas);
}

void	Brain::setIdeas(std::string input){
	if (input.length() <= 100)
		*this->ideas = input;
}
