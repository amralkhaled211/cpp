/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:21:58 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 13:01:01 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.hpp"

Point::Point()
{
	this->x = 0;
	this->y = 0;
}

Point::Point(float x, float y)
{
	this->x = x;
	this->y = y;
}

Point::Point(Point const & src)
{
	*this = src;
}

Point::~Point()
{
}

Point & Point::operator=(Point const & src)
{
	this->x = src.x;
	this->y = src.y;
	return *this;
}


Fixed Point::getX() const
{
	return this->x;
}

Fixed Point::getY() const
{
	return this->y;
}

