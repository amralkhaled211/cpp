/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:27:50 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/27 17:36:38 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "replace.hpp"

int main(int ac, char **av)
{
    if (ac != 4) {
        std::cerr << "Error: wrong number of arguments" << std::endl;
        return 1;
    }

    Replace replace(av[1], av[2], av[3]);
    replace.replace();

    return 0;
}