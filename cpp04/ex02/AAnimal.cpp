/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:17:30 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/10 14:25:04 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal()
{
	this->type = "AAnimal";
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type)
{
	this->type = type;
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &animal)
{
	this->type = animal.type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(const AAnimal &animal)
{
	this->type = animal.type;
	std::cout << "AAnimal assignation operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal destructor called" << std::endl;
}

std::string AAnimal::getType() const
{
	return this->type;
}