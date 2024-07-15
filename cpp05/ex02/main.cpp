#include "Bureaucrat.hpp"
#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    try
	{
        //bureaucrat should not be able to be bigger than  form in order of excute to work 
        Bureaucrat john("John", 4); // Assuming Bureaucrat constructor takes name and grade
        ShrubberyCreationForm form("HomeGarden");
        //RobotomyRequestForm form("MYROBOT");
        //PresidentialPardonForm form("PardonMe");
        


        std::cout << "Attempting to sign the form." << std::endl;
        form.beSigned(john); // Assuming AForm has a method to sign the form
        john.signForm(form); // Assuming Bureaucrat has a method to sign forms
        std::cout << "Attempting to execute the form." << std::endl;
        form.execute(john);
        john.executeForm(form); // Assuming Bureaucrat has a method to execute forms
    }
	catch (std::exception &e)
	{
        std::cout << e.what() << std::endl;
    }
    return 0;
}



