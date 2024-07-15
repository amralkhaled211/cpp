#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target , 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : AForm(src)
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &src)
{
	if (this != &src)
	{
		AForm::operator=(src);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::cout << this->getName() << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
