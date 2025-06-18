#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;


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
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function checks if two vectors have a        |
	//   |   common element.                                   |
	//   | - It uses an unordered_map to store elements from   |
	//   |   the first vector.                                 |
	//   | - Then it checks each element from the second       |
	//   |   vector against the map.                           |
	//   |                                                     |
	//   | Return type: bool                                   |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'myMap' stores elements from 'vect1' as keys.     |
	//   | - Loop through 'vect2' and check against 'myMap'.   |
	//   | - Check output from Test.cpp in "User logs".        |
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