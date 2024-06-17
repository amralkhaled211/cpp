/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:49:03 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/03 14:29:55 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

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
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif