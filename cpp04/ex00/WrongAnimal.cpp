/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:35 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:43:28 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void )
{
	this->_type = "WrongAnimal";
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( WrongAnimal const & src )
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal( void )
{
	std::cout << "WrongAnimal Destructor called" << std::endl;
}

std::string WrongAnimal::getType( void ) const
{
	return this->_type;
}

void WrongAnimal::makeSound( void ) const
{
	std::cout << "WrongAnimal Sound" << std::endl;
}

