#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//We are traversing the string from left to right
//hence the new string will have elements from right to left
//we upper all the chars, add - after 'k' value hits
//remove edge cases

class Solution{
    //we need to declare everything public to access in main function
    public:
    string licensePlateFormatting(string s, int k){
        //we'll count the k value here
        //each time k = counter, counter reset
        int counter = 0;
        string lpf = "";

        for(int i = s.size() - 1; i >= 0;i--){
            if(s[i] != '-'){
                lpf.push_back(toupper(s[i]));
                counter++;
            }
            if(counter == k){
                lpf.push_back('-');
                counter = 0;
            }
        }
        //we need to also make sure that once the string is traversed
        //and reached the end which also happens to be counter == k
        //to remove the last '-' we appeneded
        //hence we check if the size is greater and 
        //back of the stack is '-'
        if(lpf.size() > 0 && lpf.back() == '-'){
            lpf.pop_back();//this is remove the unnecessary - at the ends
        }
        
        //one final reverse
        reverse(lpf.begin(),lpf.end());
        return lpf;
    }
};

int main(){
    Solution newSolution;
    string str = "5F3Z-2e-9-w";
    int k = 4;
    
    string result = newSolution.licensePlateFormatting(str,k);
    cout<<str<<endl<<result;
}

/*
You are given a license key represented as a string s that consists 
of only alphanumeric characters and dashes. 
The string is separated into n + 1 groups by n dashes. You are also given an integer k.

We want to reformat the string s such that 
each group contains exactly k characters, 
except for the first group, 
which could be shorter than k but still must contain at least one character. 
Furthermore, there must be a dash inserted between two groups, 
and you should convert all lowercase letters to uppercase.

Return the reformatted license key.

Example 1:

Input: s = "5F3Z-2e-9-w", k = 4
Output: "5F3Z-2E9W"
Explanation: The string s has been split into two parts, each part has 4 characters.
Note that the two extra dashes are not needed and can be removed.
*/