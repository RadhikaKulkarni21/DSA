#include "R:\C++\Project1\lcHeader.h"
//DFS
class Solution{
public:
    int numIslands(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                if(grid[i][j] == '1'){
                    islands++;
                    eraseIsland(grid,i,j);//mark them zero bc we reuse the grid
                }
            }
        }
        return islands;
    }

private:
    void eraseIsland(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') return;

        grid[i][j] = '0';//if grid is zero we move next
        eraseIsland(grid, i - 1, j);//up
        eraseIsland(grid, i + 1, j);//down
        eraseIsland(grid, i, j - 1);//left
        eraseIsland(grid, i, j + 1);//right
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    Solution s;
    cout<< s.numIslands(grid);
}

/*
1 1 0 0
1 0 0 1
0 0 1 1

Cell (0,0) = '1'

New island found → islands = 1

Call eraseIslands(0,0)

This erases:

1 1 0 0     →     0 0 0 0
1 0 0 1           0 0 0 1
0 0 1 1           0 0 1 1

Continue scanning

All erased '0' → skipped

Cell (1,3) = '1'

New island → islands = 2

Erase connected land

Grid becomes:

0 0 0 0
0 0 0 0
0 0 1 1

Cell (2,2) = '1'

New island → islands = 3

Erase connected land

Grid becomes:

0 0 0 0
0 0 0 0
0 0 0 0

Final answer
return islands; // 3
*/