#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ifstream input("../day1.in.txt");
    int solution = 0, id;
    vector<int> l1, l2;
    l1.reserve(1000);
    l2.reserve(1000);

    while (input >> id) {
        l1.push_back(id);
        if (input >> id) {
            l2.push_back(id);
        }
    }
    input.close();

    sort(l1.begin(), l1.end());
    sort(l2.begin(), l2.end());

    for (size_t i = 0; i < l1.size(); i++) {
        solution += abs(l1[i] - l2[i]);
    }

    cout << solution << endl;

    return 0;
}