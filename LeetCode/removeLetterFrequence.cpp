/*
You are given a 0-indexed string word, consisting of lowercase English letters.
You need to select one index and remove the letter at that index from 
word so that the frequency of every letter present in word is equal.
*/

#include "R:\C++\Project1\lcheader.h"

class Solution{
public:
    bool removeLetter(string s){
        //we store every freq as 0
        int arr[26] = {0};

        //adding freq to each 
        //so a = 1 = 1
        for(char c : s){
            arr[c - 'a']++;
        }

        for(int i = 0; i < 26; i++){
            //if the alphabet does not exist we just move next
          if(!arr[i]) continue;
          //we set whatever freq one down
          arr[i]--;
          unordered_set<int> ust;

          //sets only store unique value
          //so if each alphabet will have equal freq then only 1 will added
          //if we get more than 1 that means there are alphabets with more than one
          for(int x : arr){
            if(x){//if x is zero we are not adding it into the set only <=1 values
                ust.insert(x);
            }
          }

          //if the very first attempt gives a correct answer we don't need to go 
          //through the entire array
          // we are only going to hit if all the frequencies are 1
          if(ust.size() == 1) return true; //short circuit on first success

          //restore freq
          arr[i]++;
        }
        return false;
    }
};

int main(){
    Solution s;
    string st = "aabbcc";
    bool r = s.removeLetter(st);
    r ? cout << "True" : cout << "False";
}

/*
aabbcc, at no given point will we have same frequencies
becuase we need to remove and then check for the frequency not prior to operation

aabbcc arr = [2,2,2]
when we go in the for loop
the array will change to [1,2,2] for a
[2,1,2] for b and [2,2,1] for c
for all three alphabets the size of set will always be 2

on the other hand if we take aabc
the initial array is [2,1,1]
after for loop
the arr will be [1,1,1], hence we hit the required condition in first attempt
so we break out of the loop and return true

the freq is restored just in case for next alphabet for example
aabbccc, here we need the restored freq as we will hit c = 2 at the very last 
for iteration

why only greater then 0 values
because of line 58, we need to remove a letter no matter what but deleteing it from the
string is wrong behaviour
*/