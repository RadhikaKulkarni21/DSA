//working
/*
Given n non-negative integers representing an elevation map where 
the width of each bar is 1, compute how much water it can trap after raining.
*/

#include "lcheader.h"

    int trap(vector<int>& height){
        int water = 0;
        //two pointers to iterate through the vector
        int left = 0;
        int right = height.size() - 1;
        
        //These will store the value,
        //whenever we hit a 0 that means water is there, so max left will give
        //biggest wall on the left, same for right
        int maxLeft = height[left];
        int maxRight = height[right];

        while(left < right){
            if(maxLeft < maxRight){
                //we move a bit to left
                left++;
                //max between the left and current Left
                maxLeft = max(maxLeft, height[left]);
                //water will be max - current bar
                water += maxLeft - height[left];       
            }
            else{
                right--;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }
        return water;
    }

int main(){
    //vector<int> height = {2,1,0,1,3,2}; exp: 4
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1}; //exp: 6
    int res = trap(height);
    cout<<res;
}

/*
[2,1,0,1,3,2]
 L         R

left max = 2
right max = 2
water = 0

current bar vs current max right
= 3 vs 2
= 3

[2,1,0,1,3,2]
 L       R

left max = 2
right max = 3
water = 0

water = current right max - current bar
= 3 - 3
= 0

[2,1,0,1,3,2]
     L   R

left max = 2
right max = 3
water = 1

2 - 0 = 2
total water = 3
*/