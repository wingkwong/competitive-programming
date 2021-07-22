/*
Partition Array into Disjoint Intervals
https://leetcode.com/problems/partition-array-into-disjoint-intervals/

Given an array nums, partition it into two (contiguous) subarrays left and right so that:

Every element in left is less than or equal to every element in right.
left and right are non-empty.
left has the smallest possible size.
Return the length of left after such a partitioning.  It is guaranteed that such a partitioning exists.

Example 1:

Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
Example 2:

Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
 

Note:

2 <= nums.length <= 30000
0 <= nums[i] <= 106
It is guaranteed there is at least one way to partition nums as described.
*/

class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int ans = 0, pre_mx = nums[0], cur_mx = pre_mx;
        for(int i = 1; i < nums.size(); i++) {
            cur_mx = max(cur_mx, nums[i]);
            if(nums[i] < pre_mx) {
                pre_mx = cur_mx;
                ans = i;
            }
        }
        return ans + 1;
    }
};
