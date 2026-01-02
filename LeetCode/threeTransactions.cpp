/*
You are given an array of integers prices representing the 
price of a stock on each day.
 You are allowed to complete at most three transactions 
 (i.e., buy one and sell one share of the stock multiple times). 
 Note: You may not engage in multiple transactions simultaneously 
 (i.e., you must sell the stock before you buy again).

Find the maximum profit you can achieve.
*/

#include "R:\C++\Project1\lcHeader.h"

int findThirdLargestTransaction(const vector<int>& transactions){

    if(transactions.size() == 0) return 0;
    int maxProfit = 0;
    int minPrice = INT_MIN;
    int thirdTrans = INT_MIN;
    int firstTrans = INT_MIN;
    int secondTrans = INT_MIN;

    for(int i = 0; i < transactions.size();i++){
        int current = transactions[i];

        if(current > firstTrans){
            thirdTrans = secondTrans;
            secondTrans = firstTrans;
            firstTrans = current;
        }
        else if(current > secondTrans){
            thirdTrans = secondTrans;
            secondTrans = current;
        }
        else if (current > thirdTrans){
            thirdTrans = current;
        }
    }

    if(thirdTrans == INT_MIN){
        return thirdTrans;
    }
}

int main(){
    vector<int> transactions = {3,3,5,0,0,3,1,4};
    //we are outputting the transaction not the profit
    cout<< findThirdLargestTransaction(transactions);
}