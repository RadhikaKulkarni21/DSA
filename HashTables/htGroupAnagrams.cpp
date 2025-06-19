#include <iostream>
#include <unordered_map>
#include <vector>
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

vector<vector<string>> groupAnagrams(const vector<string>& strings) {

	unordered_map<string, vector<string>> anagramGroups;
	for(const string& str: strings){
        // Create the canonical form by sorting the string
	    string canonical = str;
	    sort(canonical.begin(),canonical.end());
	    anagramGroups[canonical].push_back(str);
	}
	vector<vector<string>> result;
	for(const auto& group: anagramGroups){
	    result.push_back(group.second);
	}
	return result;
}

int main(){

    vector<string> input{"listen", "silent", "enlist"};
    vector<vector<string>> result = groupAnagrams(input);
    sort(result[0].begin(), result[0].end());
    sort(input.begin(), input.end());
    cout << "EXPECTED: ";
    printGroups({input});
    cout << "RETURNED: ";
    printGroups(result);
}