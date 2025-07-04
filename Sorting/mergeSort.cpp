using namespace std;
#include <iostream>
#include <vector>


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

//take two varibales, loop through
//compare values, add them into another array/list
//one arrays, two subarrays and we copy those into new array
//i and j are in new arrays
//actually copying them in the old array after comparision

//helper fucntion
void merge(int array[], int leftIndex, int midIndex,int rightIndex){
    int leftArraySize = midIndex - leftIndex + 1;
    int rightArraySize = rightIndex - midIndex;

    //dynamic array size so need to declare it like this
    int* leftArray = new int[leftArraySize];
    int* rightArray = new int[rightArraySize];

    for (int i = 0; i < leftArraySize; i++){
        leftArray[i] = array[leftIndex + i];
    }
    for (int j = 0; j < rightArraySize; j++){
        rightArray[j] = array[midIndex + 1 + j];
    }

    int index = leftIndex;
    int i = 0;
    int j = 0;
    //Run till one of the subarrays is null
    while(i < leftArraySize && j < rightArraySize){
        //comparing across both subarrays
        if(leftArray[i] <= rightArray[j]){
            //if i value from first array is small, add in the main array
            array[index] = leftArray[i];
            index++;
            i++;
        }
        else{
            //if j is smaller add the j in main array
            array[index] = rightArray[j];
            index++;
            j++;
        }
    }
    //once out of while loop, need a separate array to move rest of the items from
    //remaining subarray to move into main array
    while(i < leftArraySize){
        array[index] =  leftArray[i];
        index++;
        i++;
    }

    while(j < rightArraySize){
        array[index] =  rightArray[j];
        index++;
        j++;
    }
}

int main(){
    int newArray[] = {1,3,7,8,2,4,5,6};

    int size = sizeof(newArray)/ sizeof(newArray[0]);
    int leftIndex = 0;
    int midIndex = (size/2) - 1;
    int rightIndex = size - 1;

    cout<<"Before:";
    printArray(newArray, size);

    cout<<"After";
    merge(newArray, leftIndex,midIndex,rightIndex);
    printArray(newArray, size);
}