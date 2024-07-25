#include "iter.hpp"


int main()
{
	int array[] = {1, 2, 3, 4, 5};
	iter(array, 5, print);

	std::string array2[] = {"Hello", "World", "!"};
	iter(array2, 3, print);
	return 0;
}