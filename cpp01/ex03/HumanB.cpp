 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    HumanB.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:05:37 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/27 15:09:30 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = 0;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
    weapon = &newWeapon;
}

void HumanB::attack() const {
    if (weapon) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    } else {
        std::cout << name << " has no weapon" << std::endl;
    }
}