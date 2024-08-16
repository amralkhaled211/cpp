#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream input_DB("data.csv");
	if (!input_DB.is_open())
	{
		std::cerr << "Erorr opening a file " << std::endl;
	}
	std::string line;
	while (std::getline(input_DB, line))
	{
		size_t delim = line.find(',');

		std::string key = delete_spaces(line.substr(0, delim));
		std::string value = delete_spaces(line.substr(delim + 1, line.length()));
		this->DB[key] = value;
	}
	input_DB.close();
}

void BitcoinExchange::Exchanger(const std::string &file)
{
	std::ifstream input_file(file.c_str());
	if (!input_file.is_open())
	{
		std::cerr << "Erorr opening a file " << std::endl;
		return;
	}
	//check for empty file 
	input_file.seekg(0, std::ios::end);
	if (input_file.tellg() == 0)
	{
		std::cerr << "The file is empty" << std::endl;
        input_file.close();
		return ;
	}
	input_file.seekg(0, std::ios::beg);
	std::string line;
	std::getline(input_file, line);
	if (line != "date | value")
	{
		std::cerr << "invalid format !!" << std::endl;
		return;
	}
	while (std::getline(input_file, line))
	{
		size_t delim = line.find("|");
		if (delim == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
		std::string key = delete_spaces(line.substr(0, delim));
		if (!check_valid_key(key))
		{
			std::cerr << "Error: bad input => " << key << std::endl;
			continue;
		}
		std::string value = delete_spaces(line.substr(delim + 1, line.length()));
		if (!check_valid_value(value))
			continue;
		std::map<std::string , std::string>::iterator it;
		std::string old_date = key;
		it = this->DB.find(key);
		while(it == this->DB.end())
		{
			const std::string& new_date = old_date;
			old_date = prev_date(new_date);
			it = this->DB.find(old_date);
		}
		std::cout << key << " => " << value  << " = "
                << std::atof(it->second.c_str()) * std::atof(value.c_str()) << std::endl;
	}
}

bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}

std::string BitcoinExchange::delete_spaces(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (std::string::npos == first)
        return str;

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

bool BitcoinExchange::check_valid_key(const std::string& key)
{

	if (key.length() != 10)
	{
		// std::cerr << "Error : invalid : date format!!" << std::endl;
        return false;
	}
	for (int i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
		{
            if (key[i] != '-')
			{
				// std::cerr << "Error : invalid : date format!!" << std::endl;
                return false;
			}
        }
		else
		{
            if (!is_digit(key[i]))
			{
				// std::cerr << "Error : invalid : date format!!" << std::endl;
                return false;
			}
        }
    }

    // Extract year, month, and day from the key
    int year = std::atoi(key.substr(0, 4).c_str());
    int month = std::atoi(key.substr(5, 2).c_str());
    int day = std::atoi(key.substr(8, 2).c_str());

    // Check if year, month, and day are within valid ranges
    if ( year < 2009 || year < 0 || month < 1 || month > 12 || day < 1 || day > 31)
	{
		// std::cerr << "Error : invalid year range !!" << std::endl;
        return false;
    }
    // Check for months with fewer than 31 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
	{
		// std::cerr << "Error : invalid : days don't match month !!" << std::endl;
        return false;
    }
    // Check for February and leap years
    if (month == 2)
	{
        bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > 29 || (day == 29 && !is_leap))
		{
			// std::cerr << "Error : invalid : February format!!" << std::endl;
            return false;
        }
    }
    return true;
}

bool	BitcoinExchange::check_valid_value (const std::string &value)
{
	float num = std::atof(value.c_str());

	if (num < 0)
	{
		std::cerr << "Error: not a positive number " << std::endl;
		return false;
	}
	if (num > 1000)
	{
		std::cerr << "Error: too large a number" << std::endl;
		return false;
	}
	//if (value ==) i might need to check for a slight bigger number than 1000 somthing like 1000.0001
	return true;
}

std::string BitcoinExchange::prev_date(const std::string& date)
{
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
    if (is_leap)
        daysInMonth[1] = 29; // February has 29 days in a leap year
    day--;
    if (day == 0)
    {
        month--;
        if (month == 0)
        {
            month = 12;
            year--;
        }
        day = daysInMonth[month - 1];
    }
	std::stringstream ss;
	ss << year;
	std::string newYear = ss.str();

	ss.str(""); // Clear the stringstream
	ss << (month < 10 ? "0" : "") << month;
	std::string newMonth = ss.str();

	ss.str(""); // Clear the stringstream
	ss << (day < 10 ? "0" : "") << day;
	std::string newDay = ss.str();

    return newYear + "-" + newMonth + "-" + newDay;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : DB(other.DB)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this == &other)
		return *this;
	this->DB = other.DB;
	return *this;
}