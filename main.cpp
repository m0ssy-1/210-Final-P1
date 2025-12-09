#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

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


    return 0;
}