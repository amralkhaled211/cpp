#include "PmergeMe.hpp"


void printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}


int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error : nothing to sort !!" << std::endl;
		return 1;
	}

	// std::cout << "hello < " << std::endl;

	///a function that insert to the vector ----- and handle the input this is the first containter 
	std::vector<int> Vector_C;
	Vector_C = Insert_elements(ac, av);
	//printVector(Vector_C);



}