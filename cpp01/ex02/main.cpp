/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:42:14 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/24 14:49:18 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR = &myString;
	std::string& stringREF = myString;

	std::cout << "Address of myString: " << &myString << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;

	std::cout << "Value in myString: " << myString << std::endl;
	std::cout << "Value in stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value in stringREF: " << stringREF << std::endl;
}