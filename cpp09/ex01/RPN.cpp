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
	{
		return res = value1 * value2;
	}
	if(oper == "+")
	{
		return res = value1 + value2;
	}
	if(oper == "/")
	{
		return res = value1 / value2;
	}
	if(oper == "-")
	{
		return res = value1 - value2;
	}
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

void RPN::Calculator(const std::string &arg)
{
	try 
	{
		validateString(arg);
		std::string cleanedArg = removeSpaces(arg);
		//std::cout << cleanedArg << std::endl;
		int i = 0;
		while (cleanedArg[i])
		{
			if (is_operation(cleanedArg[i]) && (this->RPN_stack.size() == 2))
			{
				
				this->RPN_stack.push(std::string(1, cleanedArg[i]));
				// std::cout << "this opertor pushed :" << cleanedArg[i] << std::endl;
				std::string oper = this->RPN_stack.top();
				this->RPN_stack.pop();
				// std::cout << "this opertor are poped :" << cleanedArg[i] << std::endl;
				std::string value1_char = this->RPN_stack.top();
				this->RPN_stack.pop();
				// std::cout << "this num1  are poped :" << value1_char << std::endl;
				std::string value2_char = this->RPN_stack.top();
				this->RPN_stack.pop();
				// std::cout << "this num2  are poped :" << value2_char << std::endl;
				int value1 = stringToInt(value2_char); // Convert string to int
				// std::cout << "this is value num 1 :" << value1 << std::endl;
            	int value2 = stringToInt(value1_char); // Convert string to int
				// std::cout << "this is value num 2 :" << value2 << std::endl;
            	int new_value_int = get_the_resuelt(value1, value2, oper);
				// std::cout << "this is final res :" << new_value_int << std::endl;
            	std::string new_value_str = intToString(new_value_int); // Convert int to string
				this->RPN_stack.push(new_value_str);
				// std::cout << "size of stack :" << this->RPN_stack.size() << std::endl;
			}
			else
			{
				this->RPN_stack.push(std::string(1, cleanedArg[i]));
				// std::cout <<"numbers bening pushed " << cleanedArg[i] << std::endl;
				
			}
			i++;
		}
		std::cout << this->RPN_stack.size() << std::endl;
		std::cout << this->RPN_stack.top() << std::endl;
		// std::cout << "Stack elements: ";
        // while (!this->RPN_stack.empty())
        // {
        //     std::cout << this->RPN_stack.top();
        //     this->RPN_stack.pop();
        // }
        // std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << "Error " <<  e.what() << std::endl;
	}
}