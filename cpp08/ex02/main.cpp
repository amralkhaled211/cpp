// main.cpp
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "MutantStack.hpp"

int main()
{
    
    
    // std::cout << std::endl;

    // MutantStack of integers using std::list as the underlying container
    MutantStack<int, std::list<int> > listStack;
    listStack.push(7);
    listStack.push(8);
    listStack.push(9);

    std::cout << "List Stack (std::list): ";
    for (MutantStack<int, std::list<int> >::iterator it = listStack.begin(); it != listStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}