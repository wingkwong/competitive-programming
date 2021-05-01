/*
Maximum Average Subarray II
https://leetcode.com/problems/maximum-average-subarray-ii/

You are given an integer array nums consisting of n elements, and an integer k.

Find a contiguous subarray whose length is greater than or equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

 

Example 1:

Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation:
- When the length is 4, averages are [0.5, 12.75, 10.5] and the maximum average is 12.75
- When the length is 5, averages are [10.4, 10.8] and the maximum average is 10.8
- When the length is 6, averages are [9.16667] and the maximum average is 9.16667
The maximum average is when we choose a subarray of length 4 (i.e., the sub array [12, -5, -6, 50]) which has the max average 12.75, so we return 12.75
Note that we do not consider the subarrays of length < 4.
Example 2:

Input: nums = [5], k = 1
Output: 5.00000
 

Constraints:

n == nums.length
1 <= k <= n <= 104
-104 <= nums[i] <= 104
*/

class Solution {
public:
    bool is_larger(vector<int>& nums, int k, double m) {
        double cur_sum = 0;
        double pre_sum = 0;
        double min_sum = 0;
        // a0 + a1 + .. + aj / j >= m
        // a0 + a1 + .. + aj >= m * j
        // a0 - m + a1 - m + .. + aj - m >= 0
        for(int i = 0; i < k; i++) cur_sum += nums[i] - m;
        if(cur_sum >= 0) return true;
        for(int i = k; i < nums.size(); i++) {
            cur_sum += nums[i] - m;
            pre_sum += nums[i - k] - m;
            min_sum = min(min_sum, pre_sum);
            if(cur_sum - min_sum >= 0) return true;
        }
        return false;
    }
    
    double findMaxAverage(vector<int>& nums, int k) {
        double l = (double) nums[0];
        double r = (double) nums[0];
        for(auto x : nums) {
            l = min(l, (double) x);
            r = max(r, (double) x);
        }
        while(r - l > 1e-5) {
            double m = l + (r - l) / 2;
            if(is_larger(nums, k, m)) l = m;
            else r = m;
        }
        return l;
    }
};