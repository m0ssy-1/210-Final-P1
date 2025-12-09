#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;
//Milestone 3: Add a function that prints only airports whose traffic counts fall within a specified inclusive range [low, high].

//Your driver program should build the map and call the function at least twice with different ranges, clearly showing which airports fall in each range. Do not code user input. 

void printAirportsInRange(const std::map<std::string, int %traffic, int low, int high) {
    std::cot << "\nAirports with traffix"
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


    return 0;
}