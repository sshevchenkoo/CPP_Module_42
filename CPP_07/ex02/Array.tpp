#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(nullptr), length(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : length(n)
{
    data = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : length(other.length)
{
    data = new T[length];
    for (unsigned int i = 0; i < length; i++) {
        data[i] = other.data[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        delete[] data;
        length = other.length;
        data = new T[length];
        for (unsigned int i = 0; i < length; i++)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= length)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= length) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return length;
}

#endif