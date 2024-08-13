#include "PmergeMe.hpp"


// this would be my example              : 11 7 5 3 20 22 8 6 1 2
//This is would be the main_chain        : 11  5  22  8  2
//This is would be the pinding_chain     : 7   3  20  6  1
 //                                           b     e
//This is would be the sorted_main_chain    : 2  5  8  11  22
//This is would be the sorted_pinding_chain : 1  3  6  7   20
//Now i have to perfum the binary search in here .
//but the way I am going to iterate in the pending_chain is throw the jacobsthal

void sort_vector(std::vector<int>& pinding_chain, std::vector<int>& main_chain, std::vector<int>& sorted_main_chain)
{
    int i = 0;
    int size;
    int pending_num;

    //here i would sort the first element
    sorted_main_chain.insert(sorted_main_chain.begin(), find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]));
    i++;
    size = sorted_main_chain.size();
    std::cout << "size : " << size <<std::endl;
    while (i <= size)///here i might need to change the iterating go jacop stayle
    {
        size = sorted_main_chain.size();
        pending_num = find_pending_elment(pinding_chain, main_chain, sorted_main_chain[i]);/// I might need to return -1 in case i dont find

        ///I have to perform the binary search
        if (pending_num < sorted_main_chain[i + 1])
        {
            //we wanna discharge the rest element from the right side : this mean that the number is samll
            int end = i;
            std::cout << "what is end : "  << end <<  std::endl;
           // int begin = 0;
            int middle = end / 2;
            std::cout << "What is in the middle :" << sorted_main_chain[middle] << "  what is the middle :" << middle<< std::endl;
            break;
        }
        // else
        // {
        //     //we wanna discharge the rest element from the left side : this mean that the number is big

        // }

    }
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cerr << "Error : nothing to sort !!" << std::endl;
		return 1;
	}
	std::vector<int> Vector_C;
	Vector_C = Insert_elements(ac, av);


    //I am dividing the array to 2 chains one bigger and one smaller
	std::vector<int> pending_chain;
    std::vector<int> main_chain;
	divideAndCompare(Vector_C, pending_chain, main_chain);

    //Now i have to sort the main_chain
    std::vector<int> sorted_main_chain = getSortedMainChain(main_chain);
    std::cout << "Large elements: ";
    printVector(main_chain);
	std::cout << "Small elements: ";
    printVector(pending_chain);
    std::cout << "before sorted main chain: ";
    printVector(sorted_main_chain);
    


    sort_vector(pending_chain, main_chain, sorted_main_chain);
    std::cout << "after sorted main chain: ";
    printVector(sorted_main_chain);




    
    


}

































// // Jacobsthal and Jacobsthal-Lucas numbers
//A simple C++ recursive solution to find
// #include <bits/stdc++.h>
// using namespace std;

// // Return nth Jacobsthal number.
// int Jacobsthal(int n)
// {
// 	// base case
// 	if (n == 0)
// 		return 0;

// 	// base case
// 	if (n == 1)
// 		return 1;

// 	// recursive step.
// 	return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
// }

// // Driven Program
// int main()
// {
// 	int n = 6;
// 	cout << "Jacobsthal number: " << Jacobsthal(n) << endl;
// 	return 0;
// }
