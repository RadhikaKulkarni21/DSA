#include "R:\C++\Project1\lcHeader.h"

/*
It repeatedly divides the search interval in half
eliminating half of the remaining elements
each time until the target value is found or interval is empty
*/

int binarySearch(vector<int> arr, int target){
    int n = arr.size();

    int left = 0;
    int right = n - 1;

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(arr[mid] ==  target){
            return mid;
        }
        //if the target is greater than mid, we just ignore the first half
        else if(arr[mid] < target){
            left = mid + 1;
        }
        //we move to other side
        else{
            right = mid -1;
        }
    }
    return -1;
}

int binarySearchReccursive(vector<int> arr, int target, int low, int high){
    if(high >= low){
        int mid = low + (high - low)/2;

        if(arr[mid] == target) return mid;
        
        //if mid is bigger than target we go to the first half of array
        if(arr[mid] > target){
            return binarySearchReccursive(arr, target, 0, mid - 1);
        }

        //if mid is smaller than target then we go to second half of array
        if(arr[mid] < target){
            return binarySearchReccursive(arr, target, mid + 1, high);
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {39,45,74,89,92,98};
    int target = 89;

    int n = arr.size();
    int result = binarySearch(arr, target);
    int rresult = binarySearchReccursive(arr, target, 0, n - 1);

    if(result == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Binary search index: " << result<< endl;
    }

    if(rresult == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<<"Recursive search index: "<< rresult<<endl;
    }
}