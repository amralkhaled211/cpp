#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target , 145, 137)
{
}


ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : AForm(src)
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{

	if (!this->getSigned())
    {
        throw AForm::FormNotSignedException();
    }
    if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	// Execute the form
	std::ofstream file((this->getName() + "_shrubbery").c_str());
	if (!file.is_open())
	{
		throw AForm::FileNotOpenedException();
	}
	file << "      /\\" << std::endl;
	file << "     /  \\" << std::endl;
	file << "    /    \\" << std::endl;
	file << "   /      \\" << std::endl;
	file << "  /        \\" << std::endl;
	file << " /          \\" << std::endl;
	file << " ------------" << std::endl;
	file << "     ||||" << std::endl;
	file << "     ||||" << std::endl;
	file.close();
}	
