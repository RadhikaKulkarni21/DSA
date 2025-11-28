/*
You are given an array a of len n, 
split mutually exclusive subarrays with a equal total product,
return the max number of parts in partition possible 
where each part has an equal total product

example
A = [36,6,6,12,3]
N = 5
O/p = 3

[36] [6,6] [12,3]
*/

#include "R:\C++\Project1\lcHeader.h"

int numberOfPartitons(vector<int>arr, int n){
    //return -1 if no partitions are possible
    int partitions = -1;
    
    //product should always 0 <
    long product = 1;

    for(int n : arr){
        product *= n;
    }

    for(int i = n; i >= 2; i--){
        if(product == 0) break;

        long root = pow((long)product, 1.0L/i);
        long target = round(root);

        long f = 1;
        for(int k = 0;k < i;k++)f *= target;
        if(f != product) continue;

        long check = 1;
        int div = 0;

        for(int j = 0; j < n;j++){
            check *= arr[j];
            if(check == target){
                div++;
                check = 1;
            }
        }
        if(div == i){
            partitions = i;
            break;
        }
    }
    return partitions;
}

int main(){
    vector<int> arr = {2,1,1,2,1,1,2};

    cout<<numberOfPartitons(arr,arr.size());
}
