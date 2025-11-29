#include "R:\C++\Project1\lcHeader.h"


int missingNumber(vector<int> arr, int num){
    //gonna need to pass the num = array.size separately as array index starts from 0
    //when calculating size a 50 length array will be of size 49 hence will destroy
    //the calculations
    int totalSum = num * (num + 1)/2;
    int actualSum = 0;

    for(int n : arr){
        actualSum += n;
    }
    
    int missingNum = totalSum - actualSum;
    
    return missingNum;
}

int missingNumberAcc(const vector<int>& arr){
    int n = arr.size() + 1;
    int totalSum = n * (n+1)/2;

    //to replace accumulate
    int actualSum = 0;
    for(int num : arr){
        actualSum += num;
    }

    //accumulate only works if 0 is included
    return totalSum - accumulate(arr.begin(),arr.end(),0);
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,8,9,10};
    vector<int> num = {4,6,7,1,9,8,3,5,10};

    int n = arr.size() + 1;//need a +1 bc array index starts from zero
    cout<< "Missing Number: "<< missingNumber(arr, n)<< endl;

    cout<< "Missing Number: "<< missingNumberAcc(num);
    return 0;
}