#include "R:\C++\Project1\lcHeader.h"


/*
 Write a function that takes a list of integers and returns a 
 new list containing two elements: the maximum and the minimum value in the input list.
 Example 1:

Input:

myList: [3, 7, 2, 9, 5]

Output: [9, 2]
*/

vector<int> findMaxMin(vector<int>& newList) {
    int minValue = newList[0];
    int maxValue = newList[0];

    for(int i = 0; i < newList.size();i++){
        if(newList[i] > maxValue){
            maxValue = newList[i];
        }
        else if(newList[i] < minValue){
            minValue = newList[i];
        }
    }
    return vector<int> {maxValue, minValue};
}

vector<int> minMax(vector<int>& myList){
    int minValue = myList[0];
    int maxValue = myList[0];

    for(int nums: myList){
        if(nums > maxValue){
            maxValue = nums;
        }
        else if(nums < minValue){
            minValue = nums;
        }
    }
    return vector<int>{maxValue,minValue};
}
 
int main(){
    vector<int> newVector = {1,2,3,4,5,6};
    printVector(newVector);

    vector<int> resultFor = findMaxMin(newVector);
    cout<<"Using for loop: "<<endl;
    printVector(resultFor);

    vector<int> resultForEach = minMax(newVector);
    cout<<"Using foreach loop: "<<endl;
    printVector(resultForEach);
}

/*
No difference just two different ways to solve it
Its just range based for loop is cleaner code wise than for loop
*/