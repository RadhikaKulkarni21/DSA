#include "R:\C++\Project1\lcHeader.h"

void selectionSort(int array[], int size){
    for(int i = 0;i < size;i++){
        int min_index = i;
        for(int j = i+1; j < size;j++){
            if(array[j] < array[min_index]){
                min_index = j;
            }
        }

        //if i is not the min index, change the min index
        //this is actually putting the value in place
        if(i != min_index){
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}
//time complexity is O(n^2)
//space complexity is O(1)

int main(){
    int newArray[] = {6,4,2,5,1,3};

    int size = sizeof(newArray) / sizeof(newArray[0]);
    printArray(newArray,size);
    cout<<endl;
    selectionSort(newArray, size);
    printArray(newArray,size);
}