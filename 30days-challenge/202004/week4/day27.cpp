/*
Maximal Square

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row=(int)matrix.size(); if(row==0) return 0;
        int col=(int)matrix[0].size();
        int dp[row+1][col+1];
        int m=0;
        memset(dp,0,sizeof(int)*(row+1)*(col+1));
        for(int i=1;i<=row;i++){
            for(int j=1;j<=col;j++){
                if(matrix[i-1][j-1]=='1') {
                    // the number of the bottom right of the square is greater than the others
                    dp[i][j] = min({
                        dp[i-1][j], // top
                        dp[i-1][j-1], // top left
                        dp[i][j-1] // left
                    }) + 1;
                    // take the max width/height
                    m=max(m,dp[i][j]);
                }
            }
        }
        // area = width*height
        return m*m;
    }
};
static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();