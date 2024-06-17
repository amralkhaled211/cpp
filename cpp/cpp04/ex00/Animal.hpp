/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:17:27 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 15:46:35 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>


class Animal
{
	protected:
		std::string type;
	public:
	Animal();
	Animal(std::string type);
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);
	virtual void makeSound() const;
	virtual ~Animal();
	std::string getType() const;
	
};

#endif