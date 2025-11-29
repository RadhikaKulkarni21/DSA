#include "R:\C++\Project1\lcHeader.h"
//using memoization
//to calculate the number of operations required
static int counter = 0;

vector<int> memo(100,-1);

int fib(int n){
    counter++;

    if(memo[n] != -1){
        return memo[n];
    }

    if(n == 0 ||  n == 1){
        return n;
    }
    //return fib(n-1) + fib(n-2) = o(2^n)
    //overlapping subproblem
    memo[n] =  fib(n-1) + fib(n-2); // = o(n)
    return memo[n];
}

int main(){
    int result = fib(10);
    cout<<result<<endl;
    cout<<counter;
}