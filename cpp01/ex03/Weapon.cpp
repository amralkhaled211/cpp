/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:02:23 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 11:08:13 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
	this->type = type;
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& newType)
{
	type = newType;
}