#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>
#include <iostream>

class Span 
{
    private:
        std::vector<int> numbers;
        unsigned int maxSize;

    public:
        Span(unsigned int N);
        void addNumber(int n);
        int shortestSpan() const;
        int longestSpan() const;

        template <typename Iterator>
        void addNumbers(Iterator begin, Iterator end);

        class	ArrayFullException : public std::exception
        {
	        public:
		        virtual const char	*what() const throw();
        };
        class	LogicException : public std::exception
        {
	        public:
		        virtual const char	*what() const throw();
        };
};

#endif