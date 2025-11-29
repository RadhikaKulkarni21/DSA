/*Title: Finding Maximum Profit from Stock Prices

Introduction: The stock market is unpredictable, with prices of stocks rising and falling 
every day. For those who want to buy and sell stocks to gain profit, 
knowing when to buy at a low price and when to sell at a high price is crucial. 
This problem challenges you to determine the best day to 
buy and sell a stock to achieve maximum profit.

Objective: Given a list of integers where each integer represents the stock price 
of a company for a particular day (index 0 is Day 1, index 1 is Day 2, and so on),
your task is to find the maximum profit you could achieve 
from buying the stock on one day and selling it on a later day. 
Note that you are only allowed to complete one transaction, 
i.e., you can only buy and sell the stock once.

Detailed Requirements:

Input:

A list of integers, prices, representing the stock price for each day. 
The list can be of any length, including being empty.

Output:

An integer representing the maximum profit you can make. 
Return 0 if no profit can be made or if the input list is empty.

Example 1:

Input:
prices: [7,1,5,3,6,4]
Output:
5
Explanation:
Buy on Day 2 (price = 1) and sell on Day 5 (price = 6) for a profit of 6-1 = 5.
*/
#include "R:\C++\Project1\lcHeader.h"

int maxProfit(const vector<int>& prices){
    //we need to find the max value
    int minPrice = INT_MAX;
    int maxProfit = 0;

    for(int price : prices){
        minPrice = min(minPrice, price);
        int profit = price - minPrice;
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}

int maxProfitFor(const vector<int>& prices){
    int minPrice = INT_MAX;//assigning a max value just to get min
    int maxProfit = 0;
    for(int price = 0; price < prices.size();price++){
        minPrice = min(minPrice, prices[price]);//getting min outta prices in vector
        //profit will be min of whatever buying price 
        //and whatever is the price on that day
        int profit = prices[price] - minPrice;
        //we compare the subtartion for each day and store it
        maxProfit = max(maxProfit,profit);
    }
    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 2, 3, 9, 5};
    cout << "Prices: "; printVector(prices);
    int profit = maxProfit(prices);
    cout << "Profit: " << profit;

    cout << "Prices: "; printVector(prices);
    int profit = maxProfitFor(prices);
    cout << "Profit: " << profit;
}
/*
two same fcuntions just solved differently
*/