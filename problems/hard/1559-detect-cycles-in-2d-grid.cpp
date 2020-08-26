/*
Detect Cycles in 2D Grid

Given a 2D array of characters grid of size m x n, you need to find if there exists any cyclic consisting of the same value in grid.

A cyclic is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.

Also, you cannot move to the cell that you visited in your last move. For example, the cyclic (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.

Return true if any cyclic of the same value exists in grid, otherwise, return false.


Example 1:


Input: grid=[["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
Output: true
Explanation: There are two valid cyclics shown in different colors in the image below:

Example 2:

Input: grid=[["c","c","c","a"],["c","d","c","c"],["c","c","e","c"],["f","c","c","c"]]
Output: true
Explanation: There is only one valid cyclic highlighted in the image below:

Example 3:

Input: grid=[["a","b","b"],["b","z","b"],["b","b","a"]]
Output: false


Constraints:

m==grid.length
n==grid[i].length
1 <= m <= 500
1 <= n <= 500
grid consists only of lowercase English letters.
*/

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n=grid.size(), m=grid[0].size(), dirx[4]={-1,0,1,0}, diry[4]={0,1,0,-1}; 
        vector<vector<int>> visited(n,vector<int>(m,0)); 

        // check if the grid[x][y] is valid (i.e. in the bound)
        function<bool(int,int)> isValid = [&](int x, int y) {
            return (x<n&&x>=0&&y<m&&y>=0);
        };

        // check if it is cyclic
        function<bool(int,int,int,int)> dfs = [&](int x, int y, int fromX, int fromY) {
            // mark it visited
            visited[x][y]=1; 
            // check the next cells in four directions
            for(int k=0; k<4; k++) { 
                int toX=x+dirx[k], toY=y+diry[k]; 
                if (isValid(toX, toY)&&grid[toX][toY]==grid[x][y]&&!(fromX==toX&&fromY==toY)) { 
                    if (visited[toX][toY] || dfs(toX, toY, x, y)) return true; 
                } 
            } 
            return false; 
        };

        // dfs approach
        for(int i=0; i<n; i++) { 
            for(int j=0; j<m; j++) { 
                // if the current cell is not visited, 
                // then check if it is cyclic 
                if (!visited[i][j]&&dfs(i, j, -1, -1)){
                    return true;
                }
            } 
        } 
        return false;
    }
};