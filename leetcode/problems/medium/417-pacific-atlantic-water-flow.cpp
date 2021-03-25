/*
Pacific Atlantic Water Flow
https://leetcode.com/problems/pacific-atlantic-water-flow/

Pacific Atlantic Water Flow
Medium

1858

449

Add to List

Share
Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:

The order of returned grid coordinates does not matter.
Both m and n are less than 150.
 

Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).
*/

class Solution {
public:
    void dfs(vector<vector<int>>& M, vector<vector<int>>& vis, int i, int j) {
        int m = M.size(), n = M[0].size();
        vis[i][j] = 1;
        if(i - 1 >= 0 && !vis[i - 1][j] && M[i - 1][j] >= M[i][j]) dfs(M, vis, i - 1, j);
        if(i + 1 < m && !vis[i + 1][j] && M[i + 1][j] >= M[i][j]) dfs(M, vis, i + 1, j);
        if(j - 1 >= 0 && !vis[i][j - 1] && M[i][j - 1] >= M[i][j]) dfs(M, vis, i, j - 1);
        if(j + 1 < n && !vis[i][j + 1] && M[i][j + 1] >= M[i][j]) dfs(M, vis, i, j + 1);
    }
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& M) {
        vector<vector<int>> ans;
        int m = M.size();
        if(m == 0) return ans;
        int n = M[0].size();
        if(n == 0) return ans;
        vector<vector<int>> P(m, vector<int>(n)); // pacific
        vector<vector<int>> A(m, vector<int>(n)); // atlantic
        for(int i = 0; i < m; i++) {
            dfs(M, P, i, 0);
            dfs(M, A, i, n - 1);
        }
        for(int i = 0; i < n; i++) {
            dfs(M, P, 0, i);
            dfs(M, A, m - 1, i);
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(P[i][j] && A[i][j]) {
                    ans.push_back(vector<int>{i, j});
                }
            }
        }
        return ans;
    }
};