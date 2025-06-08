#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./bitcoin [file]" << std::endl;
        return 1;
    }
    try
    {
        BitcoinExchange exchenge;
        exchenge.execute(argv[1]);    
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
    }
     return 0;
}