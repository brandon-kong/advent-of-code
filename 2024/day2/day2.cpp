#include <fstream>
#include <iostream>
#include <math.h>
#include <sstream>


bool isAscending(std::vector<int> iterable) {
    int last = iterable[0];

    for (int i = 1; i < iterable.size(); i++) {
        if (iterable[i] <= last) {
            return false;
        }

        last = iterable[i];
    }

    return true;
}

bool isDescending(std::vector<int> iterable) {
    int last = iterable[0];

    for (int i = 1; i < iterable.size(); i++) {
        if (iterable[i] >= last) {
            return false;
        }

        last = iterable[i];
    }

    return true;
}

bool isDifferenceSmall(std::vector<int> iterable) {
    int last = iterable[0];

    for (int i = 1; i < iterable.size(); i++) {
        int difference = abs(iterable[i] - last);
        if (difference > 3 || difference < 1) {
            return false;
        }

        last = iterable[i];
    }

    return true;
}

int main() {
    std::ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return EXIT_FAILURE;
    }

    std::string line;

    std::vector<std::vector<int> > reports;

    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);

        std::vector<int> report;

        int n;

        while (stream >> n) {
            report.push_back(n);
        }

        reports.push_back(report);
    }

    int safeReports = 0;

    for (int i = 0; i < reports.size(); i++) {
        std::vector<int> report = reports[i];
        
        if ((isAscending(report) || isDescending(report)) && isDifferenceSmall(report)) {
            safeReports += 1;
        }
    }

    std::cout << safeReports << std::endl;

    return EXIT_SUCCESS;
}