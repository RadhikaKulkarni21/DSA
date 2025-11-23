#include "R:\C++\Project1\lcHeader.h"
/*
A straight forward method, that checks every element to find the target element.
*/

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
    //int size = sizeof(arr)/sizeof(arr[0]);
    int target = 1;

    int result =  linearSearch(arr, target);

    if(result == -1){
        cout<<"Element not present"<<endl;
    }
    else{
        cout<< "Element present at index: " << result << endl;
    }

    //cout<< linearSearchS(arr, size, target);
}