/*
Ugly Number II

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.
*/

class Solution {
public:
    int nthUglyNumber(int n) {
        // base cases
        if(n<=0) return 0;
        if(n==1) return 1;
        int dp[n],p2=0,p3=0,p5=0;
        dp[0]=1;
        for(int i=1;i<n;i++){
            // The key is how to maintain the order of the ugly numbers. 
            // Try a similar approach of merging from three sorted lists: L1, L2, and L3.
            // Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
            dp[i] = min({dp[p2]*2,dp[p3]*3,dp[p5]*5});
            if(dp[i]==dp[p2]*2) p2++;
            if(dp[i]==dp[p3]*3) p3++;
            if(dp[i]==dp[p5]*5) p5++;
             
        }
        return dp[n-1];
    }
};

static const auto io_sync_off = []() {std::ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();