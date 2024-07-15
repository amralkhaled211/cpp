#include "Bureaucrat.hpp"
#include <iostream>


int	main()
{
	try
	{
		Bureaucrat b("b", 3);
		std::cout << b << std::endl;
		b.incrementGrade();
		std::cout << b << std::endl;
		b.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}