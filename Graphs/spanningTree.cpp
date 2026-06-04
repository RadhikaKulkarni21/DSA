/*
Connect ALL nodes using minimum edges (exactly n-1 edges), with no cycles.
We have 4 edges but only need 3, so we remove 1 edge each time:
Remove edge weight 5 -1, 2, 3 max=3, min=-1  diff = 4
Remove edge weight 3-1, 2, 5 max=5, min=-1 diff = 6
Remove edge weight 2-1, 3, 5max=5, min=-1 diff = 6
Remove edge weight -12, 3, 5max=5, min=2 diff = 3  
but last one disconnects node 1
*/

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

}

/*
Spanning tree problem - connect all nodes without cycles
Considering we need to connect 4 nodes, we need 3 edges
*/
