/*
Climbing Stairs

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
*/

class Solution {
public:
    int climbStairs(int n) {
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

class Solution2 {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        vector<int> dp(n+1,0);
        dp[1]=1; // take 1 step
        dp[2]=2; // either take 1 step + 1 step or take 2 steps
        for(int i=3;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

class Solution3 {
public:
    int climbStairs(int n) {
        vector<int> memo(n+1,0);
        return h(memo,n,0);
    }
private:
    int h(vector<int> &memo, int n, int k){
        if(k>n) return 0;
        if(k==n) return 1;
        if(memo[k]) return memo[k];
        memo[k] = h(memo,n,k+1) + h(memo,n,k+2);
        return memo[k];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();