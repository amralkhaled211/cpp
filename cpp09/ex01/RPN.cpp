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
        if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '/' && *it != '*' && *it != ' ')
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

int	RPN::get_the_resuelt(int value1, int value2, char oper)
{
	int res;

	if(oper == '*')
		return res = value1 * value2;
	if(oper == '+')
		return res = value1 + value2;
	if(oper == '/')
		return res = value1 / value2;
	if(oper == '-')
		return res = value1 - value2;
	return 0;
}


int	RPN::stringToInt(const std::string& str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

void RPN::processRPN(char oper)
{
	int value1 = this->RPN_stack.top();
	this->RPN_stack.pop();
	int value2 = this->RPN_stack.top();
	this->RPN_stack.pop();
    int new_value = get_the_resuelt(value1, value2, oper);
	this->RPN_stack.push(new_value);
}

void RPN::Calculator(const std::string &arg)
{
	try 
	{
		validateString(arg);
		std::string cleanedArg = removeSpaces(arg);
		int i = 0;
		while (cleanedArg[i])
		{
			if (is_operation(cleanedArg[i]) && this->RPN_stack.size() >= 2)
				processRPN(cleanedArg[i]);
			else if (!is_operation(cleanedArg[i]))
			{
				std::string charAsString1(1, cleanedArg[i]); // Convert char to std::string
				int value = stringToInt(charAsString1);
				this->RPN_stack.push(value);
				if (cleanedArg[i + 1] == '\0')
					throw std::invalid_argument("You need to put valid input");
			}
			else
					throw std::invalid_argument("not enough numbers to calculate");
			i++;

		}
		if (this->RPN_stack.size() != 1)
			throw std::invalid_argument("not enough operations");
		std::cout << this->RPN_stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " <<  e.what() << std::endl;
	}
}