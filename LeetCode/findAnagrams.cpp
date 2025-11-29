/*
anagrams
a = ["tea","pea","act"]
b = ["ate", "eat", "acts"]
how many characters are needed to be changed to get the anagrams for each of it?
result [0,1,-1]
acts.length != act.length,hence return -1
 */

#include "R:\C++\Project1\lcHeader.h"

vector<int> anagramChanges(vector<string> a,  vector<string> b) {
    vector<int> result;

    //min as to check if anagram exists 
    size_t n = min(a.size(), b.size());
    for (size_t i = 0; i < n; ++i) {
         string s1 = a[i], s2 = b[i];

        if (s1.length() != s2.length()) {
            //since we are looping this works as this
            //will not push it all the way to the back
            result.push_back(-1); // cannot be anagrams
            continue;
        }

        //taking array of 26 and all value to 0 assuming every str is anagram
        int count1[26] = {0};
        int count2[26] = {0};

        for (char c : s1) count1[c - 'a']++;
        for (char c : s2) count2[c - 'a']++;

        int changes = 0;
        for (int j = 0; j < 26; ++j) {
            if (count1[j] > count2[j]) {
                changes += count1[j] - count2[j];
            }
        }

        result.push_back(changes); // 0 if already anagrams
    }

    return result;
}

int main() {
    vector<string> a = {"abc", "aeb", "abcd"};
    vector<string> b = {"bca", "ba", "abdc"};

    vector<int> res = anagramChanges(a, b);
    for (int x : res) {
        cout << x << " ";
    }
    cout << endl; // Output: 0 -1 0

    return 0;
}
