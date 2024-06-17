/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:26 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 13:22:03 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include "Point.hpp"

int main ( void )
{
    /* if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(30, 15) ) == true )
	{
        std::cout << "Point is in the triangle" << std::endl;
    }
	else
	{
        std::cout << "Point is not in the triangle" << std::endl;
    } */
	if ( bsp( Point(0, 0), Point(10, 30), Point(20, 0), Point(10, 10) ) == true )
	{
	    std::cout << "Point is in the triangle" << std::endl;
	}
	else
	{
	    std::cout << "Point is not in the triangle" << std::endl;
	}
    return 0;
}