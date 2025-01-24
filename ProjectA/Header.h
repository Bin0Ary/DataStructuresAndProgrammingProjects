#include <iostream>
#include <deque>
// Function to get the numbers from the user and store them in a deque
std::deque<int> getNumbers() {
    std::deque<int> numbers;
    std::cout << "Enter the numbers (End with '.'): ";
    int num;
    while (std::cin >> num) {
        numbers.push_back(num);
    }
   
    std::cin.clear();
   
    while (std::cin.get() != '\n');
    return numbers;
}

// Function to calculate the frequency of each number
void calculateAndPrintFrequency(const std::deque<int>& numbers) {
    std::deque<int> counted;
    std::cout << "Frequency of numbers:\n";
    for (int num : numbers) {
        bool alreadyCounted = false;
        for (int countedNum : counted) {
            if (countedNum == num) {
                alreadyCounted = true;
                break;
            }
        }
        if (!alreadyCounted) {
            int count = 0;
            for (int n : numbers) {
                if (n == num) {
                    count++;
                }
            }
            std::cout << num << " : " << count << "\n";
            counted.push_back(num);
        }
    }
}