/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:11 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:14:34 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : Animal(rhs)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &rhs)
{
	std::cout << "Dog Assignation Operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}

