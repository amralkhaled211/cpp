/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:12 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 13:16:55 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Point.hpp"

// get he absolute value of a fixed point
Fixed   absolute(Fixed x)
{
    if (x < 0)
        return x * -1;
    return x;
}

// get the area of a triangle
Fixed area(Point const a, Point const b, Point const c)
{
    Fixed term1 = a.getX() * (b.getY() - c.getY());
    Fixed term2 = b.getX() * (c.getY() - a.getY());
    Fixed term3 = c.getX() * (a.getY() - b.getY());
    Fixed sum = term1 + term2 + term3;
    return sum / 2;
}

// check if a point is inside a triangle
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed abcArea = absolute(area(a, b, c));
    Fixed pabArea = absolute(area(point, a, b));
    Fixed pbcArea = absolute(area(point, b, c));
    Fixed pcaArea = absolute(area(point, c, a));

    if (abcArea == (pabArea + pbcArea + pcaArea))
	{
        return true;
    } 
	else
	{
        return false;
    }
}