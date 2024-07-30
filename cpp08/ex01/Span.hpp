#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <limits>

class Span
{
private:
    unsigned int max_size;
    std::vector<int> numbers;
    Span();
public:
    Span(unsigned int N);
    Span(const Span &span);
    Span &operator=(const Span &span);
    ~Span();
    void addNumber(int number);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;
    int size() const;

};

#endif // SPAN_HPP
