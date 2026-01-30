/*
The Parent-Child (Family Tree) Problem

Part 2: Given the same pairs and two specific individuals, 
write a function that returns True if they share at least one common ancestor.

Part 3: Given one individual, find their earliest ancestor
 (the person at the highest level of the tree). 
 If there is a tie, any one is usually fine.
*/

#include "R:\C++\Project1\lcHeader.h"

//case where class needs to exist for whole code to run
class FamilyTree{
    //each parent to children
    unordered_map<int, vector<int>> parent;
    //each children of parent
    unordered_map<int, vector<int>> children;
    unordered_map<int, int> parentCount;
    unordered_set<int> people;

public:
    FamilyTree(const vector<pair<int, int>> pairs) {
        for(auto p : pairs){
            int par = p.first;
            int child = p.second;

            parent[child].push_back(par);
            children[par].push_back(child);
            parentCount[child]++;
            people.insert(par);
            people.insert(child);
        }
    }
};

/*Part 1: Given a list of [parent, child] pairs, find:

All individuals with zero parents (roots).

All individuals with exactly one parent.*/
vector<vector<int>> findParents(vector<vector<int>> pairs){
    unordered_map<int, int> parentCount;
    unordered_set<int> people;

    for(auto p : pairs){
        int parent = p[0];
        int child = p[1];

        //each parent got 1+ child
        parentCount[child]++;

        //if only one parent or one child
        // we use set to remove duplicate parents/children
        people.insert(parent);
        people.insert(child);
    }

    vector<int> zeroParent, oneParent;

    for(int per : people){
        if(parentCount[per] == 0){
            zeroParent.push_back(per);
        }
        else if(parentCount[per] == 1){
            oneParent.push_back(per);
        }
    }
    return {zeroParent, oneParent};
}

void dfs(
    int person,
    unordered_map<int, vector<int>>& parents,
    unordered_set<int>& visited
) {
    for (int p : parents[person]) {
        if (!visited.count(p)) {
            visited.insert(p);
            dfs(p, parents, visited);                                                                 
        }
    }
}

bool hasCommonAncestor(
    vector<vector<int>>& pairs,
    int person1,
    int person2
) {
    unordered_map<int, vector<int>> parents;

    for (auto& p : pairs) {
        parents[p[1]].push_back(p[0]);
    }

    unordered_set<int> ancestors1, ancestors2;

    dfs(person1, parents, ancestors1);
    dfs(person2, parents, ancestors2);

    for (int a : ancestors1) {
        if (ancestors2.count(a))
            return true;
    }

    return false;
}


int findEarliestAncestor(
    vector<vector<int>>& pairs,
    int person
) {
    unordered_map<int, vector<int>> parents;

    for (auto& p : pairs) {
        parents[p[1]].push_back(p[0]);
    }

    int earliest = -1;
    int maxDepth = -1;

    function<void(int, int)> dfs = [&](int curr, int depth) {
        if (parents[curr].empty()) {
            if (depth > maxDepth) {
                maxDepth = depth;
                earliest = curr;
            }
            return;
        }

        for (int p : parents[curr]) {
            dfs(p, depth + 1);
        }
    };

    dfs(person, 0);
    return earliest;
}
