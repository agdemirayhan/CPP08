#include <iostream>
#include "Span.hpp"
#include <cstdlib>

int main() {
    std::srand(std::time(0));
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        Span big(5000);
        for (int i = 0; i < 5000; ++i)
            big.addNumber(rand());

        std::cout << "Big span test: " << std::endl;
        std::cout << "Shortest: " << big.shortestSpan() << std::endl;
        std::cout << "Longest: " << big.longestSpan() << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
