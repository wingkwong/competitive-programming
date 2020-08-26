/*
Max Area of Island

Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.
*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=(int)grid.size();
        int c=(int)grid[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                // perform dfs to find out the max value
                if(grid[i][j]) ans=max(ans,dfs(i,j,grid));
            }
        }
        return ans;
    }
private:
    int ans=0;
    int dfs(int i, int j, vector<vector<int>>& grid){
        int r=(int)grid.size();
        int c=(int)grid[0].size(); 
        // set grid[i][j] to 0 (visited) if it is not out of bound or zero value
        if(i>=0&&i<r&&j>=0&&j<c&&grid[i][j]){
            grid[i][j]=0;
            // add 1 plus the results from 4 directions
            return 1+ dfs(i+1,j,grid)+dfs(i-1,j,grid)+dfs(i,j+1,grid)+dfs(i,j-1,grid);
        }
        return 0;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();