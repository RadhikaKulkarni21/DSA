#include "R:\C++\Project1\lcHeader.h"

int linearSearchS(vector<int> arr,int size, int target){
    for (int i = 0; i < size;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int linearSearch(vector<int> arr, int target){
    for (int i = 0; i < arr.size();i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {7,4,5,6,1,2,8};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 1;

    cout<< linearSearch(arr, target)<<endl;
    cout<< linearSearchS(arr, size, target);
}