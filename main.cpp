#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

void printAirportsInRange(const std::map<std::string, int> &traffic, int low, int high) {
    std::cout << "\nAirports with traffix in range [" << low << ", " << high << "]:\n";
    std::cout << std::left << std::setw(10) << "Airport" << " | "
              << std::right << std::setw(7)  << "Traffic" << "\n";

    for (const auto &entry : traffic) {
        if (entry.second >= low && entry.second <= high) {
            std::cout << std::left << std::setw(10) << entry.first << " | "
                      << std::right << std::setw(7)  << entry.second << "\n";
        }
    }
    std::cout << "\n";
}

int main () {

    std::map<std::string, int> traffic;

    std::ifstream in("../final.codes.txt");
    if (!in) {
        cout << "Error opening file." << endl;
        return 1;
    }

    std::string origin;
    std::string destination;

    while (in >> origin >> destination) {
        traffic[origin]++;
        traffic[destination]++;
    }

    std::cout << "All airport traffic counts:\n";
    std::cout << std::left << std::setw(10) << "Airport" << " | "
              << std::right << std::setw(7)  << "Traffic" << "\n";
    for (const auto &entry : traffic) {
        std::cout << std::left << std::setw(10) << entry.first << " | "
                  << std::right << std::setw(7) << entry.second << '\n';
    }
    std::cout << "\n";

    int maxCount = 0;
    for (const auto &entry : traffic) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }

    std::cout << "\nBusiest airports with count " << maxCount << ":\n";
    std::cout << std::left << std::setw(10) << "Airport" << " | "
              << std::right << std::setw(7) << "Traffic" << "\n";

    for (const auto &entry : traffic) {
        if (entry.second == maxCount) {
            std::cout << std::left << std::setw(10) << entry.first << " | " 
                      << std::right << std::setw(7) << entry.second << '\n';
        }
     }
     std::cout << "\n";

     printAirportsInRange(traffic, 5, 8);
     printAirportsInRange(traffic, 9, 12);

    return 0;
}