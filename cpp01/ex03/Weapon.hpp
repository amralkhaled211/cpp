/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 16:02:38 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/13 11:16:36 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>
/* #include "HumanA.hpp"
#include "HumanB.hpp" */


class Weapon
{
    private:
        std::string type;
    
    public:
        Weapon(const std::string& type);
        const std::string& getType() const;
        void setType(const std::string& newType);
};

#endif