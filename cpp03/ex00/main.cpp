/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:51:25 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 14:25:21 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    // Test default constructor
    ClapTrap defaultClap;

    // Test name constructor
    ClapTrap namedClap("Clappy");
     

    // Test copy constructor
    ClapTrap copyClap(namedClap);
     

    // Test attack
    namedClap.attack("target");
     

    // Test takeDamage
    namedClap.takeDamage(5);
        
    // Test beRepaired
    namedClap.beRepaired(5);
      
    // Test assignment operator
    defaultClap = namedClap;
      

    return 0;
}