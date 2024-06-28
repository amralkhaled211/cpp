/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 11:11:23 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 16:08:57 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat Constructor called" << std::endl;
	this->type = "Cat";
	
	try
	{
		this->brain = new Brain();
	}
	catch (std::bad_alloc &e)
	{
		std::cerr << "Memory allocation failed: " << e.what() << std::endl;
	}
}

Cat::Cat(const Cat &copy) : AAnimal(copy), brain(new Brain(*copy.brain))
{
	std::cout << "Cat Copy Constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &copy)
{
	std::cout << "Cat operator called" << std::endl;
	if (this != &copy)
	{
		AAnimal::operator=(copy);
		delete this->brain;
		this->brain = new Brain(*copy.brain);//protcet
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat Destructor called" << std::endl;
	delete this->brain;
}

void Cat::makeSound() const
{
	std::cout << "Miaou Miaou" << std::endl;
}
