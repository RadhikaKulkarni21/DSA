/*
The Rectangle Finder (Matrix) 
This problem focuses on 2D array traversal and coordinate tracking.

Part 3: Instead of rectangles, there are now irregularly shaped "blobs" of 0s.
Return the coordinates of every cell that belongs to each blob.
*/

#include "R:\C++\Project1\lcHeader.h"

/*
Part 1: You are given a 2D matrix of 1s and 0s. 
There is exactly one rectangle of 0s. 
Return its top-left and bottom-right coordinates. 
*/

#include <vector>
using namespace std;

pair<pair<int,int>, pair<int,int>> findSingleRectangle(const vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (mat[r][c] == 0) {
                int top = r, left = c;
                //assuming 0 is the top left corner

                int right = c;
                //keep moving right till we hit a 1 and get the width
                while (right + 1 < cols && mat[r][right + 1] == 0)
                    right++;

                //keep moving down till we hit a 1 and get the height
                int bottom = r;
                while (bottom + 1 < rows && mat[bottom + 1][c] == 0)
                    bottom++;

                return {{top, left}, {bottom, right}};
            }
        }
    }
    return {{-1, -1}, {-1, -1}}; // should never happen
}

/*
Part 2: Now, there can be multiple rectangles of 0s.
They will not be touching. Return the coordinates for all of them.
*/

#include <vector>
using namespace std;

vector<pair<pair<int,int>, pair<int,int>>> findAllRectangles(vector<vector<int>>& mat) {
    int rows = mat.size(), cols = mat[0].size();
    //creating a matrix and marking all as F for not visited
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    //answer matrix
    vector<pair<pair<int,int>, pair<int,int>>> rectangles;

    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            if (mat[r][c] == 0 && !visited[r][c]) {
                int top = r, left = c;

                int right = c;
                while (right + 1 < cols && mat[r][right + 1] == 0)
                    right++;

                int bottom = r;
                while (bottom + 1 < rows && mat[bottom + 1][c] == 0)
                    bottom++;

                //we mark visited or it will keep counting the same rectangle
                for (int i = top; i <= bottom; i++)
                    for (int j = left; j <= right; j++)
                        visited[i][j] = true;

                rectangles.push_back({{top, left}, {bottom, right}});
            }
        }
    }
    return rectangles;
}
