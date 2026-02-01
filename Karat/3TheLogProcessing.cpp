/*
This is common for Data or Backend roles and focuses on time-window logic.
*/

#include "R:\C++\Project1\lcHeader.h"

/*
============================================================
Part 1: Given a list of logs [user_id, timestamp, page_id], 
find the earliest and latest access time for each user.
============================================================
*/
//assuming this is given log 
struct Logs{
    string userID;
    vector<vector<string>> timestamp;
    string page_id;
};
//we are returning each users times
//so we use unordered_maps

//since logs are string
//we cant use int for userID
unordered_map<string, pair<string, string>> earliestAndLate(vector<vector<string>> logs){
    unordered_map<string, pair<string, string>> mp;

    for(auto log : logs){
        string user = log[0];
        string time = log[1];

        //check if user already exists in map
        if(!mp.count(user)){//user does not exist 
            //map the times in maps
            //string user = pair<string time, string time>
            //user is the key and time, time are the access times
            //for the initial one both will be same
            mp[user] = {time, time};
        }
        else{
            mp[user].first = min(mp[user].first, time);
            mp[user].second = max(mp[user].second, time);
        }
    }
    return mp;
}

/*
============================================================
Part 2: Identify "loyal customers" who visited the site on 
two different days and viewed at least two unique pages on each day.
============================================================
*/
vector<string> loyalCustomer(vector<vector<string>>& logs){
    unordered_map<string, unordered_map<string, unordered_set<string>>> visit;

    for(auto log  : logs){
        string user = log[0];
        string time = log[1];
        string page = log[2];

        //because time also has HH:MM, we skip those
        //so we take substring
        string date = time.substr(0,10);

        //because visit is a set, this will only enter unique pages
        visit[user][date].insert(page);
    }

    //visit[user][date][page/s]

    vector<string> result;
    //days[date] = set of unique pages on that date
    //days = {
    //"2023-01-01": {"Home", "Login"},
    //"2023-01-02": {"Home", "Search"}
    //}
    //All the dates the user has visited are accumulated into day
    for(auto& [user, days] : visit){
        int uniqueDays = 0;

        //[date, pages] == one day’s activity
        for(auto& [date, page] : days){
            //for a date and page on a day, 
            //if the pages are more than 2, we increase the counter
            if(page.size() >= 2){
                uniqueDays++;
            }
        }
        if(uniqueDays >= 2){
            result.push_back(user);
        }
    }
    return result;
}

/*
============================================================
Part 3: Find the most common 3-page sequence 
(e.g., User A visited: Home -> Login -> Logout).
============================================================
*/

string mostCommonSequence(vector<vector<string>>& logs){
    unordered_map<string, vector<pair<string, string>>> userPages;

    for(auto& log: logs){
        //user.push({timestamps, page})
        userPages[log[0]].push_back({log[1], log[2]});
    }

    unordered_map<string, int> freq;

    /*
    Key = user (string)

    Value = pages → vector<pair<string, string>>
    Each pair = (timestamp, page)

    This loop iterates user by user, giving us all their visit history.
    */
    for(auto& [user, page] : userPages){
        //get the proper sequence 
        //sorts first by a.first=timestamp),then by a.second=page if timestamps tie
        sort(page.begin(), page.end());

        //make the sequence
        //i+ to create a sliding window as we need 3 pages
        for(int i = 0; i + 2 < page.size(); i++){
            string seq = page[i].second + " " + page[i + 1].second + " "
            + page[i + 2].second;

            freq[seq]++;
        }
    }

    string ans;
    int max = 0;

    //freq is the seq and count
    for(auto& [seq, count] : freq){
        if(count > max){
            max = count;
            ans = seq;
        }
    }
    return ans;
}
