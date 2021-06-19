/*
Number of Subarrays with Bounded Maximum
https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/

We are given an array nums of positive integers, and two positive integers left and right (left <= right).

Return the number of (contiguous, non-empty) subarrays such that the value of the maximum array element in that subarray is at least left and at most right.

Example:
Input: 
nums = [2, 1, 4, 3]
left = 2
right = 3
Output: 3
Explanation: There are three subarrays that meet the requirements: [2], [2, 1], [3].
Note:

left, right, and nums[i] will be an integer in the range [0, 109].
The length of nums will be in the range of [1, 50000].
*/

class Solution {
public:
    int go(vector<int>& nums, int n) {
        int res = 0, cnt = 0;
        for(int x : nums) cnt = x <= n ? cnt + 1 : 0, res += cnt;
        return res;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return go(nums, right) - go(nums, left - 1);
    }
};