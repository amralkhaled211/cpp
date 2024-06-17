/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 14:58:31 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/02 16:47:57 by amalkhal         ###   ########.fr       */
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
		Fixed(const Fixed &fixed);
		Fixed &operator=(const Fixed &fixed);
		int getRawBits(void) const;
		void setRawBits(int const raw);
		~Fixed();
};

#endif