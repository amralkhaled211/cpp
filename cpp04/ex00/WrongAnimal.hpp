/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:51 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:43:37 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();
		WrongAnimal & operator=( WrongAnimal const & rhs );

		//WrongAnimal & operator=( WrongAnimal const & rhs );

		std::string getType( void ) const;
		void makeSound( void ) const;

	protected:
		std::string _type;
};

#endif