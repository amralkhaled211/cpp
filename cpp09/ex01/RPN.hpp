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
		std::stack<std::string> RPN_stack;
		void processRPN(char cleanedArgChar);
	public :
		RPN();
		void	Calculator(const std::string &arg);

};


#endif