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

int getMinimumDifference(int g_nodes, vector<int> g_from,vector<int> g_to, vector<int> g_weight) {
    int m = g_weight.size();
    
    // Build and sort edges
    vector<vector<int>> edges(m, vector<int>(3));
    for(int i = 0; i < m; i++) {
        edges[i][0] = g_weight[i];//we put weight first so that we can sort with weight
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
            while(parent[x] != x) x = parent[x];//preventing cycles
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
    int g_nodes = 4;
    vector<int> g_from = {1,2,3,4};
    vector<int> g_to = {2,3,4,2};
    vector<int> g_weight = {-1,2,5,3};

   int result = getMinimumDifference(g_nodes,g_from,g_to, g_weight);

   cout << "Minimum Difference is: " << result;
}

/*
Spanning tree problem - connect all nodes without cycles
Considering we need to connect 4 nodes, we need 3 edges
first for loop
g_weight = [-1, 2, 5, 3]
g_from   = [1,  2, 3, 2]
g_to     = [2,  3, 4, 4]

after loop
edges[0] = [-1, 1, 2]   (weight=-1, from node1, to node2)
edges[1] = [2,  2, 3]   (weight=2,  from node2, to node3)
edges[2] = [5,  3, 4]   (weight=5,  from node3, to node4)
edges[3] = [3,  2, 4]   (weight=3,  from node2, to node4)

after sort
edges[0] = [-1, 1, 2]   
edges[1] = [2,  2, 3]   
edges[2] = [3,  2, 4]   
edges[3] = [5,  3, 4]

while(parent[x] != x) x = parent[x]
This is to prevent repetation/cycles if the parent is pointing towards itself that
means we have already counted the node and its pointing towards itself

the left loop is to check if this node should be included in the path or not
the right loop is keep adding edges until all nodes are connected

once the tree is complete we substract the difference

What tracing would look like:
Sorted edges:
edges[0] = [-1, 1, 2]   
edges[1] = [2,  2, 3]   
edges[2] = [3,  2, 4]   
edges[3] = [5,  3, 4]
Parent array at start:
parent = [0, 1, 2, 3, 4]
4 separate groups: {1}, {2}, {3}, {4}

right = 0, trying edge [-1, 1, 2]
Find group of node 1:
parent[1] = 1 → stops, pu = 1
Find group of node 2:
parent[2] = 2 → stops, pv = 2
pu != pv → different groups → safe to add!
parent[1] = 2,  edges_used = 1
Groups: {1,2}, {3}, {4}

right = 1, trying edge [2, 2, 3]
Find group of node 2:
parent[2] = 2 → stops, pu = 2
Find group of node 3:
parent[3] = 3 → stops, pv = 3
pu != pv → safe to add!
parent[2] = 3,  edges_used = 2
Groups: {1,2,3}, {4}

right = 2, trying edge [3, 2, 4]
Find group of node 2:
parent[2] = 3 → parent[3] = 3 → stops, pu = 3
Find group of node 4:
parent[4] = 4 → stops, pv = 4
pu != pv → safe to add!
parent[3] = 4,  edges_used = 3
Groups: {1,2,3,4}

edges_used = 3 = g_nodes - 1 → spanning tree complete!
diff = edges[2][0] - edges[0][0] = 3 - (-1) = 4
ans = 4
break!
*/
