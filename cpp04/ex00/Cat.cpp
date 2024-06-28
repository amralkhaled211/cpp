/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:23 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:16:22 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat Constructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) : Animal(rhs)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat &rhs)
{
	std::cout << "Cat Assignation Operator called" << std::endl;
	if (this == &rhs)
		return (*this);
	Animal::operator=(rhs);
	return (*this);
}

Cat::~Cat() 
{
	std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
