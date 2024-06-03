/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgomez-r <pgomez-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:16:28 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/31 11:45:10 by pgomez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	std::cout << "[ ScavTrap ] default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->_hitPts = 100;
	this->_energyPts = 50;
	this->_attackDmg = 20;
	std::cout << "[ ScavTrap ] constructor with name " << name << " called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &src){
	*this = src;
	std::cout << "[ ScavTrap ] copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "[ ScavTrap ] " << this->_name << " destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &rhs){
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
	return (*this);
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energyPts < 1)
	{
		std::cout << "[ ScavTrap ] " << this->_name << " has no energy left!" << std::endl;
		return ;
	}
	this->_energyPts--;
	std::cout << "[ ScavTrap ] " << this->_name << " attacks " << target << " causing "
		<< this->_attackDmg << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void){
	std::cout << "[ ScavTrap ] " << this->_name << ": \"HOLD THE DOOR, HOLD DOOR...HODOR...\"" << std::endl;
}
