#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP


#include <sstream> 
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <cmath>
#include <iomanip>

class ScalarConverter
{
	public:
	    static void convert(const std::string& literal);
	private:
	    ScalarConverter();
		static void printChar(const std::string& literal);
	    static void printInt(const std::string& literal);
	    static void printFloat(const std::string& literal);
	    static void printDouble(const std::string& literal);
};


#endif