#pragma once
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

// Prompts the user for number inputs
void NumberPrompt(std::string& a) {
    std::cout << "Enter both numbers with one space between them: ";
    std::getline(std::cin, a);
}

// Deletes all null characters at the beginning of a string
void CleanString(std::string& s) {
    s.erase(0, s.find_first_not_of(' '));
}

// Fills two deques with numbers inside the strings by splitting both
void FillDeque(std::deque<int>& numInt1, std::deque<int>& numInt2, const std::string& numString) {
    size_t pos = numString.find(' ');
    std::string num1 = numString.substr(0, pos);
    std::string num2 = numString.substr(pos + 1);

    bool isNegative1 = num1[0] == '-';
    bool isNegative2 = num2[0] == '-';

    if (isNegative1) num1 = num1.substr(1);
    if (isNegative2) num2 = num2.substr(1);

    for (char c : num1) {
        numInt1.push_back(c - '0');
    }

    for (char c : num2) {
        numInt2.push_back(c - '0');
    }

    if (isNegative1) numInt1[0] *= -1;
    if (isNegative2) numInt2[0] *= -1;
}

// Multiplication algorithm for the two deques
void Mult(const std::deque<int>& numInt1, const std::deque<int>& numInt2, std::deque<std::deque<int>>& multInt) {
    size_t carry = 0;
    size_t mult = 0;
    size_t l = 0;

    for (size_t i = numInt1.size(); i-- > 0;) {
        std::deque<int> temp;
        carry = 0;
        for (size_t j = numInt2.size(); j-- > 0;) {
            mult = (numInt1[i] * numInt2[j]) + carry;
            temp.push_front(mult % 10);
            carry = mult / 10;
        }
        if (carry > 0) {
            temp.push_front(carry);
        }
        for (size_t k = 0; k < l; ++k) {
            temp.push_back(0);
        }
        multInt.push_back(temp);
        l++;
    }
}

// Add function, just adds the columns of the multInt deque
void Add(std::deque<int>& resultInt, const std::deque<std::deque<int>>& multInt, size_t& l) {
    unsigned int sum = 0;
    unsigned int carry = 0;
    size_t maxSize = 0;

    for (const auto& row : multInt) {
        if (row.size() > maxSize) {
            maxSize = row.size();
        }
    }

    for (size_t i = 0; i < maxSize; ++i) {
        sum = carry;
        for (const auto& row : multInt) {
            if (row.size() > i) {
                sum += row[row.size() - 1 - i];
            }
        }
        carry = sum / 10;
        resultInt.push_front(sum % 10);
    }

    while (carry > 0) {
        resultInt.push_front(carry % 10);
        carry /= 10;
    }
}

void DisplayDeque(const std::deque<int>& resultInt, bool isResultNegative) {
    if (isResultNegative) {
        std::cout << "-";
    }
    for (auto val : resultInt) {
        std::cout << std::abs(val);
    }
    std::cout << std::endl;
}
