#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Graph{
    public:
    unordered_map<string, unordered_set<string>> adjList;

    void printGraph() {
            unordered_map<string, unordered_set<string>>::iterator kvPair = adjList.begin();
            while (kvPair != adjList.end()) {
                cout << kvPair->first << ": [";
                unordered_set<string>::iterator edge = kvPair->second.begin();
                bool first = true;
                while (edge != kvPair->second.end()) {
                    if (!first) {
                        cout << ", ";
                    }
                    cout << *edge;
                    edge++;
                    first = false;
                }
                cout << "]" << endl;
                kvPair++;
            }
        }

    //adding a new vertex
    bool addVertex(string vertex){
        if(adjList.count(vertex) == 0){//for that vertex is 0, then only we add or else it is already present
            adjList[vertex];  //{ "A" : [] }
            return true;
        }
        return false;
    }

    //adding a new edge
    bool addEdge(string vertex1, string vertex2){
        if(adjList.count(vertex1) != 0 && adjList.count(vertex2) != 0){
        adjList.at(vertex1).insert(vertex2);
        adjList.at(vertex2).insert(vertex1);
        return true;
        }
        return false;
    }

    bool removeEdge(string vertex1, string vertex2){
        if(adjList.count(vertex1)!=0 && adjList.count(vertex2)!=0){
            adjList.at(vertex1).erase(vertex2);
            adjList.at(vertex2).erase(vertex1);
            return true;
        }
        return false;
    }

    /*
    "A" = ["B","C","D"],
    "B" = ["A","D"],
    "C" = ["A","D"],
    "D" = ["A","B","C"]
    */
   bool removeVertex(string vertex){
    if(adjList.count(vertex) == 0)return false;
    //this for loop will pick up the "A" in "D" vertex
    
    for (auto otherVertex : adjList.at(vertex)){
        //this is gonna return whatever edge is associated with the vertex
        //then at othervertex "A" it will earse asked vertex which is "D"
        adjList.at(otherVertex).erase(vertex);
     }
     adjList.erase(vertex);
     return true;
   }
   
};

int main(){
    Graph* newGraph = new Graph();
    newGraph->addVertex("A");
    newGraph->addVertex("B");
    newGraph->addVertex("C");
    newGraph->addVertex("D");

    newGraph->addEdge("A","B");
    newGraph->addEdge("A","C");
    newGraph->addEdge("A","D");
    newGraph->addEdge("B","D");
    newGraph->addEdge("C","D");
    cout<<"Before: "<<"\n";
    newGraph->printGraph();

    //newGraph->removeEdge("A","B");
    newGraph->removeVertex("D");
    cout<<"After: "<<"\n";
    newGraph->printGraph();
}