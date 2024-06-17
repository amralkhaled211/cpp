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

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::name = name + "_clap_name"; 
	this->hitpoints = FragTrap::hitpoints;
	this->energyPoints = ScavTrap::energyPoints;
	this->attackDamage = FragTrap::attackDamage;
	std::cout << "DiamondTrap pram constructor is called " << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->_name << " and my ClapTrap name is " << this->ClapTrap::name << std::endl;
}