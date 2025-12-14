#include "R:\C++\Project1\lcHeader.h"

//easy approach
/*int findSmallestMissingPositive(vector<int> orderNumbers) {
    int n = orderNumbers.size();
    if(n == 0)return 1;
    
    for (int i : orderNumbers){
        cout<< i << ", ";
    }
    
    for(int i = 0;i < n; i++){
        while(orderNumbers[i] > 1 && orderNumbers[i] <= n && orderNumbers[i] != orderNumbers[orderNumbers[i] - 1]){
            swap(orderNumbers[i], orderNumbers[orderNumbers[i] - 1]);
        }
    }
    for(int i = 0;i < n;i++){
        if(i != orderNumbers[i - 1]){
            return i;
        }
    }
    
    return n + 1;
}*/

int findSmallestMissingPositive(vector<int> arr) {
  	int n = arr.size();
    bool flag = false;

    // Check if 1 is present in array or not
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            flag = true;
            break;
        }
    }

    // If 1 is not present
    if (flag == false)
        return 1;

    // Change out of range values to 1
    //essentially marking all -ve values as -1
    for (int i = 0; i < n; i++) {
        if (arr[i] <= 0 || arr[i] > n)
            arr[i] = 1;
        
    }

    // Mark the occurrence of numbers 
  	// directly within the same array
    for (int i = 0; i < n; i++) {
        arr[(arr[i] - 1) % n] += n;
    }

    // Finding which index has value less than n
    for (int i = 0; i < n; i++) {
        if (arr[i] <= n)
            return i + 1;
    }

    // If array has values from 1 to n
    return n + 1;
}

int main(){
    vector<int> orderNumbers = {3, 4, -1, 1};
    cout<< findSmallestMissingPositive(orderNumbers);//2
}