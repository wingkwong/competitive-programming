/*
Minimum Adjacent Swaps for K Consecutive Ones
https://leetcode.com/problems/minimum-adjacent-swaps-for-k-consecutive-ones/

You are given an integer array, nums, and an integer k. nums comprises of only 0's and 1's. In one move, you can choose two adjacent indices and swap their values.

Return the minimum number of moves required so that nums has k consecutive 1's.

 

Example 1:

Input: nums = [1,0,0,1,0,1], k = 2
Output: 1
Explanation: In 1 move, nums could be [1,0,0,0,1,1] and have 2 consecutive 1's.
Example 2:

Input: nums = [1,0,0,0,0,0,1,1], k = 3
Output: 5
Explanation: In 5 moves, the leftmost 1 can be shifted right until nums = [0,0,0,0,0,1,1,1].
Example 3:

Input: nums = [1,1,0,1], k = 2
Output: 0
Explanation: nums already has 2 consecutive 1's.
 

Constraints:

1 <= nums.length <= 105
nums[i] is 0 or 1.
1 <= k <= sum(nums)
*/

class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        long long ans = INT_MAX;
        vector<int> one_idx;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) one_idx.push_back(i);
        }
        int n = one_idx.size();
        vector<long long> prefix_sum = {0};
        for(int i = 0; i < n; i++) {
            prefix_sum.push_back(prefix_sum.back() + one_idx[i]);
        }
        for(int i = k / 2; i < n - (k - 1) / 2; i++) {
            long long left = k / 2 * one_idx[i] - (prefix_sum[i] - prefix_sum[i - k / 2]) - k / 2 * (k / 2 + 1) / 2;
            long long right = prefix_sum[i + 1 + (k - 1) / 2] - prefix_sum[i + 1] - (k - 1) / 2 * one_idx[i] - (k - 1) / 2 * ((k - 1) / 2 + 1) / 2;
            ans = min(ans, left + right);
        }
        return ans;
    }
};