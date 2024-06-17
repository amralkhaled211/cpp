/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 12:31:31 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 09:27:37 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"



int main( void )
{
    Zombie zombi1("zombi1");

    Zombie *zombi2 = newZombie("heapZombi");
    zombi2->announce();
    delete zombi2;

    randomChump("stackZombi");
    return 0;
}