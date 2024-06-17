/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:17:27 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/10 14:25:21 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>


class AAnimal
{
	protected:
		std::string type;
	public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal &animal);
	AAnimal &operator=(const AAnimal &animal);
	virtual void makeSound() const = 0;
	virtual ~AAnimal() = 0;
	std::string getType() const;
	
};

#endif