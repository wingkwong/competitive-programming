/*
Longest Increasing Path in a Matrix

Given an integer matrix, find the length of the longest increasing path.

From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).

Example 1:

Input: nums = 
[
  [9,9,4],
  [6,6,8],
  [2,1,1]
] 
Output: 4 
Explanation: The longest increasing path is [1, 2, 6, 9].
Example 2:

Input: nums = 
[
  [3,4,5],
  [3,2,6],
  [2,2,1]
] 
Output: 4 
Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
*/

class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    
    int dfs(vector<vector<int>>& matrix, int i, int j){
        if(dp[i][j]) return dp[i][j];
        int v = 1;
        if (i+1<m&&matrix[i+1][j]>matrix[i][j]) v=max(v,1+dfs(matrix,i+1,j));
        if (i-1>=0&&matrix[i-1][j]>matrix[i][j]) v=max(v,1+dfs(matrix,i-1,j));
        if (j+1<n&&matrix[i][j+1]>matrix[i][j]) v=max(v,1+dfs(matrix,i,j+1));
        if (j-1>=0&&matrix[i][j-1]>matrix[i][j]) v=max(v,1+dfs(matrix,i,j-1));
        dp[i][j] = v;
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        // dp[i][j] means the length of longest increasing path starting from (i,j). 
        // Traverse four directions iff the next cell is in the bound and the value is greater than the current one. 
        // Calculate it recursively and store it back to dp[i][j]. 
        // If dp[i][j] has been calculated, return the cached result directly.
        m = matrix.size();
        if(m==0) return 0;
        n = matrix[0].size();
        dp = vector<vector<int>>(m, vector<int>(n, 0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans, dfs(matrix,i,j));
            }
        }
        return ans;
    }
};