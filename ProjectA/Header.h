#pragma once
#include <iostream>
#include <deque>
void FillDeque(std::deque <int> &numbers) {
	int temp{ 0 };
	int cnt{ 0 };
	std::cout << "How many numbers do you want to enter?: ";
	std::cin >> cnt;
	for (size_t i{ 0 }; i < cnt; i++) {
		std::cout << "Enter Number " << i+1 << ": ";
		std::cin >> temp;
		numbers.push_back(temp);
	}
}

void NumberRepeat(std::deque <int>& numbers, std::deque <int> &result) {
	size_t cnt{ 0 };
	for (size_t i{ 0 }; i < numbers.size(); i++) {
		for (size_t j{ 0 }; j < numbers.size(); j++) {
			if (numbers[i] == -4222211) {
				break;
			}
			else if (numbers[i] == numbers[j]) {
				cnt++;
				if (cnt > 1) {
					numbers[j] = -4222211;
				}
			}
		}
		if(numbers[i] != -4222211){
		result.push_back(numbers[i]);
		result.push_back(cnt);
		cnt = 0;
		}
	}
}

void DisplayDeque(const std::deque <int> &result) {
	for (size_t i{ 0 }; i < result.size(); i = i+2) {
		std::cout << result[i] << ':' << result[i + 1] << std::endl;
	}
}