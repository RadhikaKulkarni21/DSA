#include "R:\C++\Project1\lcHeader.h"

void bubbleSort(int array[], int size){
    for(int i = size - 1; i > 0; i--) //i = 5(index) //i = 4
    {
        for(int j = 0;j<i;j++){//i is passes
            if(array[j] > array[j+1]){//j[0] = 6 j[0+1] = 4
            int temp = array[j];      //j[1] = 6  j[2] = 2
            array[j] = array[j+1];    //We will do this for every element
            array[j+1] = temp;       //take one element compare it with next element
            }                        //Move on if no match is found
        }
    }
}
//Complexity: O(n^2)
//Space O(1) - no new data structure created

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

Within the loop, create another loop with an index variable j increasing 
from 0 to i - 1. 
Compare the elements at positions j and j + 1.

Swap elements if necessary:

If the element at position j is greater than the element at position j + 1, 
swap the elements by storing the element at position j in a temporary variable temp, 
then assigning the element at position j + 1 to the element at position j, 
and finally assigning the value stored in temp to the element at position j + 1.
*/

