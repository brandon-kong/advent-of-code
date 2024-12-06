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

bool isSafeReport(std::vector<int> report) {
    return ((isAscending(report) || isDescending(report)) && isDifferenceSmall(report));
}

std::vector<std::vector<int> > getAllVectorsWithoutEach(std::vector<int> iterable) {
    std::vector<std::vector<int> > res;

    for (int i = 0; i < iterable.size(); i++) {
        std::vector<int> newVector;

        for (int j = 0; j < iterable.size(); j++) {
            if (i != j) {
                newVector.push_back(iterable[i]);
            }
        }

        res.push_back(newVector);
    }

    return res;
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
    int safeReportsWhenRemoving = 0;

    for (int i = 0; i < reports.size(); i++) {
        std::vector<int> report = reports[i];

        // Part 1
        if (isSafeReport(report)) {
            safeReports += 1;
            safeReportsWhenRemoving += 1;
        }
        else {
            // Part 2
            std::vector<std::vector<int> > vectorsWithout = getAllVectorsWithoutEach(report);

            for (int j = 0; j < vectorsWithout.size(); j++) {
                std::vector<int> newReport = vectorsWithout[j];
                

                if (isSafeReport(newReport)) {
                    std::cout << "YAYY" << std::endl;
                    safeReportsWhenRemoving += 1;
                    continue;
                }
            }
        }
    }

    // Part 1
    std::cout << safeReports << std::endl;

    // Part 2
    std::cout << safeReportsWhenRemoving << std::endl;

    return EXIT_SUCCESS;
}