#ifndef RNB_HPP
#define RNB_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <string>
#include <sstream>

class RPN
{
	private :
		std::stack<int> RPN_stack;
		void	validateString(const std::string &arg);
		std::string removeSpaces(const std::string &input);
		void processRPN(char oper);
		bool	is_operation(char opr);
		int	get_the_resuelt(int value1, int value2, char oper);
		int stringToInt(const std::string& str);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public :
		RPN();
		void	Calculator(const std::string &arg);
		~RPN();
};


#endif