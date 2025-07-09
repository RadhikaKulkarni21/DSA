using namespace std;
#include <iostream>
#include <vector>

void printVector(vector<int> vect){
    cout<<"[";
    for(int i = 0;i < vect.size();i++){
        cout<< vect[i];
        if(i != vect.size() - 1){
            cout<<", ";
        }
    }
    cout<<"]"<<endl;
}

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