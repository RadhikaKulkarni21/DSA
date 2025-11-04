#include <vector>
#include <algorithm>
#include <iostream>
#include <limits>
using namespace std;

vector<int> getMinimumLength(int roads_nodes, vector<int> roads_from, vector<int> roads_to, vector<int> roads_weight) {
    if(roads_nodes <= 0)return {};
//give TSP/DFs
long long num = 1e15;

vector<vector<long long>> L(roads_nodes+1,vector<long long> (roads_nodes + 1, num));

for(int i = 1; i <= roads_nodes;i++){
    L[i][i] = 0;//adjacent houses
}

int num_roads = roads_from.size();

for(int i = 0; i < num_roads; i++){//matrix to get the corresondance
    int f = roads_from[i];
    int t = roads_to[i];
    int w = roads_weight[i];
    
    if(f >= 1 && f <= roads_nodes && t >= 1 && t <=roads_nodes){
        L[f][t] = min(L[f][t], (long long)w);
    }
}

for(int k = 1; k <= roads_nodes;k++){
    for(int i = 1;i <= roads_nodes;i++){
        for(int j = 1; j <= roads_nodes;j++){
            if(L[i][k] != num && L[k][j] != num){
                L[i][j] = min(L[i][j], L[i][k]+L[k][j]);
            }
        }
    }
}

vector<int> result(roads_nodes);
for(int i = 1;i <= roads_nodes;i++){
    long long min_length = L[i][i];
    
    if(min_length > 0 && min_length != num){
        result[i - 1] = int(min_length);
    }
    else{
        result[i - 1] = 0;
    }//???
}
return result;
}