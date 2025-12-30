/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, 
and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.
*/

#include "R:\C++\Project1\lcHeader.h"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //we start from end of nums1 vector
    //we compare the last value from nums1 to the first value of nums2
    int mind = m - 1;
    int nind = n - 1;
    //the position to be compared to add the value
    //r is last element in nums1 vector
    int r = m + n - 1;

    while(nind >= 0){
        if(mind >= 0 && nums1[mind] > nums2[nind]){
            //if the last element is greater than first value of nums2, the element stays 
            //there and we move to the next element 
            nums1[r] = nums1[mind];
            mind--;
            //vector is sorted to largest element is already at the back
        }
        else{
            //once we reach -1, the element will get placed at r correctly
            nums1[r] = nums2[nind];
            nind--;
        }
        //r moves to next position which will be (m - 2)
        r--;
    }
}

int main(){
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int n = 3;
    int m = 3;

    merge(nums1, m, nums2, n);
    printVector(nums1);
}

/*
             ↓     r
nums1 = [1,2,3,0,0,0], m = 3,
nums2 = [2,5,6], n = 3　　　　　　　　　　　
             ↑

r is right position where we should put the next biggest number.
First of all, compare 3 with 6. 
6 is bigger than 3. 
Put 6 at right position and mvoe r and the pointer in nums2 to the next.
     ↓   r
[1,2,3,0,0,6]
[2,5,6]
   ↑

Compare 3 with 5.
     ↓ r
[1,2,3,0,5,6]
[2,5,6]
   ↑
Compare 3 with 2.

   ↓ r
[1,2,3,3,5,6]
[2,5,6]
 ↑
Compare 2 with 2. Let me put 2 from nums2.

   ↓ r
[1,2,2,3,5,6]
[2,5,6]
↑

*/