/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 15:42:38 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/07 14:56:32 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"


class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap( std::string name );
		~ScavTrap();
    	void    attack(std::string const& target);
    	void    guardGate();
};

#endif

