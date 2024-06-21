/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:11 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 16:17:46 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog Constructor called" << std::endl;
	try
	{
		this->brain = new Brain();
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Wouf Wouf" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), brain(new Brain(*copy.brain))
{
    std::cout << "Dog Copy Constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &copy)
{
    std::cout << "Dog operator called" << std::endl;
    if (this != &copy)
    {
        Animal::operator=(copy); // Call the base class assignment operator
        delete this->brain; // Delete the old Brain object
        this->brain = new Brain(*copy.brain); // Deep copy the Brain object
    }
    return (*this);
}
