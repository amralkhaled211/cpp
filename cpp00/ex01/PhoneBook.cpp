/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:03:12 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/13 18:27:44 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::~PhoneBook()
{
}

void PhoneBook::addContact(Contact contact)
{
	if (contact.getFirstName().empty() || contact.getLastName().empty()
        || contact.getPhoneNumber().empty() || contact.getNickname().empty()
            || contact.getDarkestSecret().empty())
    {
        std::cout << "Error: All fields must be filled." << std::endl;
        return;
    }
    if (contactsCount < 8)
    {
        contacts[contactsCount] = contact;
        contactsCount++;
    }
    else
    {
        for (int i = 0; i < contactsCount - 1; i++)
        {
            contacts[i] = contacts[i + 1];
        }
        contacts[contactsCount - 1] = contact;
    }
}

void PhoneBook::displayContacts()
{
	for (int i = 0; i < contactsCount; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].print_dot(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << contacts[i].print_dot(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << contacts[i].print_dot(contacts[i].getNickname()) << "|" << std::endl;
	}
}

void    PhoneBook::searchContact()
{
    int index;
    std::cout << "Enter the index of the contact you want to see: ";
    std::cin >> index;
    if (std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer." << std::endl;
        return;
    }
    std::cin.ignore();
    if (index < 0 || index >= contactsCount)
    {
        std::cout << "Error: Invalid index." << std::endl;
        return;
    }
    std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << contacts[index].getDarkestSecret() << std::endl;
}