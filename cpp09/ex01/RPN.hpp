#ifndef RNB_HPP
#define RNB_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <algorithm>
#include <string>
#include <list>
#include <sstream>
#include <limits>
class RPN
{
	private :
		std::stack<int, std::list<double> > RPN_stack;
		void	validateString(const std::string &arg);
		std::string removeSpaces(const std::string &input);
		void processRPN(char oper);
		bool	is_operation(char opr);
		double	get_the_resuelt(double value1, double value2, double oper);
		double	stringToDouble(const std::string& str);
		std::list<std::string> split(const std::string &s, char delimiter);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
	public :
		RPN();
		void	Calculator(const std::string &arg);
		~RPN();
};


#endif