/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:42:16 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/08 15:12:56 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

// DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
// {
// 	this->_name = name;
// 	this->hitpoints = FragTrap::hitpoints;
// 	this->energyPoints = ScavTrap::energyPoints;
// 	this->attackDamage = FragTrap::attackDamage;
// 	std::cout << "DiamondTrap pram constructor is called " << std::endl;
// }

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
    this->_name = name;
    this->hitpoints = FragTrap::hitpoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    this->ClapTrap::name = name + "_clap_name";
    std::cout << "DiamondTrap pram constructor is called " << std::endl;
}

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& rhs) : ClapTrap(rhs), ScavTrap(rhs), FragTrap(rhs)
{
	std::cout << "DiamondTrap Copy constructor called" << std::endl;
	this->_name = rhs._name;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	// 1. Check for self-assignment
	if (this == &rhs)
		return *this;
	// 2. Call base class assignment operator
	ClapTrap::operator=(rhs);
	this->_name = rhs._name;
	this->ClapTrap::name = rhs._name + "_clap_name";
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}