#include <iostream>
#include <cstring> // For std::memset
#include "Array.hpp"


int main()
{
    // Create an Array of integers with 5 elements
    try
    {
        Array<char> intArray(5);
    
        // Assign values to the array elements
        for (size_t i = 0; i < intArray.size(); ++i)
	    {
            intArray[i] = "abcde"[i];
        }
        // Display the values in the array
        std::cout << intArray.size() << std::endl;

        //try to access out of bounds
        //intArray[6] = '1';

        std::cout << "Array elements:\n";
        for (size_t i = 0; i < intArray.size(); ++i)
        {
            std::cout << intArray[i] << ", ";
        }
        std::cout << std::endl;



        // // Create a copy of the array
        // Array<char> copiedArray(intArray);
        // copiedArray[3] = '2';
        // std::cout << "Copied array elements:\n ";
        // for (size_t i = 0; i < copiedArray.size(); ++i)
        // {
            // std::cout << copiedArray[i] << ", ";
        // }
        // std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    //std::cout << "End of main" << std::endl;
    
    return 0;
}