#include "headerHashTables.h"

/*
Implement a function called itemInCommon() 
that checks if two input vectors have at least one common item.
Consider the following input vectors:

vect1: {1, 2, 3, 4, 5}
vect2: {4, 5, 6, 7, 8}

After calling itemInCommon(vect1, vect2), the result should be:
true
*/

/*o(n^2)
bool itemInCommon(vector<int> vect1, vector<int> vect2) {

    for(int i : vect1){
        for(int j : vect2){
            if(i == j) return true;
        }
    }
    return false;
}
*/

bool itemInCommon(vector<int> vect1, vector<int> vect2) {                                          
	// - 'myMap' stores elements from 'vect1' as keys.  
	// - Loop through 'vect2' and check against 'myMap'.
	// - Check output from Test.cpp in "User logs".     
	//   +=====================================================+
	//o(n)
	unordered_map<int, bool> unMap;
	for(auto i : vect1){
		unMap.insert({i,true});
	}
	for(int j : vect2){
		if(unMap[j]) return true;

	}
	return false;
}

int main(){
    vector<int> vect1 = {1, 2, 3, 4, 5};
    vector<int> vect2 = {0, 6, 7, 8, 9};

    cout<<itemInCommon(vect1,vect2);
}