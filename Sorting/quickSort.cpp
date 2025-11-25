#include "R:\C++\Project1\lcHeader.h"

void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex){
    int swapIndex = pivotIndex;//start at the same point
    for(int i = pivotIndex + 1; i<= endIndex;i++){
        if(array[i] < array[pivotIndex]){
            //changing this so that the item is samller than pivot      
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    //changing the biggest with smallest swap index
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
}

void quickSort(int array[], int leftIndex, int rightIndex){
    if(leftIndex >= rightIndex) return;
    //this will make the array look like |smaller pivot bigger|
    int pivotIndex = pivot(array, leftIndex, rightIndex);
    //this will run for the left side of pivot so sorting the numbers smaller than pivot
    quickSort(array, leftIndex, pivotIndex - 1);
    //this will run for the left side of pivot so sorting the numbers bigger than pivot
    quickSort(array, pivotIndex + 1, rightIndex);
}

int main(){
    int newArray[] = {4,6,1,7,3,2,5};

    int size = sizeof(newArray) / sizeof(newArray[0]);

    int returnedIndex = pivot(newArray, 0, size - 1);

    cout<<"Returned Index:" << returnedIndex <<"\n\n";
    printArray(newArray, size);
    quickSort(newArray,0, size - 1);
    printArray(newArray,size);
}