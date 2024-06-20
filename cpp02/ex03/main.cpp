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


#include <iostream>
#include <cmath>
#include "Fixed.hpp"
#include "Point.hpp"

// class Point {
// public:
//     double x, y;
//     Point(double x = 0, double y = 0) : x(x), y(y) {}
// };

// double area(const Point &a, const Point &b, const Point &c) {
//     return std::abs((a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y)) / 2.0);
// }

// bool bsp(const Point &a, const Point &b, const Point &c, const Point &point) {
//     double total = area(a, b, c);
//     double p1 = area(point, b, c);
//     double p2 = area(a, point, c);
//     double p3 = area(a, b, point);

//     double epsilon = 0.00001; // or some other small value
//     if (std::abs(total - (p1 + p2 + p3)) < epsilon)
//     {
//         return true;
//     } 
//     else
//     {
//         return false;
//     }
// }


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
	if ( bsp( Point(0, 0), Point(0, 1), Point(1, 0), Point(0.1f, 0.3f) ) == true )
	{
	    std::cout << "Point is in the triangle" << std::endl;
	}
	else
	{
	    std::cout << "Point is not in the triangle" << std::endl;
	}
    return 0;
}