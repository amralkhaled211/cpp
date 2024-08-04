#include "RPN.hpp"

int	main(int ac, char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error : invalid argumants !!" << std::endl;
		return 1;
	}

	RPN	program;
	
	program.Calculator(av[1]);

}
