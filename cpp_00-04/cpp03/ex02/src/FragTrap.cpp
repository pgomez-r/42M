/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 12:11:43 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/31 11:45:37 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "{ FragTrap } default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	this->_hitPts = 100;
	this->_energyPts = 100;
	this->_attackDmg = 30;
	std::cout << "{ FragTrap } constructor with name " << name << " called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &src){
	*this = src;
	std::cout << "{ FragTrap } copy constructor called" << std::endl;
}

FragTrap::~FragTrap(){
	std::cout << "{ FragTrap } " << this->_name << " destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &rhs){
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
	return (*this);
}

void	FragTrap::highFivesGuys(void){
	std::cout << "Let's go Mortys, high fives!" << std::endl;
}
