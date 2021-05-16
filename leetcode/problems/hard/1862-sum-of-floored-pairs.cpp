/*
Sum of Floored Pairs
https://leetcode.com/problems/sum-of-floored-pairs/

Given an integer array nums, return the sum of floor(nums[i] / nums[j]) for all pairs of indices 0 <= i, j < nums.length in the array. Since the answer may be too large, return it modulo 109 + 7.

The floor() function returns the integer part of the division.

 

Example 1:

Input: nums = [2,5,9]
Output: 10
Explanation:
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then sum them up.
Example 2:

Input: nums = [7,7,7,7,7,7,7]
Output: 49
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 105
*/

class Solution {
public:
    int cnt[300007] = {0}, prev[300007] = {0};
    int sumOfFlooredPairs(vector<int>& nums) {
        int M = 1e9 + 7, n = 300007, ans = 0;
        // unordered_map<int, int> cnt, prev;
        for(auto x : nums) cnt[x]++;
        for(int i = 1; i < n; i++) prev[i] = prev[i - 1] + cnt[i];
        for(int i = 1; i < n; i++) {
            for(int j = i; j < n; j += i) {
                if(i != j && cnt[i] > 0) {
                    ans += cnt[i] * (prev[j - 1] - prev[j - i - 1]) * (j / i - 1);
                    ans %= M;
                }
            }
        }
        return ans;
    }
};