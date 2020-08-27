#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(int n) {
        if(!n) return 1;
        int dp[n+1];
        memset(dp,0,sizeof(int)*(n+1));
        dp[0]=1;
        dp[1]=1;
        // targets: no of stairs
        for(int i=2;i<=n;i++){
            // ways: no of steps
            for(int j=1;j<=2;j++){
                dp[i] += dp[i-j];
            }
        }
        return dp[n];
    }
};
