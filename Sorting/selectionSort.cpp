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


void selectionSort(int array[], int size){
    for(int i = 0;i < size;i++){
        int min_index = i;
        for(int j = i+1; j < size;j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }
        if(i != min_index){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

/*Iterate through the array from the first element to the second-to-last:

Using a loop with an index variable i increasing from 0 to size - 1.

Find the index of the minimum element in the remaining unsorted part of the array:

Initialize a variable minIndex to i, 
and create another loop with an index variable j increasing from i + 1 to size - 1.
If the element at position j is less than the element at position minIndex, 
update minIndex to j.

Swap the found minimum element with the element at position i:

If i is not equal to minIndex, 
swap the elements by storing the element at position i in a temporary variable temp, 
then assigning the element at position minIndex to the element at position i,
and finally assigning the value stored in temp 
to the element at position minIndex.*/

int main(){
     int newArray[] = {6,4,2,5,1,3};

    int size = sizeof(newArray) / sizeof(newArray[0]);
    printArray(newArray,size);
    cout<<endl;
    selectionSort(newArray, size);
    printArray(newArray,size);
}