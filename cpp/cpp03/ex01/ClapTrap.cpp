/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:50:42 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/15 20:52:06 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	hitpoints = 10;
	energyPoints = 10;
	attackDamage = 0;
	std::cout << "ClapTrap pram constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	if (this == &clap)
		return;
	*this = clap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
	std::cout << "ClapTrap operator called" << std::endl;
	name = clap.name;
	hitpoints = clap.hitpoints;
	energyPoints = clap.energyPoints;
	attackDamage = clap.attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target
		<< " causing " << attackDamage << " points of damage!" << std::endl;
	energyPoints -= 1;
	std::cout << "ClapTrap " << name << " has " << energyPoints << " energy points left" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return;
	}
	else if (hitpoints < amount)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		hitpoints = 0;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	hitpoints -= amount;
	std::cout << "ClapTrap " << name << " has " << hitpoints << " hitpoints left" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoints >= 10)
	{
		std::cout << "ClapTrap " << name << " is already at full health" << std::endl;
		return;
	}
	else if (hitpoints == 0)
	{
		std::cout << "ClapTrap " << name << " is dead and can't be repaired" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " is being repaired for " << amount << " points of health!" << std::endl;
	hitpoints += amount;
}

