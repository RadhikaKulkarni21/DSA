#include "lcHeader.h"

/*
Input: arr = [10,13,12,14,15]
             [ 0  1  2  3  4]
Output: 2
Explanation: 
odd: i <= j, j is smallest
even: i >= i, j is biggest

From starting index i = 0 = 10, 
we can make our 1st jump to i = 2 = 12 
(since arr[2]=12 is the smallest among arr[1]=13, arr[2], arr[3]=14, arr[4]=15 
that is greater or equal to arr[0]=10), then we cannot jump any more.

From starting index i = 1 and i = 2, 
we can make our 1st jump to i = 3, then we cannot jump any more.

From starting index i = 3, 
we can make our 1st jump to i = 4, so we have reached the end.

From starting index i = 4, we have reached the end already.
In total, there are 2 different starting indices i = 3 and i = 4, 
where we can reach the end with some number of
jumps.
*/