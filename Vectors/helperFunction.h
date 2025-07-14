//tired of entering the same code every integer question
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const vector<int> nums){
    cout << "[";
    for(size_t i = 0; i < nums.size();i++){
        cout<<nums[i];
        if(i != nums.size() - 1){
            cout<< ", ";
        }
    }
    cout<<"]"<<endl;
}

void printString(const vector<string>& strings){
    cout<<"[";
    for (const auto& str : strings) {
        cout << "\"" << str << "\" ";
    }
    cout << "]"<<endl;
}

//new size to print resized vector
void printVectorNewSize(const vector<int>& nums, int newSize = -1) {
    cout << "[";
    int sizeToPrint = (newSize == -1) ? nums.size() : newSize;
    for (int i = 0; i < sizeToPrint; i++) {
        cout << nums[i];
        if (i < sizeToPrint - 1) {
            cout << ", ";
        }
    }
    cout << "]";
}

/*
some codes are missing questions.
TODO: add questions, context to the codes to know what is what - DONE
*/