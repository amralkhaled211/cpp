#include "Span.hpp"

Span::Span(unsigned int N) : max_size(N) {}


void Span::addNumber(int number)
{
	if (numbers.capacity() >= max_size)
	{
		throw std::logic_error("Span is already full");
	}
	numbers.push_back(number);
}

Span::Span(const Span &span)
{
	*this = span;
}

Span &Span::operator=(const Span &span)
{
	if (this == &span)
	{
		return *this;
	}
	max_size = span.max_size;
	numbers = span.numbers;
	return *this;
}

Span::~Span() {}

int Span::shortestSpan() const
{
	if (numbers.size() < 2)
		{
            throw std::logic_error("Not enough numbers to find a span");
        }
        std::vector<int> sorted_numbers = numbers;
        std::sort(sorted_numbers.begin(), sorted_numbers.end());
		std::cout << "sorted_numbers: ";
		for (size_t i = 0; i < sorted_numbers.size(); ++i)
		{
			std::cout << sorted_numbers[i] << " ";
		}
		std::cout << std::endl;
		//std::cout << "size of sorted_numbers: " << sorted_numbers.size() << std::endl;
        int min_span = std::numeric_limits<int>::max();
        for (size_t i = 1; i < sorted_numbers.size(); ++i)
		{
            int span = sorted_numbers[i] - sorted_numbers[i - 1];
            if (span < min_span) {
                min_span = span;
            }
        }
        return min_span;
}

int Span::longestSpan() const
{
	if (numbers.size() < 2)
	{
		throw std::logic_error("Not enough numbers to find a span");
	}
	int min_number = *std::min_element(numbers.begin(), numbers.end());
	int max_number = *std::max_element(numbers.begin(), numbers.end());
	return max_number - min_number;
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (numbers.size() + std::distance(begin, end) > max_size)
	{
		throw std::logic_error("Span is already full");
	}
	numbers.insert(numbers.end(), begin, end);
}

int Span::size() const
{
	return numbers.size();
}