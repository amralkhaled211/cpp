#include "PmergeMe.hpp"

void printPending(std::vector<int>& pending_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
{
    for (size_t i = 0; i < pending_chain.size(); i++)
    {
        int value = sorted_main_chain[i];
        int index = find_pending_elment(pending_chain, main_chain, value);
        std::cout << "(" << value << ", " << index << ") ";
    }
    std::endl(std::cout);
}

void printVector_B(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        if (i + 1 < vec.size())
        {
            std::cout << "(" << vec[i] << ", " << vec[i + 1] << ") ";
        }
        else
        {
            std::cout << "(" << vec[i] << ", " << "null" << ") "; // Handle the case where the vector has an odd number of elements
        }
    }
    std::cout << std::endl;
}

void printVector(const std::vector<int>& vec)
{
    for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
	{
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}