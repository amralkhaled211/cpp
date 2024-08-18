#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP


#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <iomanip>
//#include <regex>

class BitcoinExchange
{
	private:
		std::map<std::string, std::string> DB;
		bool check_valid_key(const std::string& key);
		std::string delete_spaces(const std::string& str);
		bool	check_valid_value (const std::string &value);
		std::string prev_date(const std::string& date);
	public :
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		void	Exchanger(const std::string &file);
};

#endif