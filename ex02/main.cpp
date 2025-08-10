#include <iostream>
#include "MutantStack.hpp"
#include <list>

#define CYAN "\033[36m"
#define RESET "\033[0m"

template <typename C>
void printContainer(const C &c, const std::string &name)
{
    std::cout << name << " [size=" << c.size() << "]:";
    for (typename C::const_iterator it = c.begin(); it != c.end(); ++it)
    {
        std::cout << ' ' << *it;
    }
    std::cout << '\n';
}

void testMutantStack()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    printContainer(mstack, "MutantStack after pushing 5 and 17");

    std::cout << "top: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "size: "<< mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    printContainer(mstack, "MutantStack after pushing more elements");

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Iterating through MutantStack:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);
}

void listTest()
{
    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);

    printContainer(mlist, "std::list after pushing 5 and 17");

    std::cout << "back: " << mlist.back() << std::endl;

    mlist.pop_back();

    std::cout << "size: " << mlist.size() << std::endl;

    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    mlist.push_back(0);

    std::list<int>::iterator it = mlist.begin();
    std::list<int>::iterator ite = mlist.end();

    ++it;
    --it;
    std::cout << "Iterating through std::list:" << std::endl;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

int main()
{

    std::cout << CYAN << "Testing MutantStack" << RESET << std::endl;
    testMutantStack();
    std::cout << std::endl;

    std::cout << CYAN << "Testing std::list" << RESET << std::endl;
    listTest();
    std::cout << std::endl;

    return 0;
}
