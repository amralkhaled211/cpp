/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:39:36 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 10:00:55 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
    // empty constructor
}

void Zombie::setName(std::string name)
{
    this->name = name;
}
 
Zombie::Zombie(std::string name) 
{
	this->name = name;
}

Zombie::~Zombie()
{
    std::cout << this->name << " is dead" << std::endl;
}

void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}