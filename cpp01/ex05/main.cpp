/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 18:46:49 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 13:00:10 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( void )
{

    std::string input;
    Harl        harl;

    while (std::cin)
    {
        std::cout << "Enter a level: ";
        if (!std::getline(std::cin, input))
            break;
        if (input.compare("DEBUG") == 0 || input.compare("INFO") == 0
            || input.compare("WARNING") == 0 || input.compare("ERROR") == 0)
            harl.complain(input);
        else if (input.compare("exit") == 0)
            break;
        else
            std::cout << "Invalid level: " << input << std::endl;
    }

    return 0;
}