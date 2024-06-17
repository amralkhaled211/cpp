/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:33:21 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/13 20:51:54 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include "Contact.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;
	Contact contact;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string darkestSecret;
	while (std::cin)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		if (!std::getline(std::cin, command))
   			 break;
		if (command == "ADD")
		{
			std::cout << "Enter first name: ";
			std::getline(std::cin, firstName);
			contact.setFirstName(firstName);
			
			std::cout << "Enter last name: ";
			std::getline(std::cin, lastName);
			contact.setLastName(lastName);

			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			contact.setNickname(nickname);
			
			std::cout << "Enter phone number: ";
			std::getline(std::cin, phoneNumber);
			contact.setPhoneNumber(phoneNumber);
			
			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			contact.setDarkestSecret(darkestSecret);
			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
		{
			phoneBook.displayContacts();
			phoneBook.searchContact();
		}
		else if (command == "EXIT")
		{
			break;
		}
		else
		{
			std::cout << "Invalid command." << std::endl;
		}
	}
	return 0;
}
