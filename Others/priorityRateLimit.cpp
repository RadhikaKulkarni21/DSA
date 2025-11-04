using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

struct Notification{
    int id;
    bool priority;
    int timestamp;
};

vector<int> rateLimitpriority(const vector<Notification>& notifications, int k){
deque<int> high, normal;
   vector<int> delivered;

    for(const auto& notif: notifications){
        deque<int> timeframe = notif.priority ? high : normal;

        while(!timeframe.empty() && notif.timestamp - timeframe.front() >= 10){
            timeframe.pop_front();
        }

        //we are pushing this in both the vector and deque
        if(timeframe.size() < k){
            delivered.push_back(notif.id);
            timeframe.push_back(notif.timestamp);
        }
    }
    return delivered;
}
