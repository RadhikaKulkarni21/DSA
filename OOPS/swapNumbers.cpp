#include "R:\C++\Project1\lcHeader.h"

class Solution{
public:
    void swapNumbersTemp(int a, int b){
        int temp = 0;
        temp = a;
        a = b;
        b = temp;
    }

    void SwapNumbersArth(int a, int b){
        a = a + b;
        b = a - b;
        a = a - b;
    }

    void SwapNumbersBit(int a, int b){
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }
};

int main(){
    Solution s;
    int a = 10;
    int b = 20;
    //s.swapNumbersTemp(a,b);
    s.SwapNumbersArth(a,b);
    //s.SwapNumbersBit(a,b);
    cout << "a = " << a << " b = " << b << endl;
}