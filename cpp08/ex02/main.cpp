// main.cpp
#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "MutantStack.hpp"

int main()
{
    // MutantStack of integers using default container (std::deque)
    MutantStack<int> defaultStack;
    defaultStack.push(1);
    defaultStack.push(2);
    defaultStack.push(3);

    //defaultStack.pop();
    //defaultStack.pop();
    //defaultStack.pop();
    if (!defaultStack.empty())
    {
        std::cout << "Default Stack (std::deque): ";
        for (MutantStack<int>::iterator it = defaultStack.begin(); it != defaultStack.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Default Stack (std::deque) is empty." << std::endl;
    }

    // // MutantStack of integers using std::vector as the underlying container
    // MutantStack<int, std::vector<int> > vectorStack;
    // vectorStack.push(4);
    // vectorStack.push(5);
    // vectorStack.push(6);

    // std::cout << "Vector Stack (std::vector): ";
    // for (MutantStack<int, std::vector<int> >::iterator it = vectorStack.begin(); it != vectorStack.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    // // MutantStack of integers using std::list as the underlying container
    // MutantStack<int, std::list<int> > listStack;
    // listStack.push(7);
    // listStack.push(8);
    // listStack.push(9);

    // std::cout << "List Stack (std::list): ";
    // for (MutantStack<int, std::list<int> >::iterator it = listStack.begin(); it != listStack.end(); ++it) {
    //     std::cout << *it << " ";
    // }
    // std::cout << std::endl;

    return 0;
}