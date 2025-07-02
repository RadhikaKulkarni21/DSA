#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
    cout << "[";
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i != size - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int temp = array[i];
        int j = i - 1;
        while(temp < array[j] && j > -1){
            array[j+1] = array[j];
            array[j] = temp;
            j--;
        }
    }
}
/*
Iterate through the array from the second element to the last:

Using a loop with an index variable i increasing from 1 to size - 1.

Store the current element in a temporary variable:

Store the element at position i in a temporary variable temp.

Find the correct position for the current element in the sorted part of the array:

Initialize an index variable j to i - 1.
Using a while loop, check if j is greater than or equal to 0 
and if the element in the temporary variable temp is less than the element at position j. 
If both conditions are true, 
shift the element at position j one position to the right (to position j + 1)
and update the element at position j with the value stored in temp. Finally, decrement j.
*/

int main(){
    int newArray[] = {6,4,2,5,1,3};

    int size = sizeof(newArray)/sizeof(newArray[0]);

    printArray(newArray, size);
    cout<<endl;
    insertionSort(newArray, size);
    printArray(newArray, size);
}