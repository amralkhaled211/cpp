/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 21:08:42 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/27 21:12:29 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main( int ac, char **av ) {

    if (ac != 2) {
        return (std::cerr << "Wrong input"<< std::endl, 1);
    }
    std::string input = av[1];
    Harl        harl;

    harl.complain(input);

    return 0;
}