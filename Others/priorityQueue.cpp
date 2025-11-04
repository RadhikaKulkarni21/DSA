using namespace std;
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>

struct Notification {
    int id;         
    bool highPriority;
};

vector<int> priorityNotification(const vector<Notification>& notifications){
    vector<int> high;
    vector<int> normal;

    for(const auto& notification : notifications){
        if(notification.highPriority){
            high.push_back(notification.id);
        }
        else{
            normal.push_back(notification.id);
        }
    }

    vector<int> delivery = high;
    delivery.insert(delivery.end(), normal.begin(),normal.end());

    return delivery;
}