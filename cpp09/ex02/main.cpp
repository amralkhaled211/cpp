#include "PmergeMe.hpp"


void processChains(const std::vector<int>& Vector_C)
{
    std::vector<int> pending_chain;
    std::vector<int> main_chain;
    divideAndCompare(Vector_C, pending_chain, main_chain);
    std::vector<int> sorted_main_chain = getSortedMainChain(main_chain);
    // std::cout << "main_chain elements: ";
    // printVector_B(sorted_main_chain);
    // std::cout << "pending_chain elements: ";
    // printPending(pending_chain, main_chain, sorted_main_chain);
    std::vector<int> vector_sorted = sort_vector(pending_chain, main_chain, sorted_main_chain);
    printVector(vector_sorted);
}

/// i have 4 10 7 5 9 1 for this case 11 comp
int	main(int ac, char **av)
{
	if (ac == 1 || ac == 2)
	{
		std::cerr << "Error : nothing to sort !!" << std::endl;
		return 1;
	}
    clock_t start = clock();
	std::vector<int> Vector_C = Insert_elements(ac, av);
    printVector(Vector_C);
    if (Vector_C.empty())
    {
        return 1;
    }
    std::cout << "size of big array: " << Vector_C.size() << std::endl;
    processChains(Vector_C);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << Vector_C.size() << " elements with std::vector: " <<  std::fixed << std::setprecision(5) << duration << " us" << std::endl;

    return 0;
}













//debugging and explaining the code 
// int	main(int ac, char **av)
// {
// 	if (ac == 1)
// 	{
// 		std::cerr << "Error : nothing to sort !!" << std::endl;
// 		return 1;
// 	}
// 	std::vector<int> Vector_C = Insert_elements(ac, av);
//     if (Vector_C.empty())
//         return 1;
//     //I am dividing the array to 2 chains one bigger and one smaller
// 	std::vector<int> pending_chain;
//     std::vector<int> main_chain;
// 	divideAndCompare(Vector_C, pending_chain, main_chain);

//     //Now i have to sort the main_chain
//     std::vector<int> sorted_main_chain = getSortedMainChain(main_chain);
//     std::cout << "main_chain elements: ";
//     printVector_B(main_chain);
// 	   std::cout << "pending_chain elements: ";
//     printVector_B(pending_chain);
//     std::cout << "sorted main chain: ";
//     printVector(sorted_main_chain);
//     std::cout << "print pinding with sorted main_chain elments : ";
//     printPending(pending_chain, main_chain, sorted_main_chain);
//     std::vector<int> vector_sorted  = sort_vector1(pending_chain, main_chain, sorted_main_chain);
//     std::cout << "after sorted vector chain: ";
//     printVector(vector_sorted);
// }



