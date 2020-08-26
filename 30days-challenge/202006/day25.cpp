/*
Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Tortoise and Hare (Cycle Detection)
        int fast,slow;
        fast=slow=nums[0];
        while(1){
            // phase 1
            // construct a sequence like x, nums[x], nums[nums[x]], nums[nums[nums[x]]], ...
            fast=nums[fast];
            slow=nums[nums[slow]];
            if(fast==slow) break;
        }
        slow=nums[0];
        while(fast!=slow){
            // phase 2
            // slow starts from entrance point
            // fast starts from intersection point
            fast=nums[fast];
            slow=nums[slow];
        }
        return slow;
    }
};