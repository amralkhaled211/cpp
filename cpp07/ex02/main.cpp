#include <iostream>
#include <cstring> // For std::memset
#include "Array.hpp"


int main()
{
    // Create an Array of integers with 5 elements
    Array<char> intArray(5);

    // Assign values to the array elements
    for (size_t i = 0; i < intArray.size(); ++i)
	{
        intArray[i] = "abcde"[i];
    }
    std::cout << intArray.size() << std::endl;
    try
    {
        intArray[7] = '1';
        /* code */
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "Array elements:\n";
    for (size_t i = 0; i < intArray.size(); ++i)
    {
        std::cout << intArray[i] << "\n";
    }
    std::cout << std::endl;

    // Create a copy of the first array
    //Array<char> copiedArray = intArray;
    Array<char> copiedArray(intArray);


    copiedArray[3] = '2';
    std::cout << "Copied array elements: ";
    for (size_t i = 0; i < copiedArray.size(); ++i) {
        std::cout << copiedArray[i] << " ";
    }
    std::cout << std::endl;



    // Display the values in the array
    return 0;
}