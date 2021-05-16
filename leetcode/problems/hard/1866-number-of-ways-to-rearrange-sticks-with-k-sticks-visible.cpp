/*
Number of Ways to Rearrange Sticks With K Sticks Visible
https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/

There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it.

For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left.
Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 109 + 7.

 

Example 1:

Input: n = 3, k = 2
Output: 3
Explanation: [1,3,2], [2,3,1], and [2,1,3] are the only arrangements such that exactly 2 sticks are visible.
The visible sticks are underlined.
Example 2:

Input: n = 5, k = 5
Output: 1
Explanation: [1,2,3,4,5] is the only arrangement such that all 5 sticks are visible.
The visible sticks are underlined.
Example 3:

Input: n = 20, k = 11
Output: 647427950
Explanation: There are 647427950 (mod 109 + 7) ways to rearrange the sticks such that exactly 11 sticks are visible.
 

Constraints:

1 <= n <= 1000
1 <= k <= n
*/

class Solution {
public:
    int dp[1005][1005];
    int rearrangeSticks(int n, int k, int M = 1000000007) {
        if (n == k) return 1;
        if (k == 0) return 0;
        if (dp[n][k] == 0) dp[n][k]  = (1L * rearrangeSticks(n - 1, k - 1) + 1L * rearrangeSticks(n - 1, k) * (n - 1)) % M;
        return dp[n][k];
    }
};

class Solution2 {
public:
    int dp[1005][1005];
    int rearrangeSticks(int n, int k) {
        int M = 1e9 + 7;
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                dp[i][j] = (dp[i - 1][j] * (i - 1) + dp[i - 1][j - 1]);
                dp[i][j] %= M;
            }
        }
        return dp[n][k];
    }
};