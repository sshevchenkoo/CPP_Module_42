#include "easyfind.hpp"

int main() {
    try {
        int arr[] = {10, 20, 30, 40, 50};
        std::vector<int> vec(arr, arr + 5);
        std::vector<int>::iterator it = easyfind(vec, 30);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        int arr2[] = {100, 200, 300, 400};
        std::list<int> lst(arr2, arr2 + 4);
        std::list<int>::iterator it = easyfind(lst, 500);
        std::cout << "Found: " << *it << std::endl;
    } catch (const NotFoundException& e) {
        std::cout << e.what() << std::endl;
    }
    
    return 0;
}