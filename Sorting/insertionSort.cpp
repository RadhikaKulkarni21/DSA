#include "R:\C++\Project1\lcHeader.h"

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int temp = array[i];
        int j = i - 1;
        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while(temp < array[j] && j >= 0){
            array[j+1] = array[j];//compare and replace
            array[j] = temp;//store the current back into place
            j--;//bc we are going back
        }
    }
}

//Complexity: O(n) if list already sorted
//O(n^2) if not sorted or in reverse
//O(1) space complexity as no new DS is added

int main(){
    int newArray[] = {6,4,2,5,1,3};

    int size = sizeof(newArray)/sizeof(newArray[0]);

    printArray(newArray, size);
    cout<<endl;
    insertionSort(newArray, size);
    printArray(newArray, size);
}