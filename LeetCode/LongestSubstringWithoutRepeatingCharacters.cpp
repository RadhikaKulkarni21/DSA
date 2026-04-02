/*
Given a string s, find the length of the longest substring
without duplicate characters.
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    int lengthOfLongestSubstring(string str){
        unordered_map<char, int> freq;//store freq of each char in str
        int i,j = 0;//sliding window concept
        int length = 0;//result len string

        for(i = 0, j = 0; j < str.size(); j++){
            //check freq of each char
            //initially iteration, all will be zero
            if(freq[str[j]] > 0){
                //when freq is greater than 0, we move i to the next point
                //where the char was found
                //a appears at 0 then at 3
                //so we start checking for new substring from that point
                i = max(freq[str[j]], i);
            }
            //update length
            length = max(j - i + 1, length);
            //update frequency of each character
            freq[str[j]] = j + 1;
        }
        return length;
    }
};

int main(){
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str);
}

/*Now we hit ;'a' again

chars[s[3]] =  'a' =  1 > 0
if runs, max(3, 1) so i = 3
lenght = 3
udpdated index for 'a' = 4
now longest string is bca
*/
