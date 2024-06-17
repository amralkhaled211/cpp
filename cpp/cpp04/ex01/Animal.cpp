/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:17:30 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 15:47:12 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
	this->type = animal.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	this->type = animal.type;
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal Sound" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}