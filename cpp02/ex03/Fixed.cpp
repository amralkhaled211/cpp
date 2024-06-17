/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:51:55 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/03 19:41:58 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
	this->value = 0;
}

Fixed::Fixed(const int intNumber)
{
	this->value = intNumber << fractionalBits;
}

Fixed::Fixed(const float floatNumber)
{
	this->value = static_cast<int>(floatNumber * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::~Fixed()
{
}


Fixed &Fixed::operator=(const Fixed &fixed)
{
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
	return this->value;
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}


//=============================================================================


bool    Fixed::operator>( const Fixed &fixed ) const
{
	return (this->value > fixed.value);
}

bool    Fixed::operator<( const Fixed &fixed ) const
{
	return (this->value < fixed.value);
}

bool    Fixed::operator>=( const Fixed &fixed ) const
{
	return (this->value >= fixed.value);
}

bool    Fixed::operator<=( const Fixed &fixed ) const
{
	return (this->value <= fixed.value);
}

bool    Fixed::operator==( const Fixed &fixed ) const
{
	return (this->value == fixed.value);
}

bool    Fixed::operator!=( const Fixed &fixed ) const
{
	return (this->value != fixed.value);
}

//=============================================================================


Fixed   Fixed::operator+( const Fixed &fixed ) const
{
	Fixed result;

	result.value = this->value + fixed.value;
	return result;
}

Fixed   Fixed::operator-( const Fixed &fixed ) const
{
	Fixed result;

	result.value = this->value - fixed.value;
	return result;
}

Fixed   Fixed::operator*( const Fixed &fixed ) const
{
	Fixed result;

	result.value = (this->value * fixed.value) >> fractionalBits;
	return result;
}

Fixed   Fixed::operator/( const Fixed &fixed ) const
{
	Fixed result;

	result.value = (this->value << fractionalBits) / fixed.value;
	return result;
}

//=============================================================================

Fixed&  Fixed::operator++( void ) // prefix
{
	this->value++;
	return *this;
}

Fixed   Fixed::operator++( int ) // postfix
{
	Fixed temp = *this;

	this->value++;
	return temp;
}

Fixed&  Fixed::operator--( void )
{
	this->value--;
	return *this;
}

/* the prefix decrement operator (Fixed& Fixed::operator--( void ))
doesn't need a temporary object because it's 
supposed to decrement the object first and then return it. */

Fixed   Fixed::operator--( int )
{
	Fixed temp = *this;

	this->value--;
	return temp;
}

//=============================================================================}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return a;
	return b;

}




