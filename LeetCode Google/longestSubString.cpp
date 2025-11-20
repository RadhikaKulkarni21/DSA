#include "lcHeader.h"

//we use sliding window again
//at any given time only unique numbers will stay in the 

/*int longestSubstring(string s){
    unordered_map<char, int> chars;
    int length;
    int left = 0, right = 0;

    while(right < s.length()){//so that  there's actually a string here
        
        char r = s[right];//store the 'value' here
        
        chars[r]++;//update the counter for each 'value'

        //so if the sequence has more than one counter of 'value'
        //we slide the window as in move the left pointer
        //so that at any given point there are only unique values in the window
        
        while(chars[r] > 1){
            
            char l = s[left];//get the repeating character here
            
            chars[left]--;//decrease its counter by 1
            
            left++;//move the counter upfront
        }

        //+1 bc we use indices in left and right
        //we will always be undercounting here 
        length = max(length, right - left + 1);
    }
    return length;
}*/

int mapLongestSubstring(string s){
    unordered_map<char, int> charNext;
    int n = s.length(), length = 0;

    for(int j = 0, i = 0; j < n; j++){
        //occurance is more than 1
        //so we just update the latest pos of the value to next pos
        if(charNext[s[j]] > 0){

        //we are updating the window here to move forward
        //hence counting the new string from here
            i = max(charNext[s[j]], i);
            cout<<charNext[s[j]];
        }

        //Now we get the string from whatever is latest i to j
        length = max(length, j - i + 1);

        //updating j to move forward
        charNext[s[j]] = j + 1;
    }
    return length;
}

int lengthOfLongestSubstring(const string& s) {
    unordered_map<char, int> lastSeen;
    int left = 0;
    int maxLen = 0;

    for (int right = 0; right < (int)s.size(); ++right) {
        char c = s[right];//store in hashmap

        // If we've seen the character and it's inside the current window
        //check count of c in map
        if (lastSeen.count(c) && lastSeen[c] >= left) {
            left = lastSeen[c] + 1;   // move left one place ahead as to slide the window
        }

        lastSeen[c] = right; // update last seen position
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}


int main(){
    string s = "abababa";
    int length = mapLongestSubstring(s);
    cout<<endl;
    cout<<length;
}