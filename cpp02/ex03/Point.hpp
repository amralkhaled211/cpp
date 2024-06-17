/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:22:24 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 13:17:57 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"


class Point
{
	private:
		Fixed x;
		Fixed y;
	public:
		Point();
		Point(float x, float y);
		Point(Point const & src);
		~Point();
		Point & operator=(Point const & src);
		Fixed getX() const;
		Fixed getY() const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point );


#endif