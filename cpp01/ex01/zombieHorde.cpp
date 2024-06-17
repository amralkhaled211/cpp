/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:39:59 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 10:09:59 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombies = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		//zombies[i] = Zombie(name); /// this is wrong because it will create a new zombie object and assign it to the zombies[i] object
		zombies[i].setName(name);
	}
	return zombies;
}