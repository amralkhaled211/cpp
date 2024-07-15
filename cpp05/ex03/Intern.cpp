#include "Intern.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &intern)
{
	*this = intern;
}

Intern::~Intern()
{
}

Intern &Intern::operator=(const Intern &intern)
{
	(void)intern;
	return (*this);
}



AForm *Intern::makeForm(std::string formName, std::string target)
{
	int i = 0;
	std::string formNames[] =
	{
        "robotomy request",
        "presidential pardon",
        "shrubbery creation"
    };
	while (i < 3)
	{
		if (formName == formNames[i])
		{
			switch (i)
			{
			case 0:
				std::cout << "Intern creates " << formName << std::endl;
				return (new RobotomyRequestForm(target));
			case 1:
				std::cout << "Intern creates " << formName << std::endl;
				return (new PresidentialPardonForm(target));
			case 2:
				std::cout << "Intern creates " << formName << std::endl;
				return (new ShrubberyCreationForm(target));
			}
		}
		i++;
	}
	return (NULL);
}