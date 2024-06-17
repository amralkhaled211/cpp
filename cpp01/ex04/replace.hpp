/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalkhal <amalkhal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:29:43 by amalkhal          #+#    #+#             */
/*   Updated: 2024/04/27 17:49:21 by amalkhal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
# define REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>

class Replace {
private:
	std::string filename;
	std::string s1;
	std::string s2;

public:
	Replace(std::string filename, std::string s1, std::string s2);
	~Replace();
	void replace();
};

#endif