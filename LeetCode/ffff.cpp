using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

vector<int> notifications(vector<int> timestamps, int k){
    vector<int> deliveryNotifs;
    deque<int> timeframe;

    for(int t : timestamps){
        while(!timeframe.empty() && t - timestamps.front()>= 10){
            timeframe.pop_front();
        }

        if(timeframe.size() < k){
            deliveryNotifs.push_back(t);
            timeframe.push_back(t);
        }
    }
    return deliveryNotifs;
}