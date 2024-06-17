/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:04:45 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 11:25:30 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}