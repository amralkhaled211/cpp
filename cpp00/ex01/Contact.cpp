/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:11:18 by amalkhal          #+#    #+#             */
/*   Updated: 2024/05/13 18:34:17 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
}

Contact::~Contact()
{
}

void Contact::setFirstName(std::string firstName)
{
	this->firstName = firstName;
}

std::string Contact::getFirstName()
{
	return this->firstName;
}

void Contact::setLastName(std::string lastName)
{
	this->lastName = lastName;
}

std::string Contact::getLastName()
{
	return this->lastName;
}

void Contact::setNickname(std::string nickname)
{
	this->nickname = nickname;
}

std::string Contact::getNickname()
{
	return this->nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber()
{
	return this->phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::getDarkestSecret()
{
	return this->darkestSecret;
}

std::string Contact::print_dot(std::string str) const
{
	std::string newStr;
	if (str.length() > 10)
	{
		newStr = str.substr(0, 9);
		newStr += ".";
	}
	else
	{
		newStr = str;
	}
	return newStr;
}
