#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

template <typename T>
void searchAndPrint(T& container, int valueToFind, const std::string& containerName) {
    try {
        typename T::iterator it = easyfind(container, valueToFind);
        std::cout << "Found in " << containerName << ": " << *it << std::endl;
    } catch (const std::exception &e) {
        std::cerr << containerName << ": " << e.what() << " " << valueToFind << std::endl;
    }
}

int main()
{
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);

    std::cout << "---- Vector Example ----" << std::endl;
    std::cout << "Vector: ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    
    searchAndPrint(vec, 20, "vector");
    searchAndPrint(vec, 40, "vector");

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    
    std::cout << "\n---- List Example ----" << std::endl;
    std::cout << "List: ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << " ";
    std::cout << std::endl;

    searchAndPrint(lst, 1, "list");
    searchAndPrint(lst, 5, "list");

    return 0;
}
