#include "iter.hpp"

void printInt(int x) {
    std::cout << x << " ";
}

void printString(const std::string& str) {
    std::cout << str << " ";
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"Hello", "World", "!"};

    std::cout << "Integer array: ";
    iter(intArray, 5, printInt);
    std::cout << std::endl;

    std::cout << "String array: ";
    iter(strArray, 3, printString);
    std::cout << std::endl;

    return 0;
}