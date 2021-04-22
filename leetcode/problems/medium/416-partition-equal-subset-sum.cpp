/*
Partition Equal Subset Sum
https://leetcode.com/problems/partition-equal-subset-sum/

Given a non-empty array nums containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) sum += x;
        if(sum & 1) return false;
        sum /= 2;
        int n = nums.size();
        // dp[i][j] : can make sum j using the first i numbers (0 .. i)
        vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, 0));
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; i++) dp[i][0] = 1;
        // for(int j = 1; j < sum + 1; j++) dp[0][j] = 0;
        for(int i = 1; i < n + 1; i++) {
            for(int j = 1; j < sum + 1; j++) {
                // don't take it
                dp[i][j] = dp[i - 1][j];
                // take it 
                if(j >= nums[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[n][sum];
    }
};