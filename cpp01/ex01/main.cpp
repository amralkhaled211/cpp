/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:39:09 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 10:10:58 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main( void )
{
	int j = 5;

    Zombie *zombiz = zombieHorde(j, "zombi");

    for (int i = 0; i < j; i++) {
        zombiz[i].announce();
    }

    delete [] zombiz;
    return 0;
}