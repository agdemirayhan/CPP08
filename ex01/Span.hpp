#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>

class Span {
private:
    unsigned int _maxSize;
    std::vector<int> _numbers;

public:
    Span();
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    Span(unsigned int N);

    void addNumber(int number);

    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end) {
        if (_numbers.size() + std::distance(begin, end) > _maxSize)
            throw std::runtime_error("Cannot add: exceeding max size");
        _numbers.insert(_numbers.end(), begin, end);
    }

    int shortestSpan() const;
    int longestSpan() const;
    void printNumbers() const;

};

#endif
