#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(string a, string b) {
        int m=a.size(), n=b.size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++) dp[i][0]=i;
        for(int j=1;j<=n;j++) dp[0][j]=j;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }else{
                    dp[i][j] = 1 + min({
                        dp[i-1][j-1],
                        dp[i][j-1],
                        dp[i-1][j]
                    });
                }
            }
        }
        return dp[m][n];
    }
};
