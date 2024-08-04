#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <string>

// int main() {
//     // Create an ifstream object to open a file
//     std::ifstream inputFile("data.csv");

//     // Check if the file is open
//     if (!inputFile.is_open()) {
//         std::cerr << "Error opening file" << std::endl;
//         return 1;
//     }

//     // Read the file line by line
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::cout << line << std::endl;
//     }

//     // Close the file
//     inputFile.close();

//     return 0;
// }


int main(int ac, char **av)
{
    if (ac != 2)
	{
		std::cout << "Error: could not open file" << std::endl;
		return (1);
	}
    
    BitcoinExchange program;


    program.Exchanger(av[1]);


    return 0;
}