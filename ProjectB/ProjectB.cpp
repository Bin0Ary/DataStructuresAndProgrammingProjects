#include <iostream>
#include <deque>
#include <string>
#include "header.h"
int main() {
	std::string numString;
	std::deque <int> numInt1;
	std::deque <int> numInt2;
	std::deque <std::deque<int>> multInt;
	std::deque <int> resultInt;
	NumberPrompt(numString);
	CleanString(numString);
	FillDeque(numInt1, numInt2, numString);
	Mult(numInt1, numInt2, multInt);
	size_t l = numInt1.size() - 1;
	Add(resultInt, multInt, l);
	DisplayDeque(resultInt);
}
