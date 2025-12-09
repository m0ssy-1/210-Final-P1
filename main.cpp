#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

void printAirportsInRange(const std::map<std::string, int> &traffic, int low, int high) {
    std::cout << "\nAirports with traffix in range [" << low << ", " << high << "]:\n";
    for (const auto &entry : traffic) {
        if (entry.second >= low && entry.second <= high) {
            std::cout << entry.first << " " << entry.second << '\n';
        }
    }
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
    for (const auto &entry : traffic) {
        std::cout << entry.first << " " << entry.second << '\n';
    }

    int maxCount = 0;
    for (const auto &entry : traffic) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
        }
    }

    std::cout << "\nBusiest airports with count " << maxCount << ":\n";
    for (const auto &entry : traffic) {
        if (entry.second == maxCount) {
            std::cout << entry.first << " " << entry.second << '\n';
        }
     }

     printAirportsInRange(traffic, 5, 8);
     printAirportsInRange(traffic, 9, 12);

    return 0;
}