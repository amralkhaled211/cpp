#include "RPN.hpp"

RPN::RPN()
{

}

RPN::~RPN()
{

}


RPN::RPN(const RPN &other)
{
	*this = other;
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
	{
		this->RPN_stack = other.RPN_stack;
	}
	return *this;
}

void RPN::validateString(const std::string &arg)
{
    for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it)
	{
        if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '/' && *it != '*' && *it != ' ' && *it != '.')
		{
            throw std::invalid_argument("Invalid character in input string");
        }
    }
}

std::string	RPN::removeSpaces(const std::string &input)
{
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

bool	RPN::is_operation(char opr)
{
	if (opr == '-' || opr == '+' || opr == '*' || opr == '/')
		return true;
	return false ;
}

double	RPN::get_the_resuelt(double value1, double value2, double oper)
{
	double res;

	if(oper == '*')
		return res = value2 * value1;
	if(oper == '+')
		return res = value2 + value1;
	if(oper == '/')
		return res = value2 / value1;
	if(oper == '-')
		return res = value2 - value1;
	return 0;
}


double	RPN::stringToDouble(const std::string& str)
{
    std::stringstream ss(str);
    double value;
    ss >> value;
	if (ss.fail())
		throw std::invalid_argument("Invalid number in input string");
    return value;
}

void RPN::processRPN(char oper)
{
	double value1 = this->RPN_stack.top();
	this->RPN_stack.pop();
	double value2 = this->RPN_stack.top();
	this->RPN_stack.pop();
    double new_value = get_the_resuelt(value1, value2, oper);
    //std::cout << "new_value: " << new_value << std::endl;
	if (new_value > std::numeric_limits<double>::max() || new_value < -std::numeric_limits<double>::max())
    	throw std::invalid_argument("Result is out of range");
	this->RPN_stack.push(new_value);
}

std::list<std::string> RPN::split(const std::string &s, char delimiter)
{
    std::list<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

void printTokens(const std::list<std::string>& tokens)
{
    for (std::list<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
	{
		std::cout << "printTokens: ";
        std::cout << *it << std::endl;
    }
}

void validateSpacing(const std::string &arg)
{
    for (size_t i = 0; i < arg.length(); ++i)
	{
        if (isdigit(arg[i]) || arg[i] == '*' || arg[i] == '/' || arg[i] == '+' || arg[i] == '-')
		{
			if (isdigit(arg[i]) && i + 1 < arg.length() && arg[i + 1] == '.')
			{
				i++;
				while (i + 1 < arg.length() && isdigit(arg[i + 1]))
					++i;
			}
            if (i + 1 < arg.length() && arg[i + 1] != ' ')
			{
                throw std::invalid_argument("Invalid spacing in the input string.");
            }
        }
    }
}

void RPN::Calculator(const std::string &arg)
{
    try 
    {
        validateString(arg);
		validateSpacing(arg);
        std::list<std::string> tokens = split(arg, ' ');
		//printTokens(tokens);
        for (std::list<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            const std::string &token = *it;
            if (is_operation(token[0]) && this->RPN_stack.size() >= 2)
                processRPN(token[0]);
            else if (!is_operation(token[0]))
            {
                double value = stringToDouble(token);
                this->RPN_stack.push(value);
            }
            else
                throw std::invalid_argument("not enough numbers to calculate");
        }
        if (this->RPN_stack.size() != 1)
            throw std::invalid_argument("Invalid RPN expression");
        std::cout << this->RPN_stack.top() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

// void RPN::Calculator(const std::string &arg)
// {
// 	try 
// 	{
// 		validateString(arg);
// 		std::string cleanedArg = removeSpaces(arg);
// 		int i = 0;
// 		while (cleanedArg[i])
// 		{
// 			if (is_operation(cleanedArg[i]) && this->RPN_stack.size() >= 2)
// 				processRPN(cleanedArg[i]);
// 			else if (!is_operation(cleanedArg[i]))
// 			{
// 				std::string charAsString1(1, cleanedArg[i]); // Convert char to std::string
// 				double value = stringToDouble(charAsString1);
// 				this->RPN_stack.push(value);
// 				if (cleanedArg[i + 1] == '\0')
// 					throw std::invalid_argument("You need to put valid input");
// 			}
// 			else
// 					throw std::invalid_argument("not enough numbers to calculate");
// 			i++;
// 		}
// 		if (this->RPN_stack.size() != 1)
// 			throw std::invalid_argument("not enough operations");
// 		std::cout << this->RPN_stack.top() << std::endl;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cerr << "Error : " <<  e.what() << std::endl;
// 	}
// }


