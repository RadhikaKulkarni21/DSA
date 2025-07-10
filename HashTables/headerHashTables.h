#include <iostream>
#include <unordered_map>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;


void printGroups(const vector<vector<string>>& groups) {
    cout << "{ ";
    for (const auto& group : groups) {
        cout << "( ";
        for (const string& str : group) {
            cout << str << " ";
        }
        cout << ") ";
    }
    cout << "}\n";
};