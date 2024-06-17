/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:50:42 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 14:34:29 by amalkhal         ###   ########.fr       */
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
	std::cout << "ClapTrap Name constructor called" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &clap)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = clap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clap)
{
    if (this != &clap) {
        std::cout << "ClapTrap Assignment operator called" << std::endl;
        this->name = clap.name;
        this->hitpoints = clap.hitpoints;
        this->energyPoints = clap.energyPoints;
        this->attackDamage = clap.attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is out of energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " attacks " << target << std::endl;
	energyPoints -= 1;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitpoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " takes " << amount << " points of damage!" << std::endl;
	hitpoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitpoints >= 10)
	{
		std::cout << "ClapTrap " << name << " is already at full health" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << name << " is being repaired for " << amount << " points of health!" << std::endl;
	hitpoints += amount;
}

