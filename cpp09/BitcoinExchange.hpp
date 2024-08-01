#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
#include <fstream>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> DB;
	public :
		BitcoinExchange();
		void	Exchanger(std::string &file);
};

#endif