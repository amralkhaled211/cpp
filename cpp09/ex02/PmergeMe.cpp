#include "PmergeMe.hpp"

std::vector<int> Insert_elements(int ac, char **av)
{
    std::vector<int> elements;
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss(std::string(av[i]));
        int value;
        if (ss >> value && value >= 0)
            elements.push_back(value);
		else
		{
			//throw std::invalid_argument("Invalid argument: non-integer or negative value encountered");
			std::cerr << "Error : non-valid value encountered\n";
			elements.clear();
			break;
		}
    }
    return elements;
}
