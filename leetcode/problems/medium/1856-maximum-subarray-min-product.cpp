/*
Maximum Subarray Min-Product
https://leetcode.com/problems/maximum-subarray-min-product/

The min-product of an array is equal to the minimum value in the array multiplied by the array's sum.

For example, the array [3,2,5] (minimum value is 2) has a min-product of 2 * (3+2+5) = 2 * 10 = 20.
Given an array of integers nums, return the maximum min-product of any non-empty subarray of nums. Since the answer may be large, return it modulo 109 + 7.

Note that the min-product should be maximized before performing the modulo operation. Testcases are generated such that the maximum min-product without modulo will fit in a 64-bit signed integer.

A subarray is a contiguous part of an array.

 

Example 1:

Input: nums = [1,2,3,2]
Output: 14
Explanation: The maximum min-product is achieved with the subarray [2,3,2] (minimum value is 2).
2 * (2+3+2) = 2 * 7 = 14.
Example 2:

Input: nums = [2,3,3,1,2]
Output: 18
Explanation: The maximum min-product is achieved with the subarray [3,3] (minimum value is 3).
3 * (3+3) = 3 * 6 = 18.
Example 3:

Input: nums = [3,1,5,6,4,2]
Output: 60
Explanation: The maximum min-product is achieved with the subarray [5,6,4] (minimum value is 4).
4 * (5+6+4) = 4 * 15 = 60.
 

Constraints:

1 <= nums.length <= 105
1 <= nums[i] <= 107
*/

class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int M = 1e9 + 7, n = nums.size();
        vector<int> l(n), r(n);
        vector<long> sum(n + 1);
        for(int i = 0; i < n; i++) {
          int j = i;
          while(j && nums[j - 1] >= nums[i]) j = l[j - 1];
          l[i] = j, sum[i + 1] = sum[i] + nums[i];
        }
        long ans = 0;
        for(int i = n - 1; i >= 0; i--) {
          int j = i;
          while(j + 1 < n && nums[i] <= nums[j + 1]) j = r[j + 1];
          r[i] = j;
          long k = (long)(sum[j + 1] - sum[l[i]]) * nums[i];
          ans = max(ans, k);
        }
        return ans % M;
    }
};