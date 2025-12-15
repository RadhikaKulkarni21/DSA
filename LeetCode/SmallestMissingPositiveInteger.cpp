#include "R:\C++\Project1\lcHeader.h"

//easy approach
int findSmallestMissingPositiveN(vector<int> orderNumbers) {
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
}

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


//second approach
/*
we search for 1 first and if 1 does not exist thats the one we are looking for

all the -ve numbers are set to 1, this removes the out of range issue
for the further "for" loops

next for loop
1st pass = arr[(arr[0] -1)%n] += 4
arr[(3-1)%4] += 4
arr[2%4]+= 4
arr[2]+= 4
arr[2] = 5 

arr = 3 4 5 1

2nd pass = arr[(arr[1] -1)%n] += 4
arr[(4-1)%4] += 4
arr[3%4]+= 4
arr[3]+= 4
arr[3] = 5 

arr = 3 4 5 5

3rd pass = arr[(arr[2] -1)%n] += 4
arr[(1-1)%4] += 4
arr[0%4]+= 4
arr[0]+= 4
arr[0] = 7

arr = 7 4 5 5

4th pass arr = 11 4 5 5


last for loop at 1 arr[i] <= 4
hence i + 1 = 2
*/