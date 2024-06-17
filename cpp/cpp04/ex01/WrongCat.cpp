/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:43:40 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:44:17 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"


WrongCat::WrongCat( void )
{
	this->_type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat( WrongCat const & src )
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat( void )
{
	std::cout << "WrongCat Destructor called" << std::endl;
}

std::string WrongCat::getType( void ) const
{
	return this->_type;
}

void WrongCat::makeSound( void ) const
{
	std::cout << "WrongCat Sound" << std::endl;
}
