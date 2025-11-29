/*
Jack lives in city 0 and he wants to plan a trip and 
visit as many cities as possible. He does not want to visit any city more than once 
and he can only move along direct roads. 
But Each city labeled with Odd number can be visited at most one. 
given a vector T consisting of N integers describing network of N cities and N-1 roads,
return the max number of cities that jack can visit. 
How many cities can be visited including the starting one he can visit.
*/

#include "R:\C++\Project1\lcHeader.h"

int dfs(int currCity, int city0, vector<vector<int>> adj,bool oddCityVisited){
    int maxLen = 1;
    
    for(int c : adj[currCity]){
        if(c == city0) continue;
        if(c % 2 == 1 && oddCityVisited) continue;

        maxLen = max(maxLen, 1 + dfs(c, currCity, adj, oddCityVisited || (c % 2 == 1)));
    }
    return maxLen;
}

int solution(vector<int> &T) {
    // Implement your solution here
    
    int t = T.size();
    vector<vector<int>> adj(t);

    for(int i = 1; i < t; i++){
        adj[i].push_back(T[i]);
        adj[T[i]].push_back(i);
    }

    return dfs(0, -1, adj, (0 % 2 == 1));
}

/*
https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/
*/