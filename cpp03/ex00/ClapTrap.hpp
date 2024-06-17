/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:50:37 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/05 13:09:11 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
	private:
		std::string	name;
		unsigned int	hitpoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &clap);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clap);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif