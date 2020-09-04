/*
House Robber II

ou are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Example 1:

Input: [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
             because they are adjacent houses.
Example 2:

Input: [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
             Total amount you can rob = 1 + 3 = 4.
*/

class Solution {
public:
    int rob(vector<int>& nums, int left, int right) {
        int cur=0, prev=0;
        for(int i=left;i<=right;i++){
            int tmp = max(prev+nums[i], cur);
            prev=cur;
            cur=tmp;
        }
        return cur;
    }
    int rob(vector<int>& nums) {
        // As we cannot sum the first element and the last element, this comes with two cases.

        // Sum from index 0 to n-2
        // Sum from index 1 to n-1
        // where n is the size of nums.

        // The answer is the max of them. Use prev and cur to optimise space.
        int n = nums.size();
        if(n<2) return n?nums[0]:0;
        return max(rob(nums,0,n-2), rob(nums,1,n-1));
    }
};