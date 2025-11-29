#include "R:\C++\Project1\lcHeader.h"

class ExpandFromCenters {
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size();i++){
            //for odd len palindrome the center will be the same
            //eg 'aba'
            string odd = expand(i, i, s);
            if(odd.size() > res.size()){
                res = odd;
            }

            //for even len palindrome the center will be i and i+j
            //eg 'abba'
            string even = expand(i, i+1, s);
            if(even.size() > res.size()){
                res = even;
            }
        }
        return res;
    }

    string expand(int i, int j, string s){
        //using two pointers we go from the center 
        int left = i;
        int right = j;
        //so the left moves left from center and right to the right
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        //because left is now one step before the palindrome start like out of bounds
        //for the condn to be false we need to extend left till -1 hence +1 and -1 in the len
        return s.substr(left + 1, right-left-1);
    }
};

class DynamicProgramming {
public:
    string longestPalindrome(string s) {
        int l = s.size();
        vector<vector<bool>> dp(l, vector<bool>(l));
        //Keeps track of the starting and ending index of the longest palindrome found
        array<int, 2> ans = {0,0};

        //Every single character is a palindrome hence storing true
        for(int i = 0; i < l;i++){
            dp[i][i] = true;
        }

        //if two consecutive characters are true, than storing that as well
        for(int i = 0; i < l -1;i++){
            if(s[i] == s[i + 1]){
                dp[i][i+1] = true;
                ans = {i, i + 1};
            }
        }

        //diff is the difference between j and i, i.e., the length - 1.
        for(int diff = 2; diff<l;diff++){
            for(int i = 0;i < l - diff; i++){
                int j = i + diff;
                if(s[i] == s[j] && dp[i + 1][j -1]){
                    dp[i][j] = true;
                    ans = {i,j};
                }
            }
        }

        //this is just a 2 value array with i and j values stored in it
        int i = ans[0];
        int j = ans[1];

        //+1 bc the index starts at 0
        return s.substr(i, j- i + 1);
    }
};