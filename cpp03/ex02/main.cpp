/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:51:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/07 15:34:05 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    //ScavTrap scav("Scav");
    FragTrap frag("Frag");
    
    clap.attack("frag");
    // scav.takeDamage(5);
    frag.takeDamage(5);
    // scav.beRepaired(10);
    frag.beRepaired(10);
    // scav.attack("Clap");
    frag.attack("Clap");
    clap.takeDamage(20);
    clap.beRepaired(10);
    // scav.guardGate();
    frag.highFivesGuys();
    return 0;
}