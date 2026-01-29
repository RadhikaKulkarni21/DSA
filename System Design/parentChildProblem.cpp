#include "R:\C++\Project1\lcHeader.h"

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

vector<vector<int>> findParents(vector<vector<int>> pairs){
    unordered_map<int, int> parentCount;
    unordered_set<int> people;

    for(auto p : pairs){
        int parent = p[0];
        int child = p[1];

        parentCount[child]++;
        //for common ancestory
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