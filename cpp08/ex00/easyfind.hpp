#ifndef EAASYFIND_HPP
#define EAASYFIND_HPP

#include <iostream>
#include <algorithm>

// template <typename T>

// int easyfind(T &container, int value)
// {
// 	typename T::iterator it = std::find(container.begin(), container.end(), value);
// 	if (it == container.end())
// 		throw std::exception();
// 	return *it;
// }

template <typename T>
int easyfind(T &container, int value)
{
    for (typename T::iterator it = container.begin(); it != container.end(); ++it)
    {
        if (*it == value)
        {
            return *it;
        }
    }
    throw std::exception();
}

#endif