#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <vector>


template <typename T>
void print(T const &i)
{
	std::cout << i << std::endl;
}

template <typename T>
void iter(T *array, size_t size, void (*f)(T const &))
{
	size_t i = 0;

	while (i < size)
	{
		f(array[i]);
		i++;
	}
}

#endif 