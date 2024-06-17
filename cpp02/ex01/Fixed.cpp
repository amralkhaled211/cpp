/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:48:53 by amalkhal          #+#    #+#             */
/*   Updated: 2024/06/15 11:27:19 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int intNumber)
{
	std::cout << "Int constructor called" << std::endl;
	this->value = intNumber << fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	std::cout << "Float constructor called" << std::endl;
	this->value = static_cast<int>(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &fixed)
	{
		this->value = fixed.value;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return this->value >> fractionalBits;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}


///////Difference between the two floating point numbers and fixed point numbers


// this floating point number

/* float floatNumber = 42.42f; // Declare and initialize a floating-point number
floatNumber = floatNumber / 2.0f; // Perform a floating-point division
std::cout << "Result: " << floatNumber << std::endl; // Output: Result: 21.21 */


// this fixed point number

/* const int fractionalBits = 8; // Number of fractional bits for fixed-point representation
int fixedNumber = static_cast<int>(42.42f * (1 << fractionalBits)); // Convert float to fixed-point
fixedNumber = fixedNumber / 2; // Perform an integer division
float result = static_cast<float>(fixedNumber) / (1 << fractionalBits); // Convert back to float for display
std::cout << "Result: " << result << std::endl; // Output: Result: 21.20703125 */