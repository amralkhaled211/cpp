/* ************************************************************************** */
/*	                                                                         */
/*                                                        :::      ::::::::   */
/*   replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:29:29 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/27 17:53:30 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

Replace::Replace(std::string filename, std::string s1, std::string s2) : filename(filename), s1(s1), s2(s2)
{
}

Replace::~Replace()
{
}

void Replace::replace()
{
	std::ifstream file(filename.c_str());
    if (!file.is_open())
	{
		std::cerr << "Error: could not open file " << filename << std::endl;
		return;
	}
	std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
	file.close();
	
	std::string replaced;
	for (size_t pos = 0; pos < content.size(); )
	{
		if (content.substr(pos, s1.size()) == s1)
		{
			replaced += s2;
			pos += s1.size();
		} 
		else
		{
			replaced += content[pos];
			pos++;
		}
	}
	
	std::ofstream newFile((filename + ".replace").c_str());
	if (!newFile.is_open()) 
	{
		std::cerr << "Error: could not open file " << filename + ".replace" << std::endl;
		return;
	}
	newFile << replaced;
	newFile.close();
}