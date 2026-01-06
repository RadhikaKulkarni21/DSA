/*
Given a positive integer n, 
write a function that returns the number of set bits 
in its binary representation (also known as the Hamming weight).

Example 1:

Input: n = 11

Output: 3

Explanation:

The input binary string 1011 has a total of three set bits.
*/
#include <bitset>
#include "R:\C++\Project1\lcHeader.h"

int hammingWeight(int n) {
    bitset<32> dec(n);
    int counter = 0;
    for(int i = 0; i < dec.size(); i++){
        if(dec[i] == 1){
            counter++;
        }
    }
    return counter;
}

int main(){
    int n = 128;
    cout<<hammingWeight(n);
}