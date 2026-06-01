#include "R:\C++\Project1\lcHeader.h"


int getMinimumDifference(int g_nodes, vector<int> g_from, 
                          vector<int> g_to, vector<int> g_weight) {
    int m = g_weight.size();
    
    // Build and sort edges
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        edges[i][0] = g_weight[i];
        edges[i][1] = g_from[i];
        edges[i][2] = g_to[i];
    }
    sort(edges.begin(), edges.end()); // sorts by first element (weight) by default
    
    int ans = INT_MAX;
    
    for (int left = 0; left < m; left++) {
        // reset parent
        vector<int> parent(g_nodes + 1);
        for(int i = 0; i <= g_nodes; i++) parent[i] = i;
        
        int edges_used = 0;
        
        for (int right = left; right < m; right++) {
            // find with path compression
            int x = edges[right][1];
            while(parent[x] != x) x = parent[x];
            int pu = x;
            
            int y = edges[right][2];
            while(parent[y] != y) y = parent[y];
            int pv = y;
            
            if (pu != pv) {
                parent[pu] = pv;
                edges_used++;
            }
            
            if (edges_used == g_nodes - 1) {
                ans = min(ans, edges[right][0] - edges[left][0]);
                break;
            }
        }
    }
    
    return ans == INT_MAX ? -1 : ans;
}

int main(){
//idk very complex problem to even understand
}
