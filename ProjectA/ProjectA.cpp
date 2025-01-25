#include <iostream>
#include <deque>
#include "Header.h"

int main() {
    std::deque<int> numbers = getNumbers();
    Frequency(numbers);
    return 0;
}
