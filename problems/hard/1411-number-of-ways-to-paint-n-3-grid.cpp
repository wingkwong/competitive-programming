/*
Number of Ways to Paint N × 3 Grid

You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colours: Red, Yellow or Green while making sure that no two adjacent cells have the same colour (i.e no two cells that share vertical or horizontal sides have the same colour).

You are given n the number of rows of the grid.

Return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 10^9 + 7.

Example 1:

Input: n = 1
Output: 12
Explanation: There are 12 possible way to paint the grid as shown:

Example 2:

Input: n = 2
Output: 54
Example 3:

Input: n = 3
Output: 246
Example 4:

Input: n = 7
Output: 106494
Example 5:

Input: n = 5000
Output: 30228214
 

Constraints:

n == grid.length
grid[i].length == 3
1 <= n <= 5000
*/

class Solution {
public:
    int numOfWays(int n) {
        return dfs(n,0,0,0);
    }
private:
    int dp[5001][4][4][4]={};
    int mod=1E9+7;
    vector<int> colors = {1,2,3}; // r,y,g
    
    int dfs(int n, int r, int y, int g){
        if(n==0) return 1;
        if(dp[n][r][y][g]!=0) return dp[n][r][y][g];
        int ans=0;
        for(int rr: colors){
            if(rr==r) continue; // same color as below neighbor
            for(int yy: colors){
                if(yy==y||yy==rr) continue; // same color as below neighbor or same as left neighbor
                for(int gg: colors){
                    if(gg==g||gg==yy) continue; // same color as below neighbor or same as left neighbor
                    ans += dfs(n-1,rr,yy,gg);
                    ans %= mod;
                }
            } 
        }
        return dp[n][r][y][g] = ans;
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();