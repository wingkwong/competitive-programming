/*
Shortest Unsorted Continuous Subarray
https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

Return the shortest such subarray and output its length.

 

Example 1:

Input: nums = [2,6,4,8,10,9,15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Example 2:

Input: nums = [1,2,3,4]
Output: 0
Example 3:

Input: nums = [1]
Output: 0
 

Constraints:

1 <= nums.length <= 104
-105 <= nums[i] <= 105
 

Follow up: Can you solve it in O(n) time complexity?
*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> nums2 = nums;
        sort(nums.begin(), nums.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == nums2[i]) i++;
        while (j > i && nums[j] == nums2[j]) j--;
        return j - i + 1;
    }
};