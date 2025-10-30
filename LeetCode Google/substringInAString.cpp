#include "lcHeader.h"

//sliding window
//complexity is O(n^2)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = needle.length();
        int n = haystack.length();

        for (int i = 0; i <= n - m; i++) {
            for (int j = 0; j < m; j++) {
                if (needle[i] != haystack[i + j]) {
                    break;
                }
                if (i == m - 1) {
                    return i;
                }
            }
        }
        return -1;
    }
};

//https://www.geeksforgeeks.org/dsa/kmp-algorithm-for-pattern-searching/
//complexity is O(n + m)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();

        if(n == 0) return 0;

        vector<int> lps = kmpa(needle);
        int i = 0;
        int j = 0;

       for (int i = 0, j = 0; i < m;){//iterator is not given
            if(haystack[i] == needle[j]){//we are manually iterating to break the loop
                i++;j++;
            }
            if(j == n){
                return i - j;
            }
            if(i < m && haystack[i] != needle[j]){
                j ? j = lps[j - 1] : i++;
            }
        }
        return -1;
    }

    //Long prefix buildup
    //check the link
    vector<int> kmpa(string needle){
        int n = needle.length();
        vector<int> lps(n , 0);//vector of n len and all value in it is zero

        int len = 0;
        int i = 1;

        for (int i = 1, len = 0; i < n;){
           if(needle[i] == needle[len]){
            //checking the suffix
            len++;
            lps[i] = len;
            i++;
        }
        else if(len != 0){
            len = lps[len - 1];//falling back to 0
        }
        else{
            lps[i++] = 0;
        }
    }
        return lps;
    }
};