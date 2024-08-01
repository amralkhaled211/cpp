#ifndef Form_HPP
#define Form_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string  _name;
	bool _signed;
	int const _gradeToSign;
	int const _gradeToExecute;

public:

	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &copy);
	Form &operator=(Form const &copy);
	~Form();

	std::string getName() const;
	bool getSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception
	{
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif