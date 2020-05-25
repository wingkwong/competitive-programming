/*
Making A Large Island

In a 2D grid of 0s and 1s, we change at most one 0 to a 1.

After, what is the size of the largest island? (An island is a 4-directionally connected group of 1s).

Example 1:

Input: [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
Example 2:

Input: [[1, 1], [1, 0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.
Example 3:

Input: [[1, 1], [1, 1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.
 

Notes:

1 <= grid.length = grid[0].length <= 50.
0 <= grid[i][j] <= 1.
*/

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0) {
                    // flip the 0 to other color, lets say 2 (bc 0 and 1 are used)
                    // Example: [[1, 0], [0, 1]]
                    // 10  -->  20
                    // 01  -->  02  
                    // then it will return 3 (the current flip + 2 1s)
                    ans=max(ans,dfs(grid,i,j,2,true));
                    // since we've updated all 1s, so we need to update them back
                    // 20  --> 10
                    // 02  --> 01
                    dfs(grid,i,j,1,true);
                }
            }
        }
        // if no flips, the ans would be row*col
        return ans==0?grid.size()*grid[0].size():ans;
    }
private:
    int ans=0;
    int dfs(vector<vector<int>>& grid,int i,int j, int c, bool f=false){
        // dfs approach
        if(!f&&(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1||grid[i][j]==c||grid[i][j]==0)) return 0;
        // set the color for non-zero element
        grid[i][j]=grid[i][j]==0?0:c;
        // dfs for 4 directions
        return 1 + dfs(grid,i+1,j,c)+
                   dfs(grid,i,j+1,c)+
                   dfs(grid,i,j-1,c)+
                   dfs(grid,i-1,j,c);
    }
};

