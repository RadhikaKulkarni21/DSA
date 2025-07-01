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

void bubbleSort(int array[], int size){
    for(int i = size - 1; i > 0; i--)
    {
        for(int j = 0;j<i;j++){
            if(array[j] > array[j+1]){
            int temp = array[j];
            array[j] = array[j+1];
            array[j+1] = temp;
            }
        }
    }
}


int main(){
    int newArray[] = {6,4,2,5,1,3};

    int size = sizeof(newArray) / sizeof(newArray[0]);
    printArray(newArray,size);
    cout<<endl;
    bubbleSort(newArray, size);
    printArray(newArray,size);
}

/*The function should perform the following tasks:

Iterate through the array from the last element to the first:

Using a loop with an index variable i decreasing from size - 1 to 1.

Compare adjacent elements in the array:

Within the loop, create another loop with an index variable j increasing from 0 to i - 1. 
Compare the elements at positions j and j + 1.

Swap elements if necessary:

If the element at position j is greater than the element at position j + 1, 
swap the elements by storing the element at position j in a temporary variable temp, 
then assigning the element at position j + 1 to the element at position j, 
and finally assigning the value stored in temp to the element at position j + 1.
*/

