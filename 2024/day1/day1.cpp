#include <fstream>
#include <iostream>
#include <math.h>

int main() {
    std::ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;

    std::vector<int> list1, list2;

    while (std::getline(inputFile, line)) {
        // each line has two numbers separated by 4 spaces, so we can use this to extract the numbers
        int num1, num2;
        inputFile >> num1 >> num2;

        list1.push_back(num1);
        list2.push_back(num2);
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    // Now that they are sorted, we just iterate through list1 and list2

    int n = list1.size();

    std::cout << "Length of list1: " << n << std::endl;

    if (list2.size() != n) {
        std::cerr << "List sizes are not the same" << std::endl;
        return EXIT_FAILURE;
    }

    int sumDistance = 0;

    for (int i = 0; i < n; i++) {
        std::cout << list1[i] << "    " << list2[i] << std::endl;

        sumDistance += abs(list1[i] - list2[i]);
    }

    std::cout << "Answer: " << sumDistance << std::endl;
}