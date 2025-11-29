#include "R:\C++\Project1\lcHeader.h"

int maxConcurrentEvents(const vector<pair<int, int>>& events){
    vector<pair<int, int>> timeEvent;

    for(auto event : events){
        //event starter so +1 so we know event can be overlapped
        timeEvent.emplace_back(event.first, +1);
        //event ended so -1, so we can remove it
        timeEvent.emplace_back(event.second, -1);
    }

    // Sort by time; if same time, end (-1) before start (+1)
    //sorting this will have same time event or overlapping event one after another
    sort(timeEvent.begin(), timeEvent.end());
    //we got a counter
    //each time a event starts the counter++ and each time a event ends counter --
    //we need to find the max times counter goes ++

    int current = 0, maxConcurrent = 0;
    //time = whatever time is recorded in pair
    //change is counter when we record the time change
    for (auto [time, change] : timeEvent) {
        //each time a change is recorded we move this
        current += change;
        //max of whatever event is going on
        maxConcurrent = max(maxConcurrent, current);
    }
    return maxConcurrent;
}

int main(){
    vector<pair<int, int>> events = {
        {1, 5},
        {2, 6},
        {4, 7},
        {5, 8},
        {9, 10}
    };

    cout << "Max concurrent events: " << maxConcurrentEvents(events) << endl;
}