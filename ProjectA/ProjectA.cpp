#include <iostream>
#include <deque>
#include "Header.h"
int main() {
	std::deque <int> numbers;
	std::deque <int> result;
	FillDeque(numbers);
	NumberRepeat(numbers, result);
	DisplayDeque(result);
}