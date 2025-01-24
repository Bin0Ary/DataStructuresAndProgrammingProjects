#include <iostream>
#include <deque>
#include "Header.h"

int main() {
    std::deque<int> numbers = getNumbers();
    calculateAndPrintFrequency(numbers);
    return 0;
}