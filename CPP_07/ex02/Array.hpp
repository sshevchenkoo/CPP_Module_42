#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <exception>

template <typename T>
class Array {
private:
    T* data;
    unsigned int length;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif