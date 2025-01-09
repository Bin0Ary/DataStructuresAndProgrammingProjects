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
	size_t carry{ 0 };
	size_t mult{ 0 };
	size_t carryCheck{ 0 };
	// l variable is used to keep track of the number of zeroes to add 
	size_t l = numInt1.size() - 1;
	// i variable is used to keep track of the row in numInt1 deque
	for (size_t i = numInt1.size(); i-- > 0;) {
		std::deque <int> temp;
		carry = 0;
		// j variable is used to keep track of the row
		for (size_t j = numInt2.size(); j-- > 0;) {
			mult = ((numInt1[i] * numInt2[j]) + carry);
			temp.push_front(mult % 10);
			if (j == 0) {
				if (mult > 9) {
					temp.push_front(mult / 10);
					carryCheck = 1;
				}
			}
			carry = 0;
			if (mult > 9) {
				carry = mult / 10;
			}
		}
		if (l > 0 && carryCheck != 1) {
			for (size_t k = l; k-- > 0;) {
				temp.push_front(0);
			}
		}
		else if (carryCheck == 1 && l > 0) {
            for (size_t k = l - 1; k > 0; --k) {
            temp.push_front(0);
            }
		}
		for (size_t k = 0; k < numInt1.size() - 1 - i; ++k) {
			temp.push_back(0);
		}
		carryCheck = 0;
		l--;
		multInt.push_back(temp);
	}
}

void Add(std::deque <int>& resultInt, const std::deque <std::deque<int>>& multInt, size_t& l) {
	unsigned int sum{ 0 };
	unsigned int carry{ 0 };
	for (size_t i = multInt[0].size(); i-- > 0;) {
		sum = 0;
		for (size_t j = multInt.size(); j-- > 0;) {
			sum += multInt[j][i];
		}
		if (carry > 0) {
			sum += carry;
			carry = 0;
		}
		if (sum > 9) {
			carry = sum / 10;
		}
		if(i > 0){
		resultInt.push_front(sum % 10);
		}
		else {
			resultInt.push_front(sum);
		}
	}
}

void DisplayDeque(const std::deque <int>& resultInt) {
	for (auto val : resultInt) {
		std::cout << val;
	}
}
