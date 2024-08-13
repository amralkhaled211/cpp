#include "PmergeMe.hpp"

std::vector<int> Insert_elements(int ac, char **av)
{
    std::vector<int> elements;
    for (int i = 1; i < ac; i++)
    {
        std::stringstream ss((std::string(av[i])));
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
        // print the element 
       // std::cout << value << std::endl;
    }
    return elements;
}


void printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void divideAndCompare(const std::vector<int>& input, std::vector<int>& smallElements, std::vector<int>& largeElements)
{
    for (size_t i = 0; i < input.size(); i += 2)
    {
        if (i + 1 < input.size())
        {
            if (input[i] < input[i + 1])
            {
                smallElements.push_back(input[i]);
                largeElements.push_back(input[i + 1]);
            }
            else
            {
                smallElements.push_back(input[i + 1]);
                largeElements.push_back(input[i]);
            }
        }
        //else
        //{
        //    // Handle the case where there's an odd number of elements
        //    smallElements.push_back(input[i]);
        //}
    }
}


std::vector<int> getSortedMainChain(const std::vector<int>& main_chain)
{
    std::vector<int> sorted_chain = main_chain;
    std::sort(sorted_chain.begin(), sorted_chain.end());
    return sorted_chain;
}


int find_pending_elment(std::vector<int>& pending_chain, std::vector<int>& main_chain, int value_sorted_main_chain)
{
    int postion = 0;
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it)
    {
        if (*it == value_sorted_main_chain)
        {
            break;
        }
        postion++;
    }
    return pending_chain[postion];
    // I might need to improve this function and handle out of range 
}