/*
Given a positive integer n, you can either add or subtract 2^i in a
single operation where i >= 0. Determine the minimum number of operations
required to reduce it to 0

Find the minimun operations required to convert n into 0
*/

#include "R:\C++\Project1\lcheader.h"

int getMincounter(long n) {
    int counter = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            n = n / 2;
        } else if (n % 4 == 3) {
            n = n + 1;
            counter++;
        } else {
            n = n - 1;
            counter++;
        }
    }
    return counter;
}

int main(){
    long n = 7;
    cout<<getMincounter(n);
}

/*
If we reach something lets say 7, then we add 1 to make it 8 
so that it is divisible by 2^3

Why n%4 ==3
When the last two bits are 11, that means n in binary ends with ...11.

The last two bits can only be:

00 = 0
01 = 1
10 = 2
11 = 3
n % 4 gives you the value of the last two bits. So n % 4 == 3
means the last two bits are 11.

Example: n = 7 (111 in binary)

7 % 4 = 3 → last two bits are 11 → add 1 → n = 8
8 → 4 → 2 → 1... wait, just shift: ops = 1 more → total 2 ops
vs subtracting ones: 7→6→4→2→1→0 = 4 ops.
*/