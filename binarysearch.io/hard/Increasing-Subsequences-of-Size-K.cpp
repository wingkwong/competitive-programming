#include "solution.hpp"
using namespace std;


class Solution {
    public:
    int solve(vector<int>& nums, int k) {
        int n=(int)nums.size(), dp[k][n], ans=0, mod=1e9+7; 
        memset(dp, 0, sizeof(dp)); 
        for (int i=0; i<n; i++) dp[0][i]=1; 
        for (int l=1; l<k; l++) { 
            for (int i=l;i<n;i++) { 
                dp[l][i]=0; 
                for (int j=l-1;j<i;j++) { 
                    if (nums[j]<nums[i]) {
                        dp[l][i]=(dp[l][i]+dp[l-1][j])%mod; 
                    }
                } 
            } 
        } 
        for (int i=k-1;i<n;i++) {
            ans=(ans+dp[k-1][i])%mod; 
        }
        return ans; 
    }
};
