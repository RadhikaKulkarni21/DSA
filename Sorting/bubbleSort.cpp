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