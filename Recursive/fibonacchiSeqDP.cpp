using namespace std;
#include <iostream>
#include <vector>
//this will always create a brand new vector so O(n) each time
static int counter = 0;

int fib(int n){
    vector<int> fibList;
    //in CS, the 0th and 1st index won't be filled 
    //so as per fib seq we need to add 0+1 to n(1) actual item
    fibList.push_back(0);
    fibList.push_back(1);

    for(int index = 2; index <= n; index++){
        counter++;
        fibList[index] = fibList[index - 1] + fibList[index - 2];
    }
    return fibList[n];
}

int main(){
    int result = fib(10);
    cout<<result<<endl;
    cout<<counter;
}