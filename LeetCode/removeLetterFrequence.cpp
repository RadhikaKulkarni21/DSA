/*
You are given a 0-indexed string word, consisting of lowercase English letters.
You need to select one index and remove the letter at that index from 
word so that the frequency of every letter present in word is equal.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    bool removeLetter(string s){
        int arr[26] = {0};

        for(char c : s){
            arr[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
          if(!arr[i]) continue;
          
          arr[i]--;
          unordered_set<int> ust;

          for(int x : arr){
            if(x){
                ust.insert(x);
            }
          }
          
          if(ust.size() == 1) return true;

          arr[i]++;
        }
        return false;
    }
};

int main(){
    Solution s;
    string st = "abcc";
    bool r = s.removeLetter(st);
    r ? cout << "True" : cout << "false";
}