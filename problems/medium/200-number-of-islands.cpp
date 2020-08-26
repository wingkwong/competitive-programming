/*
Number of Islands

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3
*/

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(grid[row][col]=='1'){
                    ff(grid,row,col);
                    ans++;
                }
            }
       }
       return ans; 
    }
private:
    // flood fill algo
    void ff(vector<vector<char>>& grid, int row, int col){
        if(row<0||col<0||row>=grid.size()||col>=grid[0].size()||grid[row][col]!='1') return;
        grid[row][col] = '0';
        ff(grid,row+1,col);
        ff(grid,row-1,col);
        ff(grid,row,col+1);
        ff(grid,row,col-1);
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();