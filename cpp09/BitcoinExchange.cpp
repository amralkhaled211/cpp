#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

	//std::cout << "hello " << std::endl;
	std::ifstream input_DB("data.csv");
	if (!input_DB.is_open())
	{
		std::cerr << "Erorr opening a file " << std::endl;
	}
	std::string line;
	while (std::getline(input_DB, line))
	{
		size_t delim = line.find(',');

		std::string key = line.substr(0, delim);
		std::string value = line.substr(delim + 1, line.length());
		this->DB[key] = value;
	}
	// for (std::map<std::string, std::string>::iterator itr = DB.begin(); itr != DB.end(); itr++)
	// {
    //    std::cout << itr->first << ":" << itr->second << std::endl;
    // }
	input_DB.close();
}

void BitcoinExchange::Exchanger(std::string &file)
{
	std::ifstream input_file(file);
	if (!input_file.is_open())
	{
		std::cerr << "Erorr opening a file " << std::endl;
		//exit
	}
	
	//check for empty file 
	input_file.seekg(0, std::ios::end);
	if (input_file.tellg() == 0)
	{
		std::cerr << "The file is empty" << std::endl;
        input_file.close();
		//I should return or somthing 
		//exit
	}
	input_file.seekg(0, std::ios::end);

	//check the right format of the first line
	std::string line;
	std::getline(input_file, line);
	if (line != "date | value")
	{
		std::cerr << "invalid format !!" << std::endl;
		//exit
	}
	while (std::getline(input_file, line))
	{
		size_t delim = line.find("|");
		if (delim == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }
	}



}