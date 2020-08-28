#include "solution.hpp"
using namespace std;


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
    
    int solve(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
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
