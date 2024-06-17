/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:03:32 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/13 18:31:48 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <limits>
# include "Contact.hpp"
class PhoneBook
{
	private:
		Contact contacts[8];
		int contactsCount;
	public:
		PhoneBook(): contactsCount(0) {};
		~PhoneBook();
		void addContact(Contact contact);
		void displayContacts();
		void searchContact();
};
#endif