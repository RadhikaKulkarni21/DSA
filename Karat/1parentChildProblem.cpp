/*
The Parent-Child (Family Tree) Problem
Part 1	Zero / One Parent	O(N)	O(V)
Part 2	Common Ancestor 	O(N)	O(V)
Part 3	Earliest Ancestor	O(N)	O(V)
*/

#include "R:\C++\Project1\lcHeader.h"

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
        //we use set to remove duplicate parents/children
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


/*
Part 2: Given the same pairs and two specific individuals, 
write a function that returns True if they share at least one common ancestor.
*/
//we are traversing bottom up
void dfs(
    int person,
    //parent would be integer and vector followed would be all the children
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
        //for each parent push the child
        //when we go bottom to top
        parents[p[1]].push_back(p[0]);
    }

    unordered_set<int> ancestors1, ancestors2;

    dfs(person1, parents, ancestors1);
    dfs(person2, parents, ancestors2);

    //For every ancestor of person1, 
    //check if that same person is also an ancestor of person2.
    for (int a : ancestors1) {
        if (ancestors2.count(a))
            return true;
    }
    return false;
}

/*Part 3: Given one individual, find their earliest ancestor
(the person at the highest level of the tree). 
If there is a tie, any one is usually fine.*/
/*TODO: WRITE EXPLANATION*/
void dfs(
    int curr,//whatever the current person is
    int depth,//how upwards we can go to find the parent
    unordered_map<int, vector<int>>& parents,
    int& earliest,//the topmost
    int& maxDepth//depth store bc we need to traverse thru different set of persons
) {
    // Base case: reached a root ancestor
    if (parents[curr].empty()) {
        if (depth > maxDepth) {
            maxDepth = depth;
            earliest = curr;
        }
        return;
    }

    // Recurse on all parents
    for (int p : parents[curr]) {
        dfs(p, depth + 1, parents, earliest, maxDepth);
    }
}

int findEarliestAncestor(
    vector<vector<int>>& pairs,
    int person
) {
    unordered_map<int, vector<int>> parents;

    // Build child -> parents map
    for (auto& p : pairs) {
        //pushing each parent with child
        parents[p[1]].push_back(p[0]);
    }

    int earliest = -1;
    int maxDepth = -1;

    dfs(person, 0, parents, earliest, maxDepth);

    return earliest;
}