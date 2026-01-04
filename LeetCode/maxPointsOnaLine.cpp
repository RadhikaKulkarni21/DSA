/*
Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane,
return the maximum number of points that lie on the same straight line.
*/

#include "R:\C++\Project1\lcHeader.h"

int maxPoints(vector<vector<int>>& points) {
 int number = 2;
 //2 bc at any given 2 points a line will exist
 //so we don't need to code the logic
 
 int n = points.size();

 //if it has one point it will always be on the line
 if(n == 1) return 1;

 for(int i = 0; i < n - 1;i++){
    map<double, int> tangentMap;
    for(int j = 0; j < n; j++){
        if(i == j) continue;//we will skip all the 1,1 2,2 3,3

        int x1 = points[i][0];
        int y1 = points[i][1];
        int x2 = points[j][0];
        int y2 = points[j][1];

        //slope is tan = (y2 - y1)/(x2 - x1)
        double tan = atan2((y2 - y1), (x2 - x1));

        tangentMap[tan]++;//increment slope found

        number = max(number, tangentMap[tan]+ 1);
        //+1 bc the point itself is never counted
        //we are counting points with similar slopes but 
        //not the original point with the slope
    }
 }
 return number;
}

int main(){
    vector<vector<int>> points = {{1,1}, {2,2}, {3,3}};

    cout<<maxPoints(points);//expected OP: 3
}

/*
For each point, we will calculate the tangent with other points.
We will store them into a tangent map.
After it is done, we will calculate the max points that have the same tangent from the tangentMap.
Finally, return the max.

Continue skips only one iteration for one condition
so it will skip [1,1] but continue for [1,2] and [1,3]
*/