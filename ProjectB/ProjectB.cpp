#include <iostream>
#include <deque>
#include <string>
#include "Header.h"

int main() {
    std::string numString;
    std::deque<int> numInt1;
    std::deque<int> numInt2;
    std::deque<std::deque<int>> multInt;
    std::deque<int> resultInt;

    NumberPrompt(numString);
    CleanString(numString);
    FillDeque(numInt1, numInt2, numString);

    bool isResultNegative = (numInt1[0] < 0) ^ (numInt2[0] < 0);

    if (numInt1[0] < 0) numInt1[0] *= -1;
    if (numInt2[0] < 0) numInt2[0] *= -1;

    Mult(numInt1, numInt2, multInt);
    size_t l = numInt1.size() - 1;
    Add(resultInt, multInt, l);
    DisplayDeque(resultInt, isResultNegative);

    return 0;
}
