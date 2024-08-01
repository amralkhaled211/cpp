#include "Bureaucrat.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{

    try
    {
        Bureaucrat john("John", 4);
        Intern intern;
        AForm *form = intern.makeForm("shrubbery creation", "home");
        if (form == NULL)
        {
            std::cout << "Form not found" << std::endl;
            return 1;
        }

        form->beSigned(john);
        john.signForm(*form);
        form->execute(john);
        john.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}
