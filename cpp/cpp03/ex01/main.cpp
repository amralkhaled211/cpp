/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:51:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/15 20:40:05 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap clap("Clap");
    ScavTrap scav("Scav");
    clap.attack("Scav");
    scav.takeDamage(5);
    scav.beRepaired(10);
    scav.attack("Clap");
    clap.takeDamage(20);
    clap.beRepaired(10);
    scav.guardGate();
    return 0;
}