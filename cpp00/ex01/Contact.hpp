/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:25:42 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/13 18:38:18 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>


class Contact
{
	private:
		std::string firstName;
    	std::string lastName;
   		std::string nickname;
    	std::string phoneNumber;
    	std::string darkestSecret;
	public:
		Contact();
		~Contact();
		void setFirstName(std::string firstName);
		std::string getFirstName();
		void setLastName(std::string lastName);
		std::string getLastName();
		void setNickname(std::string nickname);
		std::string getNickname();
		void setPhoneNumber(std::string phoneNumber);
		std::string getPhoneNumber();
		void setDarkestSecret(std::string
		darkestSecret);
		std::string getDarkestSecret();
		std::string print_dot(std::string str) const;
};

#endif