#include "RPN.hpp"

RPN::RPN()
{

}

void validateString(const std::string &arg)
{
    for (std::string::const_iterator it = arg.begin(); it != arg.end(); ++it)
	{
        if (!isdigit(*it) && *it != '+' && *it != '-' && *it != '/' && *it != '*' && *it != ' ')
		{
            throw std::invalid_argument("Invalid character in input string");
        }
    }
}

std::string removeSpaces(const std::string &input)
{
    std::string result = input;
    result.erase(std::remove(result.begin(), result.end(), ' '), result.end());
    return result;
}

bool	is_operation(char opr)
{
	if (opr == '-' || opr == '+' || opr == '*' || opr == '/')
		return true;
	return false ;
}

int	get_the_resuelt(int value1, int value2, std::string oper)
{
	int res;

	if(oper == "*")
		return res = value1 * value2;
	if(oper == "+")
		return res = value1 + value2;
	if(oper == "/")
		return res = value1 / value2;
	if(oper == "-")
		return res = value1 - value2;
	return 0;
}

// Function to convert int to string
std::string intToString(int value)
{
    std::stringstream ss;
    ss << value;
    return ss.str();
}

// Function to convert string to int
int stringToInt(const std::string& str)
{
    std::stringstream ss(str);
    int value;
    ss >> value;
    return value;
}

void RPN::processRPN(char cleanedArgChar)
{
	this->RPN_stack.push(std::string(1, cleanedArgChar));
	// std::cout << "just pushed :" << cleanedArgChar << std::endl;
	std::string oper = this->RPN_stack.top();
	this->RPN_stack.pop();
	// std::cout << "just poped operator :" << oper << std::endl;
	std::string value1_char = this->RPN_stack.top();
	this->RPN_stack.pop();
	// std::cout << "just poped value1 :" << value1_char << std::endl;
	std::string value2_char = this->RPN_stack.top();
	this->RPN_stack.pop();
	// std::cout << "just poped value2 :" << value2_char << std::endl;
	int value1 = stringToInt(value2_char); // Convert string to int
    int value2 = stringToInt(value1_char); // Convert string to int
    int new_value_int = get_the_resuelt(value1, value2, oper);
    std::string new_value_str = intToString(new_value_int); // Convert int to string
	this->RPN_stack.push(new_value_str);
	// std::cout << "just pushed :" << new_value_str << std::endl;
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
			if (!is_operation(cleanedArg[i]) && cleanedArg[i + 1] && is_operation(cleanedArg[i + 1]))
			{
				this->RPN_stack.push(std::string(1, cleanedArg[i]));

				int j = 1;
				int opertions = 0;
				int stack_size = this->RPN_stack.size();
				while (j < stack_size)
				{
					if (cleanedArg[i + j] && is_operation(cleanedArg[i + j]))
						opertions++;
					else
						throw std::invalid_argument("There is not enough opertions");
					j++;
				}
				if (cleanedArg[i + j] && is_operation(cleanedArg[i + j]))
					throw std::invalid_argument("There is not enough number to calculate");
				while (opertions > 0)
				{
					i++;
					processRPN(cleanedArg[i]);
					opertions--;
				}
			}
			else if (!is_operation(cleanedArg[i]))
			{
				this->RPN_stack.push(std::string(1, cleanedArg[i]));
				if (cleanedArg[i + 1] == '\0')
					throw std::invalid_argument("You need to put valid input");
			}
			else
					throw std::invalid_argument("You need to put valid input");
			i++;
		}
		std::cout << this->RPN_stack.top() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error : " <<  e.what() << std::endl;
	}
}
