#include "R:\C++\Project1\lcHeader.h"
/*
We want to detect signal quality problems. Pots, in a linear office, 
we run a roboard that goes to and throw while measuring signal strength to get signal quality.
We compute the population standard error for each m consequent measurement. 
And compare the obtained value with some tolerance 
When the population standard exceeds the tolerant, we have a problem sport.
The task is to return some of sliding window indexes , 
one based where the population standard error is greater than the tolerance

https://en.wikipedia.org/wiki/Standard_error - PSE
*/

int detectSignalProblems(vector<double> measurement, int ml, int m, double tolerances){
    //m is the sliding window lenght
    //ml is the size of vector measurement

    if(m > ml || m <= 0) return 0;

    int problems = 0;

    for(int i = 0;i < ml - m;i++){
        double total = 0, sq = 0;

        for(int j = i; j < i + m;j++){
            total += measurement[j];
            sq = measurement[j] * measurement[j];
        }

        double mean = total/m;
        double varience = (sq/m) - (mean * mean);
        double stdDev = sqrt(varience);
        double pse = stdDev / sqrt(m);

        if(pse > tolerances){
            problems += (i + 1);
        }
    }
    return problems;
}

int main() {
    vector<double> measurement = {5.1, 5.0, 4.9, 5.2, 6.8, 7.1, 7.0, 5.0, 4.8, 4.9};
    int m = 4;
    double tolerance = 0.1;

    int result = detectSignalProblems(measurement, measurement.size(), m, tolerance);
    cout << "Sum of 1-based indexes of problematic windows = " << result << endl;
}