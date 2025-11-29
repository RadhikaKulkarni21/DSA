#include "R:\C++\Project1\lcHeader.h"

/*
Given a list of integers representing notification timestamps (in seconds) and
a rate limit k, 
write a function to determine which notifications would be delivered 
if no more than k notifications can be sent in any sliding window of 10 seconds.

timestamps = [1, 2, 3, 11, 12, 13, 14]  
k = 3
*/

vector<int> notifDelivered(vector<int> timestamps, int k){
    vector<int> notifSent;
    deque<int> timeFrame;//works as a stack and queue and used for sliding window

    for(int t : timestamps){
        //we check if the first ttimestamp
        //the second part compares if the next timestamp is actually false
        while(!timeFrame.empty() && t - timeFrame.front() >= 10){
            timeFrame.pop_front();
        }

        //we are pushing this in both the vector and deque
        if(timeFrame.size() < k){
            timeFrame.push_back(t);
            notifSent.push_back(t);
        }
    }
    return notifSent;
}

int main(){

}

/*
deliveryNotifs = []

timeframe = [] (deque)

1️⃣ t = 1

Remove old: timeframe empty → nothing removed

timeframe.size() = 0 < k → deliver 1

deliveryNotifs = [1]

timeframe = [1]

2️⃣ t = 2

Remove old: 2 - 1 < 10 → nothing removed

timeframe.size() = 1 < 3 → deliver 2

deliveryNotifs = [1, 2]

timeframe = [1, 2]

3️⃣ t = 3

Remove old: 3 - 1 < 10 → nothing removed

timeframe.size() = 2 < 3 → deliver 3

deliveryNotifs = [1, 2, 3]

timeframe = [1, 2, 3]

4️⃣ t = 8

Remove old: 8 - 1 < 10 → nothing removed

timeframe.size() = 3 == k → discard 8

deliveryNotifs = [1, 2, 3]

timeframe = [1, 2, 3]

5️⃣ t = 10

Remove old: 10 - 1 = 9 < 10 → nothing removed

timeframe.size() = 3 == k → discard 10

6️⃣ t = 11

Remove old: 11 - 1 = 10 >= 10 → remove 1

timeframe = [2, 3]

timeframe.size() = 2 < 3 → deliver 11

deliveryNotifs = [1, 2, 3, 11]

timeframe = [2, 3, 11]

7️⃣ t = 12

Remove old: 12 - 2 = 10 >= 10 → remove 2

timeframe = [3, 11]

timeframe.size() = 2 < 3 → deliver 12

deliveryNotifs = [1, 2, 3, 11, 12]

timeframe = [3, 11, 12]

8️⃣ t = 21

Remove old:

21 - 3 = 18 >= 10 → remove 3

21 - 11 = 10 >= 10 → remove 11

21 - 12 = 9 < 10 → stop

timeframe.size() = 1 < 3 → deliver 21

deliveryNotifs = [1, 2, 3, 11, 12, 21]

timeframe = [12, 21]
*/