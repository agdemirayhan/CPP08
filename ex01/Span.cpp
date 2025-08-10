#include "Span.hpp"
#include <iostream>

#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

Span::Span(unsigned int N) : _maxSize(N) {}

Span::~Span() {}

void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize)
        throw std::runtime_error("Cannot add number: Span is full");
    _numbers.push_back(number);
}

int Span::shortestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    int minSpan = std::numeric_limits<int>::max();
    int num1 = sorted[0];
    int num2 = sorted[1];
    for (size_t i = 1; i < sorted.size(); ++i) {
        int diff = sorted[i] - sorted[i - 1];
        if (diff < minSpan)
        {
            minSpan = diff;
            num1 = sorted[i - 1];
            num2 = sorted[i];     
        }
    }
    std::cout << std::endl;
    std::cout << CYAN << "SHORTEST:" << RESET << std::endl;
    std::cout << "Shortest span between " << num1 << " and " << num2 << " => " << num2 - num1 <<std::endl;
    return minSpan;
}

int Span::longestSpan() const {
    if (_numbers.size() < 2)
        throw std::runtime_error("Not enough numbers to find a span");

    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());

    std::cout << std::endl;
    std::cout << CYAN << "LONGEST:" << RESET << std::endl;
    std::cout << "Longest span between " << maxVal << " and " << minVal << " => " << maxVal - minVal <<std::endl;

    return maxVal - minVal;
}


void Span::printNumbers() const {
    if (_numbers.size() > 50) {
        std::cout << "[Container has " << _numbers.size() << " elements. Not displaying.]" << std::endl;
        return;
    }
    std::cout << GREEN <<"Numbers in Container: " << RESET << "{";
    for (size_t i = 0; i < _numbers.size(); ++i) {
        if(i != _numbers.size() - 1)
        {
            std::cout << _numbers[i] << ", ";
        } else
        {
            std::cout << _numbers[i];
        }
    }
    std::cout << "}" << std::endl;
}
