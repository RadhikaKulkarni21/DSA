/*Theory in notes*/

#include "R:\C++\Project1\lcHeader.h"

void quadProbing(vector<int>& table, int tsize, vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n; i++) {
        // Hash function
        int hv = arr[i] % tsize;

        if (table[hv] == -1) {
            // Place directly if slot is empty
            table[hv] = arr[i] ;
        }
        else {
            // Quadratic probing in case of collision
            for (int j = 1; j <= tsize; j++) {
                // Compute new index using quadratic probing
                int t = (hv + j * j) % tsize;

                // Place element if new slot is empty
                if (table[t] == -1) {
                    table[t] = arr[i];
                    break;
                }
            }
        }
    }
}

int main() {
    vector<int> arr = { 50, 700, 76, 85, 92, 73, 101 };

    int tsize = 11 ;

    vector<int> table(tsize, -1) ;

    quadProbing(table, tsize, arr) ;

    for (int i = 0; i < table.size(); i++) {
        cout << table[i] << " ";
    }

    return 0;
}