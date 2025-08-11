#include "headerSets.h"

/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares 
of its digits.
Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

Example 1:

Input: n = 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
Example 2:

Input: n = 2
Output: false
*/

class Solution{
public:
bool happyInt(int n){
    //we are creating a set so that the visited numbers can be stored
    //this will shortern the compilation time if numbers repeat
    unordered_set<int> visited;

    while(visited.find(n) == visited.end()){
        visited.insert(n);
        //this is like n++
        n = getNextNumber(n);
        if(n == 1){
            return true;
        }
    }
    return false;
}

private:
int getNextNumber(int n){
    int output = 0;

    while(n > 0){
        int digitNum = n % 10;
        output += digitNum * digitNum;
        n = n / 10;
        // this is similar to doing n++ so we move to n's next digit on left
    }
    return output;
}
};

int main(){
    int n = 19;
    Solution newSol;
    bool result = newSol.happyInt(n);
    string op = result? "true" : "false";
    cout<< op;
}


