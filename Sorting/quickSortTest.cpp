#include "R:\C++\Project1\lcHeader.h"

void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int low, int high) {
    
    int partition = array[high];
    
    int i = low - 1;

    //traverse to store smaller elements on left side
    for(int j = low; j <= high - 1; j++){
        if(array[j] > partition){
            i++;
            swap(array[i], array[j]);
        }
    }

    
    swap(array[i+1], array[high]);
    return i + 1;
}

void quickSort(int array[], int leftIndex, int rightIndex) {
	if(leftIndex >= rightIndex) return;
	int pivotIndex = pivot(array, leftIndex, rightIndex);
	quickSort(array, leftIndex, pivotIndex - 1);
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