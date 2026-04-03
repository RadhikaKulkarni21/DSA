/*
Given an integer n, return true if it is possible to represent n 
as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.
*/
#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    bool checkPowerOfThree(int n){
        while(n > 0){
            if(n % 3 == 2) return false;

            n /= 3;
        }
        return true;
    }
};

int main(){
    Solution s;
    bool result = s.checkPowerOfThree(91);

    result ? cout << "True" : cout <<"False";
}