/*
Minimum Operations to Make a Subsequence
https://leetcode.com/problems/minimum-operations-to-make-a-subsequence/

You are given an array target that consists of distinct integers and another integer array arr that can have duplicates.

In one operation, you can insert any integer at any position in arr. For example, if arr = [1,4,1,2], you can add 3 in the middle and make it [1,4,3,1,2]. Note that you can insert the integer at the very beginning or end of the array.

Return the minimum number of operations needed to make target a subsequence of arr.

A subsequence of an array is a new array generated from the original array by deleting some elements (possibly none) without changing the remaining elements' relative order. For example, [2,7,4] is a subsequence of [4,2,3,7,2,1,4] (the underlined elements), while [2,4,2] is not.

 

Example 1:

Input: target = [5,1,3], arr = [9,4,2,3,4]
Output: 2
Explanation: You can add 5 and 1 in such a way that makes arr = [5,9,4,1,2,3,4], then target will be a subsequence of arr.
Example 2:

Input: target = [6,4,8,1,3,2], arr = [4,7,6,2,3,8,6,1]
Output: 3
 

Constraints:

1 <= target.length, arr.length <= 105
1 <= target[i], arr[i] <= 109
target contains no duplicates.
*/


class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        int n = target.size(), m = arr.size();
        unordered_map<int, int> mp;
        vector<int> v, lcs;
        for(int i = 0; i < n; i++) mp[target[i]] = i;
        for(int i = 0; i < m; i++) if(mp.count(arr[i])) v.push_back(mp[arr[i]]);
        // LIS - Longest Increasing Sequence in arr - skip those numbers not in target
        // e.g.
  		// target: 	[6,4,8,1,3,2]  		-> [0, 1, 2, 3, 4, 5]
		// arr: 	[4,7,6,2,3,8,6,1] 	-> [1, 0, 5, 4, 2, 0, 3]
        for(int x : v) {
            auto it = lower_bound(lcs.begin(), lcs.end(), x);
            if(it == lcs.end()) lcs.push_back(x);
            else *it = x;
        }
        return n - (int) lcs.size();
    }
    
    // LCS gives TLE
    // int minOperations(vector<int>& target, vector<int>& arr) {
    //     int n = target.size(), m = arr.size();
    //     // int dp[n + 1][m + 1];
    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    //     // memset(dp, 0, sizeof(dp));
    //     for(int i = 0; i < n + 1; i++) {
    //         for(int j = 0; j < m + 1; j++) {
    //             if(i == 0 || j == 0) dp[i][j] = 0;
    //             else if(target[i - 1] == arr[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
    //             else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    //     return n - dp[n][m];
    // }
};