#include "RPN.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error\n";
        return 1;
    }
    RPN a(argv[1]);
    try {
        int result = a.count_rpn();
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error\n";
        return 1;
    }

    return 0;
}