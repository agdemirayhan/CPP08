#include <iostream>
#include "Span.hpp"
#include <cstdlib>
#include <ctime>

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main() {
    std::srand(std::time(0));

    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        sp.printNumbers();

        sp.shortestSpan();
        sp.longestSpan();

        // BIG CONTAINER TEST
        std::cout << std::endl;
        Span big(5000);
        for (int i = 0; i < 51; ++i)
            big.addNumber(rand());
        std::cout << RED << "Big container test: " << RESET << std::endl;
        big.printNumbers();

        big.shortestSpan();
        big.longestSpan();

        // EMPTY CONTAINER TEST
        std::cout << std::endl;
        Span empty(5);
        for (int i = 0; i < 0; ++i)
            empty.addNumber(rand());
        std::cout << RED << "Empty container test: " << RESET << std::endl;
        empty.printNumbers();

        empty.shortestSpan();
        empty.longestSpan();

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
