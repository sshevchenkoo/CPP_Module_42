#include "Span.hpp"

Span::Span(unsigned int N) : maxSize(N) {}

void Span::addNumber(int n)
{
    if (numbers.size() >= maxSize)
        throw (Span::ArrayFullException());
    numbers.push_back(n);
}

int Span::shortestSpan() const
{
    if (numbers.size() < 2)
        throw Span::LogicException();
    
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    
    int minSpan = sortedNumbers[1] - sortedNumbers[0];
    for (size_t i = 1; i < sortedNumbers.size() - 1; ++i)
    {
        int span = sortedNumbers[i + 1] - sortedNumbers[i];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (numbers.size() < 2)
        throw Span::LogicException();
    
    int minVal = *std::min_element(numbers.begin(), numbers.end());
    int maxVal = *std::max_element(numbers.begin(), numbers.end());
    
    return maxVal - minVal;
}

const char* Span::ArrayFullException::what() const throw()
{
    return "Array is full";
}

const char* Span::LogicException::what() const throw()
{
    return "Not enough numbers to compute span";
}
