#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <iostream>
#include <exception>
#include <vector>
#include <list>

class NotFoundException : public std::exception {
public:
    const char* what() const throw() {
        return "Element not found in container";
    }
};

template <typename T>
typename T::iterator easyfind(T &arr, int value)
{
    typename T::iterator i;
    i = std::find(arr.begin(), arr.end(), value);
    if(i == arr.end())
        throw NotFoundException();
    return(i);
}

#endif
