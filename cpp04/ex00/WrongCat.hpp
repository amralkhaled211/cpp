/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:24:23 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/09 14:49:46 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat( WrongCat const & src );
		WrongCat & operator=( WrongCat const & rhs );
		virtual ~WrongCat();
		std::string getType( void ) const;
		void makeSound( void ) const;
};

#endif