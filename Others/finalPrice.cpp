/*
A shopkeeeper arranges items ina list for sale,
each item is sold at its full price minus the price to 
its right that is of equal or lower price. 
If no such item exists the current item is sold at full price.
Print the sum of the final cost for all items 
then on the next line print space separated 0 based indices 
of items that are sold at full price in ascending order
*/
#include "R:\C++\Project1\lcHeader.h"

void finalprice(vector<int> prices) {
    int n = prices.size();
    vector<int> discount(n, 0);
    stack<int> st;

    // Traverse from right to left to find next smaller/equal element
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() > prices[i])
            st.pop();

        if (!st.empty())
            discount[i] = st.top();

        st.push(prices[i]);
    }

    long long total = 0;
    vector<int> fullPriceIndices;

    for (int i = 0; i < n; i++) {
        if (discount[i] == 0)
            fullPriceIndices.push_back(i);
        total += (prices[i] - discount[i]);
    }

    cout << total << "\n";
    for (int i = 0; i < fullPriceIndices.size(); i++) {
        cout << fullPriceIndices[i];
        if (i < fullPriceIndices.size() - 1)
            cout << " ";
    }
    cout << "\n";
}

int main() {
    // Example usage:
    vector<int> prices = {5, 1, 3, 4, 6, 2};
    finalprice(prices);
    return 0;
}
