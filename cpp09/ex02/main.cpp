#include "PmergeMe.hpp"

void processChains_vecotr(const std::vector<int>& Vector_C)
{
    std::vector<int> pending_chain;
    std::vector<int> main_chain;
    divideAndCompare(Vector_C, pending_chain, main_chain);
    std::vector<int> sorted_main_chain = getSortedMainChain(main_chain);
    std::vector<int> vector_sorted = sort_container(pending_chain, main_chain, sorted_main_chain);
    std::cout << "After  : ";
    printVector(vector_sorted);
}

void processChains_deque(const std::deque<int>& Deque_C)
{
    std::deque<int> pending_chain;
    std::deque<int> main_chain;
    divideAndCompare(Deque_C, pending_chain, main_chain);
    std::deque<int> sorted_main_chain = getSortedMainChain(main_chain);
    std::deque<int> vector_sorted = sort_container(pending_chain, main_chain, sorted_main_chain);
    //std::cout << "After  : ";
    //printDeque(vector_sorted);
}


int	main(int ac, char **av)
{
	if (ac == 1 || ac == 2)
	{
		std::cerr << "Error : nothing to sort !!" << std::endl;
		return 1;
	}
    clock_t start = clock();
	std::vector<int> Vector_C = Insert_elements<std::vector<int> >(ac, av);
    if (Vector_C.empty())
    {
        return 1;
    }
    std::cout << "before : ";
    printVector(Vector_C);
    processChains_vecotr(Vector_C);
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << Vector_C.size() << " elements with std::vector: " <<  std::fixed << std::setprecision(5) << duration << " us" << std::endl;
    //std::cout << "Number of comparisons: " << comp << std::endl;

    comp = 0;
    //================================================================================================

    clock_t start1 = clock();
    std::deque<int> Deque_C = Insert_elements<std::deque<int> >(ac, av);
    if (Deque_C.empty())
    {
        return 1;
    }
    //std::cout << "before : ";
    //printDeque(Deque_C);
    //std::cout << "deque size: " << Deque_C.size() << std::endl;
    processChains_deque(Deque_C);
    clock_t end1 = clock();
    double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << Vector_C.size() << " elements with std::deque:  " <<  std::fixed << std::setprecision(5) << duration1 << " us" << std::endl;
    //std::cout << "Number of comparisons: " << comp << std::endl;
    return 0;
}




