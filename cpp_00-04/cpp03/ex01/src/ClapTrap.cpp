/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgruz11 <pgruz11@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 23:04:42 by pgruz11           #+#    #+#             */
/*   Updated: 2024/05/24 12:46:16 by pgruz11          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->_hitPts = 10;
	this->_energyPts = 10;
	this->_attackDmg = 0;
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	this->_name = name;
	this->_hitPts = 10;
	this->_energyPts = 10;
	this->_attackDmg = 0;
	std::cout << "ClapTrap constructor with name " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap " << this->_name << " destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &src){
	*this = src;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &rhs){
	this->_name = rhs._name;
	this->_hitPts = rhs._hitPts;
	this->_energyPts = rhs._energyPts;
	this->_attackDmg = rhs._attackDmg;
	return (*this);
}

void	ClapTrap::attack(const std::string &target){
	if (this->_energyPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
		return ;
	}
	this->_energyPts--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing "
		<< this->_attackDmg << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount){
	if (this->_hitPts <= amount)
		std::cout << "ClapTrap " << this->_name << " is dead!" << std::endl;
	else
	{
		this->_hitPts -= amount;
		std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;	
	}
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPts < 1)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy left!" << std::endl;
		return ;
	}
	this->_energyPts--;
	this->_hitPts += amount;
	std::cout << "ClapTrap " << this->_name << " repairs itself " << amount << " hit points!" << std::endl;
}

unsigned int		ClapTrap::getHitPts(void){
	return (this->_hitPts);
}

unsigned int		ClapTrap::getEnergyPts(void){
	return (this->_energyPts);
}

unsigned int		ClapTrap::getAttackDmg(void){
	return (this->_attackDmg);
}
