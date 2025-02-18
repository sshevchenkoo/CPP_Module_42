#include "Array.hpp"

int main()
{
    try
    {
        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;

        Array<int> intArray(5);
        for (unsigned int i = 0; i < intArray.size(); i++)
            intArray[i] = i * 10;

        std::cout << "intArray contents: ";
        for (unsigned int i = 0; i < intArray.size(); i++)
            std::cout << intArray[i] << " ";
        std::cout << std::endl;

        Array<int> copiedArray = intArray;
        copiedArray[0] = 999;
        std::cout << "Original intArray[0]: " << intArray[0] << std::endl;
        std::cout << "Copied copiedArray[0]: " << copiedArray[0] << std::endl;

        std::cout << "Trying to access out of bounds..." << std::endl;
        std::cout << intArray[10] << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}