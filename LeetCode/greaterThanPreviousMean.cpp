#include "R:\C++\Project1\lcHeader.h"

int countResponseTimeRegressions(vector<int> responseTimes) {
 int count = 0;
 long sum = 0;
 for(int i = 0;i < responseTimes.size();i++){
    if(i  != 0){    
        int avg = sum / i;
        if(avg < responseTimes[i]) count++;   
    }
    sum += responseTimes[i];
 }
 
 return count;
}

int main(){
    vector<int> responseTimes = {100, 200, 150,300};

    cout<< countResponseTimeRegressions(responseTimes)<<endl;
}