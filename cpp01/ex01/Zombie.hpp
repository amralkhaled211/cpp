/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:39:40 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 10:13:06 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		void	announce(void);
		void setName(std::string name);
		~Zombie();
};

Zombie* zombieHorde(int N, std::string name);

#endif