/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:42:29 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/07 15:28:05 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Pram counstructor called" << std::endl;
	this->hitpoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called" << std::endl;
}

void    ScavTrap::attack(std::string const& target)
{
	if (this->hitpoints == 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and can't attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << " causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoints -= 1;
}

void    ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " has entered in Gate keeper mode" << std::endl;
}

