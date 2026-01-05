/*
A sentence consists of lowercase letters ('a' to 'z'), 
digits ('0' to '9'), hyphens ('-'), punctuation marks ('!', '.', and ','),
 and spaces (' ') only. 
 Each sentence can be broken down into 
 one or more tokens separated by one or more spaces ' '.

A token is a valid word if all three of the following are true:

It only contains lowercase letters, hyphens, and/or punctuation (no digits).
There is at most one hyphen '-'. 
If present, it must be surrounded by lowercase characters 
("a-b" is valid, but "-ab" and "ab-" are not valid).
There is at most one punctuation mark.
If present, it must be at the end of the token 
("ab,", "cd!", and "." are valid, but "a!b" and "c.," are not valid).
Examples of valid words include "a-b.", "afad", "ba-c", "a!", and "!".

Given a string sentence, return the number of valid words in sentence.
*/

#include "R:\C++\Project1\lcHeader.h"

class Solution{
    public:
    int countValidWords(string sentence){
        istringstream ss(sentence);
        string token;
        int validWord = 0;

        //>> splits by whitespace
        //stops after whitespace is hit and outputs the word
        while(ss >> token){
            if(isValid(token)) validWord++;
        }
        return validWord;
    }

    private:
    bool isValid(const string& word){
        int n = word.size();
        bool hypen = false;
        bool pm = false;

        for(int i = 0;i < n;i++){
            if(isdigit(word[i])) return false;
            if(word[i] == '-'){
                //check if hypen is set to true, if yes immediate false
                //or will check rest of the validity
                //hypen is checked bc only one is allowed, if its already true
                //we skip
                if(hypen || i == 0 || i == (n - 1) || !islower(word[i-1]) || !islower(word[i+1])){
                    return false;
                }
                hypen = true;
            }
            //same for puncuation marks
            if(word[i] == '!' || word[i] == '.' || word[i] == ','){
                if(pm || i != n - 1){
                    return false;
                }
                pm = true;
            }
        }
        return true;
    }
};

int main(){
    string sentence = "cat and  dog";
    Solution s;

    cout << s.countValidWords(sentence);
}