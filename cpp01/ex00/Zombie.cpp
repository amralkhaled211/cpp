/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:35:08 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/10 19:23:06 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



Zombie::Zombie(std::string name) : name(name)
{   
}
/* {
	this->name = name;
} */
Zombie::~Zombie()
{
    
    std::cout << this->name << " is dead" << std::endl;
}
void Zombie::announce()
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}