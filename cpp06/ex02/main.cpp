
#include "Base.hpp"

int     main( void )
{
    Base*   a = generate();

    std::cout << "/* **************************************** */" << std::endl;

    std::cout << "a* = "; identify( a );
    std::cout << "a& = \n"; identify( *a ); std::cout << std::endl;

    std::cout << "/* ***************************************** */" << std::endl;


    delete a;

    return (0);
}