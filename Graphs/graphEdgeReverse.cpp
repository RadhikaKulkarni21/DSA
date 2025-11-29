#include "R:\C++\Project1\lcHeader.h"

/*
A country represented as a graph with gnodes cities connected by gnodes-1
 uni directional edges. The ith edge connects cities g_from[i] to g_to[i]. 
 If roads are bidirectional the graph would be a tree. 
 For each city find the minimum number of edges that must be reversed 
 so that it is possible to travel from city i to any other city 
 using directed edges
*/

vector<int> count(int gnodes, vector<int> gfrom, vector<int> gto) {
    vector<vector<pair<int, int>>> graph(gnodes + 1);

    // Build graph with direction info
    for (int i = 0; i < gnodes - 1; i++) {
        int u = gfrom[i], v = gto[i];
        graph[u].push_back({v, 0}); // original direction u->v (no reversal)
        graph[v].push_back({u, 1}); // reverse direction would need 1 reversal
    }

    vector<int> ans(gnodes + 1, 0);

    // First DFS: compute reversals needed if root = 1
    function<int(int, int)> dfs1 = [&](int u, int parent) {
        int total = 0;
        for (auto [v, cost] : graph[u]) {
            if (v == parent) continue;
            total += cost + dfs1(v, u);
        }
        return total;
    };

    int rootCost = dfs1(1, -1);

    // Second DFS: re-root to compute cost for all nodes
    function<void(int, int, int)> dfs2 = [&](int u, int parent, int currentCost) {
        ans[u] = currentCost;
        for (auto [v, cost] : graph[u]) {
            if (v == parent) continue;
            int newCost = currentCost + (cost == 0 ? 1 : -1);
            dfs2(v, u, newCost);
        }
    };

    dfs2(1, -1, rootCost);

    // Return answers excluding index 0 (1-indexed cities)
    vector<int> res;
    for (int i = 1; i <= gnodes; i++) {
        res.push_back(ans[i]);
    }
    return res;
}
