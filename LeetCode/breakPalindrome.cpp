#include "R:\C++\Project1\lcHeader.h"

string breakPalindrome(string palindrome){
    int l = palindrome.length();

    for(int i = 0; i < l/2; i++){
        if(palindrome[i] != 'a'){
            palindrome[i] = 'a';
            return palindrome;
        }
    }
    palindrome[l - 1] = 'b';
    return palindrome;
}

int main(){
    string palindrome = "aba";
    cout<<breakPalindrome(palindrome);
}

