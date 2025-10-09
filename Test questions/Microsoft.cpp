#include <queue>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
using namespace std;


/*
THERE are n types o f items, number of type i is given by quantity[i], 
price is determined dynamically where ith item is equal to remaning number 
of type i items. m customers in line, each will buy only one item of any type, 
shopkeeper wants to max his revenue by selling the items optimally. 
Determmine max revenue the shopkeeper can earn by selling excatly m items.
*/
long getMaximumAmount(vector<int> quantity, int m) {
     long maxRevenue = 0;
     //output we need
    // //int n = quantity.size();
    // priority_queue<int> priceValue;
    // for(int q : quantity){
    //     //we dont need 0 quantity items
    //     if(q > 0) {
    //         priceValue.push(q);
    //     }
    // }
    
    // //there are customers and there is quantity
    // while(m > 0 && !priceValue.empty()){
    //     int currentQuantity = priceValue.top();
    //     priceValue.pop();
        
    //     maxRevenue += currentQuantity;
    //     m--;
    //     if(currentQuantity> 0){
    //         priceValue.push(currentQuantity);
    //     }
    // }   
    priority_queue<int> priceValue(quantity.begin(), quantity.end());
    for(int i = 0; i < m && !priceValue.empty();i++){
        int first = priceValue.top();
        priceValue.pop();
        maxRevenue += first;
        if(first - 1 > 0) priceValue.push(first - 1);
    }
    
    return maxRevenue;
}

/*
alex is shopping, each cubicle sells products at fixed price. 
cubicles are arranged so that prices are in non decreasing value.
Array of n intergers , prices where prices[i] is the price at ith cubicle 
and q queries to process. 
For each query pos - alex's initial position and amount - amount alex has. 
Alex visits each cubicle from pos to n 
and can purchase max one product from each cubicle visited. 
Max products alex can buy without exceeding the amount. 
eg values: n = 5, prices[3,4,5,5,7], q = 3 queries = [[2,10],[1,24],[5,5]]
*/
vector<int> findMaximumValue(vector<int> prices, vector<int> pos, vector<long> amount) {
    int psize = pos.size();
    int priceSize = prices.size();
    vector<int> totalVisits(psize);
    
    for(int i = 0; i < psize;i++){
        int start = pos[i] - 1;
        //long bc the given vector is long
        long currentAmount = amount[i];
        int cubsVisit = 0;
        
        //start iterating from pos and removing the money after each visit
        for(int j = start; j < priceSize; j++){
            if (currentAmount >= prices[i]){
                currentAmount -= prices[i];  
                cubsVisit++;
            }
            else{
                //bankrupt so get out of the loop
                break;
            }
        }
        totalVisits[i] = cubsVisit;
    }
    return totalVisits;
}