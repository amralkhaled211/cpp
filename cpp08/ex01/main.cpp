
#include "Span.hpp"

int main()
{	
	try
	{
    	Span span(6);
    	span.addNumber(10);
    	span.addNumber(3);
    	span.addNumber(20);
		span.addNumber(5);
		span.addNumber(7);
        int result = span.shortestSpan();
        std::cout << "The shortest span is: " << result << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

    return 0;
}


// int main()
// {

//     try
// 	{
//     	std::vector<int> vec(6000); // Prepare a vector of integers
// 		std::srand( time ( NULL ) );
// 		std::generate(vec.begin(), vec.end(), std::rand); // Fill the vector with random numbers

// 		Span span(6001); // Create a Span object with a maximum size of 1000

//         span.addNumbers(vec.begin(), vec.end()); // Add numbers to the Span object
// 		span.addNumber(1);
//         //span.printNumbers(); // Print the numbers in the Span object
// 		int result = span.shortestSpan();
// 		std::cout << "The shortest span is: " << result << std::endl;
// 		result = span.longestSpan();
// 		std::cout << "The longe1st span is: " << result << std::endl;
// 		std::cout << "size of span numbers: " << span.size() << std::endl;
//     }
// 	catch
// 	(const std::logic_error& e) {
//         std::cerr << e.what() << std::endl;
//     }

//     return 0;
// }