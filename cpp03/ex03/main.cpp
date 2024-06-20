/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:51:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/08 15:02:41 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

#include "DiamondTrap.hpp"
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main( void )
{
    DiamondTrap ash("Diamond");
    ClapTrap clap("Base");
    ash.attack("Base");
    clap.takeDamage(30);
    clap.beRepaired(10);
    ash.whoAmI();

    return 0;
}

/* int main()
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
} */