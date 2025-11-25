#include "R:\C++\Project1\lcHeader.h"
/*
Koko loves to eat bananas. There are n piles of bananas, 
the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. 
Each hour, she chooses some pile of bananas 
and eats k bananas from that pile. 
If the pile has less than k bananas, 
she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas
before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());

    while(left < right){
        int mid = (left + right)/2;

        int hoursSpent = 0;

        for(int pile : piles){
            hoursSpent += pile / mid + (pile % mid != 0);
        }

        if(hoursSpent <= h){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    return right;
}

int main(){
    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout<< "Minimum eating speed is: " << minEatingSpeed(piles, h);
}