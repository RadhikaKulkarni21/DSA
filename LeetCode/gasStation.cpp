#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
//gas is gas you can fill at each stop
//cost is gas required or used to reach next gas station
//we can go to from 1 to 2, so we can chose starting point
//we need to subtract the gas filled from start point with cost
//positive integer means we can move forward
//if not we can move to next element in array
    int canCompleteCircle(vector<int>& gas, vector<int>& cost){
        int sp = 0;
        int totalGas = 0, totalCost = 0;

        for(int i = 0; i < gas.size(); i++){
            totalGas += gas[i];
            totalCost += cost[i];
        }

        if(totalGas < totalCost){
            return -1;
        }
        //we get curr gas and compare it at point 1 from gas to next point cost
        //if its greater than thats what the starting point is
        //if its 0 or less than 0 we move to next point
        int curr_gas = 0;

        for(int j = 0; j < gas.size();j++){
            curr_gas += gas[j] - cost[j];
            if(curr_gas < 0){
                curr_gas = 0;
                sp = j + 1;
            }
        }
        return sp;
    }

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int fuel = 0, totalGas = 0, curr = 0, sp = 0;

        for(int i = 0; i < gas.size();i++){
            fuel = gas[i] - cost[i];
            totalGas += fuel;
            curr += fuel;

            if(curr < 0){
                curr = 0;
                sp = i + 1;
            }
        }
        return totalGas < 0 ? -1 : sp;
    }
};

int main(){
    vector<int> gas = {3,1,1};
    vector<int> cost = {1,2,2};

    Solution s;

    cout<<s.canCompleteCircle(gas, cost)<<endl;
    cout<<s.canCompleteCircuit(gas, cost);
}