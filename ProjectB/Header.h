#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <deque>
// Prompts the user for number inputs
void NumberPrompt(std::string& a) {
	std::cout << "Enter both numbers with one space between them: ";
	std::getline(std::cin, a);
}
/*Deletes all null characters at the begining of a string
by shifting all characters by one to the left everytime
a null character is read, it will stop after reading
the first non null character*/
void CleanString(std::string& s) {
	for (size_t i{ 0 }; i < s.size(); i) {
		if (s[i] == ' ') {
			for (size_t j{ i + 1 }; j <= s.size(); j++) {
				s[j - 1] = s[j];
			}
		}
		else if (s[i] != ' ') {
			return;
		}
	}
}
/*Fills two deques with numbers inside the strings*/
void FillDeque(std::deque <int>& numInt1, std::deque <int>& numInt2, const std::string& numString) {
	size_t pos{ 0 };
	for (size_t i{ 0 }; i < numString.size(); ++i) {
		if (numString[i] == ' ') { pos = i + 1; break; }
		else {
			numInt1.push_back(numString[i] - 48);
		}
	}
	for (size_t i{ pos }; i < numString.size(); ++i) {
		numInt2.push_back(numString[i] - 48);
	}
}
/* Multiplication algorithm for the two deques*/
void Mult(const std::deque <int>& numInt1, const std::deque <int>& numInt2, std::deque <std::deque<int>>& multInt) {
	for (size_t i = 0; i < numInt1.size(); ++i) {
		std::deque<int> temp(numInt1.size() + numInt2.size(), 0);
		size_t carry = 0;

		for (size_t j = 0; j < numInt2.size(); ++j) {
			size_t mult = (numInt1[numInt1.size() - 1 - i] * numInt2[numInt2.size() - 1 - j]) + carry;
			temp[temp.size() - 1 - j - i] = mult % 10;
			carry = mult / 10;
		}
		if (carry > 0) {
			temp[temp.size() - 1 - numInt2.size() - i] = carry;
		}
		multInt.push_back(temp);
	}
}
// Adds the columns in the deque and pushfronts into resultInt
void Add(std::deque <int>& resultInt, const std::deque <std::deque<int>>& multInt) {
	size_t maxSize = multInt[0].size();
	resultInt.resize(maxSize, 0);
	unsigned int carry = 0;

	for (size_t i = 0; i < maxSize; ++i) {
		unsigned int sum = carry;
		for (const auto& row : multInt) {
			if (i < row.size()) {
				sum += row[row.size() - 1 - i];
			}
		}
		carry = sum / 10;
		resultInt[maxSize - 1 - i] = sum % 10;
	}
	if (carry > 0) {
		resultInt.push_front(carry);
	}
}

void DisplayDeque(const std::deque <int>& resultInt) {
	for (auto val : resultInt) {
		std::cout << val;
	}
}