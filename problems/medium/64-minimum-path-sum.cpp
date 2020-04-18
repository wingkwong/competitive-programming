/*
Minimum Path Sum

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> cur(m,grid[0][0]);
        for (int i=1;i<m;i++) cur[i]=cur[i-1]+grid[i][0]; 
        for (int j=1; j<n;j++) {
            cur[0]+=grid[0][j]; 
            for (int i=1; i<m; i++)
                cur[i] = min(cur[i-1],cur[i])+grid[i][j];
        }
        return cur[m-1];
    }
};

class Solution2 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0) return 0;
        int m=grid.size();
        int n=grid[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp[0][0])*m*n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i][j]+=grid[i][j];
                if(i>0&&j>0) {
                    dp[i][j]+=min(dp[i-1][j], dp[i][j-1]);
                } else if(i>0){
                    dp[i][j]+=dp[i-1][j]; // take from the top
                } else if(j>0){
                    dp[i][j]+=dp[i][j-1]; // take from the left
                }
            }
        }
        return dp[m-1][n-1];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();