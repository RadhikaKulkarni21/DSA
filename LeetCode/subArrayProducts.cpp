/*
given array [1,2,3]
subarray products [1][2][3][1,2][2,3][1,2,3]
count the number of subarrays whose product is less than k
*/

#include "lcHeader.h"

// Custom function to multiply adjacent numbers
int op(int a, int b) {
    return a * b;
}

long subArrayProducts(vector<int> numbers, int k){
    int l = numbers.size();
    //vector<int> product;
    long counter = 0;
    

    for(int i = 0; i < numbers.size(); i++){
        //we need to reset pro as the multiplcation moves to next index
        long pro =    1;
        for(int j = i; j < numbers.size();j++){
            pro *= numbers[j];
            if(pro <= k){
                counter++;
            }
            else{
                break;
            }
        }
    }
    
    //cout<<pro<<endl;
    //for(int n : product){
      //  cout<< n <<" ";
    //}

    //counter for subarrays
    // for(int i = 0; i < product.size(); i++){
    //     if(product[i] <= k){
    //         counter++;
    //     }
    // }
    return counter;
}

int main(){
    vector<int> numbers = {2, 3, 4};
    int k = 10;

    //2, 3, 4, 6, 12, 24
    //4
    cout<<subArrayProducts(numbers,k);
}