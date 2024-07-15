#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>


int	main()
{
	try
	{
		Bureaucrat bureaucrat("Bureaucrat", 4);
		//std::cout << bureaucrat << std::endl;
		Form form("Form", 4, 1);
		//std::cout << form << std::endl;

		form.beSigned(bureaucrat);
		bureaucrat.signForm(form);
		bureaucrat.decrementGrade(); // here we increment the grade of the bureaucrat to 5
		std::cout << bureaucrat << std::endl;

		form.beSigned(bureaucrat); // here we try to sign the form with the bureaucrat with grade 5
		bureaucrat.signForm(form);// here we try to sign the form with the bureaucrat with grade 5


	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}