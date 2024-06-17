/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:52:12 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/03 19:26:37 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	private:
		int value;
		static const int fractionalBits = 8;
	public:
		Fixed();
		Fixed(const int value);
		Fixed(const float floatNumber);
		Fixed(const Fixed &fixed);
		~Fixed();
		Fixed &operator=(const Fixed &fixed);
		float toFloat(void) const;
		int toInt(void) const;
		int getRawBits(void) const;
		void setRawBits(int const raw);
		bool    operator>( const Fixed &fixed ) const ;
	    bool    operator<( const Fixed &fixed ) const ;
	    bool    operator>=( const Fixed &fixed ) const ;
	    bool    operator<=( const Fixed &fixed ) const ;
	    bool    operator==( const Fixed &fixed ) const ;
	    bool    operator!=( const Fixed &fixed ) const ;
	
	    Fixed   operator+( const Fixed &fixed ) const ;
	    Fixed   operator-( const Fixed &fixed ) const ;
	    Fixed   operator*( const Fixed &fixed ) const ;
	    Fixed   operator/( const Fixed &fixed ) const ;
	
	    Fixed&  operator++( void ); 
	    Fixed   operator++( int ); 
	    Fixed&  operator--( void ); 
	    Fixed   operator--( int ); 

	
	    static Fixed& min( Fixed &a, Fixed &b );
	    static const Fixed& min( const Fixed &a, const Fixed &b );
	    static Fixed& max( Fixed &a, Fixed &b );
	    static const Fixed& max( const Fixed &a, const Fixed &b );
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif