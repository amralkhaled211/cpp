#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

//the only public method of the class
void ScalarConverter::convert(const std::string& literal)
{
    printChar(literal);
    printInt(literal);
    printFloat(literal);
    printDouble(literal);
}

void  ScalarConverter::printChar(const std::string& literal)
{

    std::stringstream ss(literal);
    long double value;
    if (!(ss >> value))
    {
        if (literal.size() == 3 && literal[0] == '\'' && literal[2] == '\'')
        {
            char c = literal[1];
            if (std::isprint(c))
            {
                std::cout << "char: '" << c << "'" << std::endl;
            }
            else
            {
                std::cout << "char: Non displayable" << std::endl;
            }   
        }
	    else
        {
	        std::cout << "char: impossible" << std::endl;
	    }
    }
    else
    {
	    if (value >= std::numeric_limits<char>::min() && value <= std::numeric_limits<char>::max())
        {
	        char c = static_cast<char>(value);
	        if (std::isprint(c))
            {
	            std::cout << "char: '" << c << "'" << std::endl;
	        }
            else
            {
	            std::cout << "char: Non displayable" << std::endl;
	        }
	    }
        else
        {
	        std::cout << "char: impossible" << std::endl;
	    } 
    }
}

void    ScalarConverter::printInt(const std::string& literal)
{
    std::stringstream ss(literal);
    long double value;
    if (ss >> value && std::floor(value) == value)
    {
        if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max())
        {
            std::cout << "int: " << static_cast<int>(value) << std::endl;
        }
        else
        {
            std::cout << "int: impossible" << std::endl;
        }
    }
    else
    {
        std::cout << "int: impossible" << std::endl;
    }
}


void    ScalarConverter::printFloat(const std::string& literal)
{
    if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "float: " << literal << std::endl;
    }
    else if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "float: " << literal.substr(0, literal.size()) << "f" << std::endl;
    }
    else
    {
        std::stringstream ss(literal);
        float value;
        if (ss >> value)
        {
            std::cout << std::fixed << std::setprecision(1);
            std::cout << "float: " << value << "f" << std::endl;
        }
        else
        {
            std::cout << "float: impossible" << std::endl;
        }
    }
}

void    ScalarConverter::printDouble(const std::string& literal)
{
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
    {
        std::cout << "double: " << literal << std::endl;
    }
    else if (literal == "-inff" || literal == "+inff" || literal == "nanf")
    {
        std::cout << "double: " << literal.substr(0, literal.size() - 1) << std::endl;
    }
    else
    {
        std::stringstream ss(literal);
        double value;
        if (ss >> value)
        {
            std::cout << "double: " << value << std::endl;
        }
        else
        {
            std::cout << "double: impossible" << std::endl;
        }
    }
}
