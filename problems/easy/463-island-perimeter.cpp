/*
Island Perimeter

You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.


Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // a) count how many islands, multiply by 4
        // b) count how many neighours, multiply by 2 
        // ans = a) - b)
        int c=0, cc=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    c++;
                    if(i!=0&&grid[i-1][j]==1) cc++;
                    if(j!=0&&grid[i][j-1]==1) cc++;
                }
            }
        }
        return 4*c-2*cc;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();