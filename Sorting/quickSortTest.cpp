/*Wrote this because the other quickSort.cpp was not working correctly
eventually it started working idk how*/

using namespace std;
#include <iostream>

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]"<<endl;
}

void swap(int array[], int firstIndex, int secondIndex) {
    int temp = array[firstIndex];
    array[firstIndex] = array[secondIndex];
    array[secondIndex] = temp;
}

int pivot(int array[], int pivotIndex, int endIndex) {
    int swapIndex = pivotIndex;
    for (int i = pivotIndex + 1; i <= endIndex; i++) {
        if (array[i] < array[pivotIndex]) {
             
            swapIndex++;
            swap(array, swapIndex, i);
        }
    }
    
    swap(array, pivotIndex, swapIndex);
    return swapIndex;
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