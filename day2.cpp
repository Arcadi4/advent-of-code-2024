#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ifstream input("../day2.in.txt");
    string line;
    size_t n = 1000;
    int safe = n;
    vector<int> report;

    while (getline(input, line)) {
        stringstream ss(line);
        int level;

        while (ss >> level) {
            report.push_back(level);
        }

        for (size_t i = 1; i < report.size(); i++) {
            if (report.at(i) == report.at(i - 1)) {
                safe--;
                break;
            }
            if (abs(report.at(i) - report.at(i - 1)) > 3) {
                safe--;
                break;
            }
            if ((report.at(i) < report.at(i - 1)) != (report.at(1) < report.at(0))) {
                safe--;
                break;
            }
        }
        report.clear();
    }

    cout << safe << endl;
    return 0;
}