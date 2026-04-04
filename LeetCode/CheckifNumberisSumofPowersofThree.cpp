/*
Given an integer n, return true if it is possible to represent n 
as the sum of distinct powers of three. Otherwise, return false.

An integer y is a power of three if there exists an integer x such that y == 3x.
*/
#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    bool checkPowerOfThree(int n){
        //the output for the division will always be 0, 1 or 2
        //the only way 2 is possible is 3^0 used twice
        //since we need distinct only values we can't use that
        while(n > 0){
            //we automatically break the loop
            if(n % 3 == 2) return false;

            //we keep diving the n till we reach n = 0
            //if n reaches 0 that means this is true
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

/*
n = 12
if(12 % 3 != 2)
n = 12 / 3 = 4

n = 4
if(4 % 3 != 2)
n = 4/3 = 1

n = 1

*/