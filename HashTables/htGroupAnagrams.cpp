#include "R:\C++\Project1\lcHeader.h"

/*
Implement a function called groupAnagrams() that 
groups a list of strings based on their anagram equivalence.

Consider the following input vector:

strings: {"eat", "tea", "tan", "ate", "nat", "bat"}
After calling groupAnagrams(strings), the result could be 
(order of groups and strings within groups does not matter):
{
    {"eat", "tea", "ate"},
    {"tan", "nat"},
    {"bat"}
}
*/

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