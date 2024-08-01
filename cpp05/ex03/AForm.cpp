#include "AForm.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), _signed(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}


AForm::AForm(AForm const &src) : name(src.name), _signed(src._signed), gradeToSign(src.gradeToSign), gradeToExecute(src.gradeToExecute)
{
	*this = src;
}

AForm &AForm::operator=(AForm const &src)
{
	if (this != &src)
	{
		this->_signed = src._signed;
	}
	return *this;
}

AForm::~AForm()
{
}

const std::string	AForm::getName() const
{
	return name;
}

bool				AForm::getSigned() const
{
	return _signed;
}

int					AForm::getGradeToSign() const
{
	return gradeToSign;
}

int					AForm::getGradeToExecute() const
{
	return gradeToExecute;
}

void				AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	_signed = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form is not signed";
}

const char *AForm::FileNotOpenedException::what() const throw()
{
	return "File not opened";
}

std::ostream &operator<<(std::ostream &out, AForm const &src)
{
	out << "Form " << src.getName() << " is ";
	if (src.getSigned())
		out << "signed";
	else
		out << "not	signed";

	out << " and requires grade " << src.getGradeToSign() << " to sign and grade " << src.getGradeToExecute() << " to execute";
	return out;
}